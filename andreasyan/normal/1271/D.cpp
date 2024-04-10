#include <bits/stdc++.h>
using namespace std;
const int N = 5003, INF = 1000000009;

int n, m, k;
int kk;
int a[N], b[N], c[N];
int maxu[N];

vector<int> v[N];

int dp[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    kk = k;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for (int i = 1; i <= n; ++i)
        maxu[i] = i;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        maxu[y] = max(maxu[y], x);
    }
    for (int i = 1; i <= n; ++i)
        v[maxu[i]].push_back(c[i]);
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            dp[i][j] = -INF;
        }
    }
    dp[0][k] = 0;
    for (int i = 0; i <= n; ++i)
    {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        for (int j = 0; j < N; ++j)
        {
            if (dp[i][j] < 0)
                continue;
            int p = 0;
            for (int k = 0; k < v[i].size(); ++k)
            {
                p += v[i][k];
                if (j - (k + 1) >= 0)
                    dp[i][j - (k + 1)] = max(dp[i][j - (k + 1)], dp[i][j] + p);
            }
        }
        if (i != n)
        {
            for (int j = 0; j < N; ++j)
            {
                if (dp[i][j] < 0)
                    continue;
                if (j >= a[i + 1])
                {
                    dp[i + 1][j + b[i + 1]] = max(dp[i + 1][j + b[i + 1]], dp[i][j]);
                }
            }
        }
    }
    int ans = -INF;
    for (int j = 0; j < N; ++j)
        ans = max(ans, dp[n][j]);
    if (ans < 0)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}