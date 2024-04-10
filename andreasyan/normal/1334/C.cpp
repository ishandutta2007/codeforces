#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 300005;
const long long INF = 1000000009000000009;

int n;
long long a[N], b[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%I64d%I64d", &a[i], &b[i]);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        a[i] -= (b[(i - 1 + n) % n]);
        if (a[i] > 0)
            ans += a[i];
    }
    long long yans = INF;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > 0)
            ans -= a[i];
        a[i] += (b[(i - 1 + n) % n]);
        yans = min(yans, ans + a[i]);
        a[i] -= (b[(i - 1 + n) % n]);
        if (a[i] > 0)
            ans += a[i];
    }
    printf("%I64d\n", yans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}