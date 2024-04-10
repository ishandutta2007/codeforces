#include <bits/stdc++.h>
using namespace std;

void solv()
{
    long long x;
    scanf("%lld", &x);
    long long ans = 0;
    while (1)
    {
        if (x < 10)
        {
            ans += x;
            break;
        }
        ans += (x / 10) * 10;
        x = x - (x / 10) * 10 + (x / 10);
    }
    printf("%lld\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}