#include <bits/stdc++.h>
using namespace std;
const int N = 100020, P = 7;
const long long INF = 1000000009000000009;
struct ban
{
    int i, x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n, p, k;
ban a[N];
int b[N][P];

int q[(1 << P)];

long long dp[N][(1 << P)];

int main()
{
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d", &a[i].x);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            scanf("%d", &b[i][j]);
        }
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int x = 0; x < (1 << p); ++x)
    {
        for (int i = 0; i < p; ++i)
        {
            if ((x & (1 << i)))
                ++q[x];
        }
    }
    for (int x = 1; x < (1 << p); ++x)
        dp[0][x] = -INF;
    for (int i = 1; i <= k; ++i)
        dp[0][0] += a[i].x;
    for (int i = 1; i <= n; ++i)
    {
        for (int x = 0; x < (1 << p); ++x)
        {
            dp[i][x] = max(dp[i][x], dp[i - 1][x]);
            for (int j = 0; j < p; ++j)
            {
                if ((x & (1 << j)))
                    continue;
                if (i <= k + q[x])
                    dp[i][(x | (1 << j))] = max(dp[i][(x | (1 << j))], dp[i - 1][x] + b[a[i].i][j] - a[i].x + a[k + q[x] + 1].x);
                else
                    dp[i][(x | (1 << j))] = max(dp[i][(x | (1 << j))], dp[i - 1][x] + b[a[i].i][j]);
            }
        }
    }
    printf("%lld\n", dp[n][(1 << p) - 1]);
    return 0;
}