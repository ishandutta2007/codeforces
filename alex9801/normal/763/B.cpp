#include <stdio.h>
#include <string.h>
#include <algorithm>

int main()
{
    printf("YES\n");

    int n, x1, y1, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%*d%*d", &x1, &y1);
        x1 = (x1 % 2 + 2) % 2;
        y1 = (y1 % 2 + 2) % 2;
        printf("%d\n", x1 * 2 + y1 + 1);
    }
    return 0;
}