#include <bits/stdc++.h>
using namespace std;

long long x;

bool solv()
{
    scanf("%lld", &x);
    for (int u = 1; u <= 6; ++u)
    {
        if ((x - u) > 0 && (x - u) % 14 == 0)
            return true;
    }
    return false;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}