#include <bits/stdc++.h>
using namespace std;

int a, b;

void solv()
{
    scanf("%d%d", &a, &b);
    long long ans = 0;
    for (int bb = 9, q = 1; bb <= b; bb = (bb * 10) + 9, ++q)
    {
        ans += a;
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