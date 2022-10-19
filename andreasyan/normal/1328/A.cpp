#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int u = (a / b) * b;
        if (u < a)
            u += b;
        printf("%d\n", u - a);
    }
    return 0;
}