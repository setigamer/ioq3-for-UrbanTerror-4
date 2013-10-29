/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */
/******************************************************************************
    event_status_driver.h
    API for the events status driver.
    This file contains public API.
    mpaque 11Oct91

    Copyright 1991 NeXT Computer, Inc.

    Modified:

******************************************************************************/

#ifndef _DRIVERS_EVENT_STATUS_DRIVER_
#define _DRIVERS_EVENT_STATUS_DRIVER_

__BEGIN_DECLS

#include <mach/port.h>
#include <IOKit/hidsystem/IOLLEvent.h>
#include <IOKit/hidsystem/IOHIDTypes.h>
#include <AvailabilityMacros.h>

/*
 * Event System Handle:
 *
 * Information used by the system between calls to NXOpenEventSystem and
 * NXCloseEventSystem.  The application should not
 * access any of the elements of this structure.
 */
typedef mach_port_t NXEventHandle;

/* Open and Close */
NXEventHandle NXOpenEventStatus(void);
void NXCloseEventStatus(NXEventHandle handle);

/* Status */
extern NXEventSystemInfoType NXEventSystemInfo(NXEventHandle handle,
                char *flavor,
                int *evs_info,
                unsigned int *evs_info_cnt);
/* Keyboard */
extern void NXSetKeyRepeatInterval(NXEventHandle handle, double seconds);
extern double NXKeyRepeatInterval(NXEventHandle handle);
extern void NXSetKeyRepeatThreshold(NXEventHandle handle, double threshold);
extern double NXKeyRepeatThreshold(NXEventHandle handle);
extern void NXResetKeyboard(NXEventHandle handle);

/* Mouse */
extern void NXSetClickTime(NXEventHandle handle, double seconds);
extern double NXClickTime(NXEventHandle handle);
extern void NXSetClickSpace(NXEventHandle handle, _NXSize_ *area);
extern void NXGetClickSpace(NXEventHandle handle, _NXSize_ *area);
extern void NXResetMouse(NXEventHandle handle);

/*
* The following functions have been removed.
*
* NXIdleTime
*     See CGEventSourceSecondsSinceLastEventType.
*
* NXSetKeyMapping
* NXKeyMappingLength
* NXGetKeyMapping
*     These do not have a drop in replacement.  See UCKeyTranslate.
*
* NXSetMouseScaling
*     See IOHIDSetAccelerationWithKey and IOHIDSetMouseAcceleration.
*
* NXGetMouseScaling
*     See IOHIDGetAccelerationWithKey and IOHIDGetMouseAcceleration.
*
* NXSetAutoDimThreshold
* NXSetAutoDimState
*     See IOPMSetAggressiveness and kPMMinutesToDim.
*
* NXAutoDimThreshold
* NXAutoDimTime
* NXAutoDimState
*     See IOPMGetAggressiveness and kPMMinutesToDim.
*
* NXSetAutoDimBrightness
* NXAutoDimBrightness
* NXSetScreenBrightness
* NXScreenBrightness
*     This functionality is unsupported.
*/

__END_DECLS

#endif /*_DRIVERS_EVENT_STATUS_DRIVER_ */

