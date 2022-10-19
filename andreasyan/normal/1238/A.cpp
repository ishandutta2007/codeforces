#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        x -= y;
        if (x == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}