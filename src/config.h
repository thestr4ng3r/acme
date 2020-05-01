// ACME - a crossassembler for producing 6502/65c02/65816/65ce02 code.
// Copyright (C) 1998-2020 Marco Baye
// Have a look at "acme.c" for further info
//
// Configuration
#ifndef config_H
#define config_H


// make sure the enum below works with strange compilers, too:
#ifdef FALSE
#undef FALSE
#endif
#ifdef TRUE
#undef TRUE
#endif
// types
typedef enum { FALSE = 0, TRUE }	boolean;	// yes, I could include <stdbool.h>, but this source should work with ancient compilers as well...
typedef unsigned int	scope_t;
typedef signed long	intval_t;	// at least 32 bits
typedef unsigned long	uintval_t;	// just for logical shift right
// result structure type definition with support for floating point
struct number {	// either int or float
	int	flags;	// result flags (see alu.h, one if these tells ints and floats apart)
	union {
		intval_t	intval;	// integer value
		double		fpval;	// floating point value
	} val;	// Expression value
	int	addr_refs;	// address reference count (only look at this if value is DEFINED)
};


// debugging flag, should be undefined in release version
// #define FDEBUG

// maximum nesting depth of "!src" and macro calls
// is not actually a limitation, but a means of finding recursions
#define MAX_NESTING	64
// default value for output buffer
#define FILLVALUE_INITIAL	0
// default value for "!fill"
#define FILLVALUE_FILL		0

// Nullpointer definition
#ifndef NULL
#define NULL	((void *) 0)
#endif


#endif
