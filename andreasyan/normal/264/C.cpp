#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;
const long long INF = 1000000009000000009;

int n, qq;
int v[N], g[N];

long long a, b;

long long maxu[N];
long long dp[N];

int main()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &g[i]);
    while (qq--)
    {
        scanf("%lld%lld", &a, &b);
        for (int i = 1; i <= n; ++i)
            maxu[i] = -INF;
        long long max1 = 0, max2 = 0;
        int max1i = 0, max2i = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = maxu[g[i]] + v[i] * a;
            if (maxu[g[i]] == max1)
                dp[i] = max(dp[i], max2 + v[i] * b);
            else
                dp[i] = max(dp[i], max1 + v[i] * b);
            maxu[g[i]] = max(maxu[g[i]], dp[i]);
            if (g[i] == max1i)
            {
                max1 = maxu[g[i]];
            }
            else if (g[i] == max2i)
            {
                max2 = maxu[g[i]];
                if (max2 > max1)
                {
                    swap(max2, max1);
                    swap(max1i, max2i);
                }
            }
            else
            {
                if (maxu[g[i]] >= max1)
                {
                    max2i = max1i;
                    max2 = max1;
                    max1i = g[i];
                    max1 = maxu[g[i]];
                }
                else if (maxu[g[i]] >= max2)
                {
                    max2i = g[i];
                    max2 = maxu[g[i]];
                }
            }
        }
        printf("%lld\n", max1);
    }
    return 0;
}