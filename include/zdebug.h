#ifndef __ZYY_DEBUG__
#define __ZYY_DEBUG__

#include <stdio.h>
#include <errno.h>

extern bool DEBUG_ALL;

extern bool DebugPushOnlyOnce;

extern bool DebugRASHit;

extern bool DebugPushPop;

extern bool DebugROP;

#define dprintf(debug_flags, fmt, ...) \
    do { \
        if (DEBUG_ALL && (debug_flags) ) { \
            fprintf(stderr, fmt "[%s:%d %s]\n", ##__VA_ARGS__, __FILE__, \
                    __LINE__, __FUNCTION__); \
        }\
    } while (false)

#define dprintfr(debug_flags, fmt, ...) \
    do { \
        if (DEBUG_ALL && (debug_flags) ) { \
            fprintf(stderr, fmt, ##__VA_ARGS__); \
        }\
    } while (false)

#define dvar_dec(debug_flags, var ) \
    do { \
        if (DEBUG_ALL && (debug_flags) ) { \
            fprintf(stderr, #var " = %llu\n", (unsigned long long) var); \
        }\
    } while (false)

#define dvar_hex(debug_flags, var ) \
    do { \
        if (DEBUG_ALL && (debug_flags) ) { \
            fprintf(stderr, #var " = 0x%llx\n", (unsigned long long) var); \
        }\
    } while (false)

#endif //__ZYY_DEBUG__
