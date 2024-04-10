#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    if (n&1)
    {
        printf("7");
        n -= 3;
    }
    while(n)
    {
        printf("1");
        n -= 2;
    }
    return 0;
}