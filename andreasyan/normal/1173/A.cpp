#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    char ans1, ans2;
    if (x + z > y)
        ans1 = '+';
    else if (x + z == y)
        ans1 = '0';
    else
        ans1 = '-';
    if (y + z > x)
        ans2 = '-';
    else if (y + z == x)
        ans2 = '0';
    else
        ans2 = '+';
    if (ans1 == ans2)
        printf("%c\n", ans1);
    else
        printf("?\n");
    return 0;
}