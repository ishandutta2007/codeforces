#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000009000000009;

long long a[3];

long long ans;

void rec(int i)
{
    if (i == 3)
    {
        ans = min(ans, abs(a[0] - a[1]) + abs(a[1] - a[2]) + abs(a[2] - a[0]));
        return;
    }
    rec(i + 1);
    ++a[i];
    rec(i + 1);
    --a[i];
    --a[i];
    rec(i + 1);
    ++a[i];
}

void solv()
{
    for (int i = 0; i < 3; ++i)
        scanf("%lld", &a[i]);
    ans = INF;
    rec(0);
    printf("%lld\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}