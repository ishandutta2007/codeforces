#include <bits/stdc++.h>
using namespace std;
const int N = 33;
const long long INF = 1000000009000000009;

int n;
long long m;

long long a[N];

int main()
{
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i)
        a[i + 1] = min(a[i + 1], a[i] * 2);
    long long ans = INF;
    long long yans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        while ((m - (1 << i)) > 0)
        {
            m -= (1 << i);
            yans += a[i];
        }
        ans = min(ans, yans + a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}