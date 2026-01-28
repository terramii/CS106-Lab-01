#include <stdio.h>

/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x)
{
    //return ((x | 0x00007888) >> 16 == 0) && ((x | 0xFFFF8000) >> 16 == ~0);
    return !((x >> 15) ^ (x >> 16));
}

int test_fitsShort(int x)
{

    short int sx = (short int) x;
    return x == sx;
}

int main(void)
{
    int x = 0xFFFF8888;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
}
