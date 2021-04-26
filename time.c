/***************************************************************************
* Name of the file	             : time.c
* Brief Description of file      : Source file for time.c
* Name of Author    	           : Yatharth Agarwal
* Email ID                       : yatharthrpi@gmail.com


This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************************************************/
/**
@file time.c
@brief Source file for time.c
@detail the source file for an accurate delay function that measures time in upto milli seconds
*/




#include "platform.h"
#include "clint_driver.h"

#define CLINT_DIVISOR 16



/** @fn  millis(unsigned int sec)
 * @brief Function to give a delay in milli seconds
 * @details This function will halt the programm for the defined milli seconds
 * @param unsigned int sec - specifies the delay in milli seconds
 */

void millis(unsigned int sec)
{
   if (sec == 0)
  {
    return;
  } 
  
    uint64_t start = get_timer_value();
    sec = sec*((CLOCK_FREQUENCY/1000)/CLINT_DIVISOR );
  
    while(get_timer_value() - start <= sec ){}
 
    return;
}
