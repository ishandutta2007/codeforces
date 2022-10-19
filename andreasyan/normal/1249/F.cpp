#include <bits/stdc++.h>
using namespace std;
const int N = 202;

int n, k;
int b[N];
vector<int> a[N];

int dp[N][N];
int ndp[N];
void dfs(int x, int p)
{
    dp[x][0] = b[x];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        memset(ndp, 0, sizeof ndp);
        for (int h1 = 0; h1 <= n; ++h1)
        {
            for (int h2 = 0; h2 <= n; ++h2)
            {
                if (h1 + h2 + 1 <= k)
                    continue;
                ndp[min(h1, h2 + 1)] = max(ndp[min(h1, h2 + 1)], dp[x][h1] + dp[h][h2]);
            }
        }
        memcpy(dp[x], ndp, sizeof ndp);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    int ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = max(ans, dp[1][i]);
    printf("%d\n", ans);
    return 0;
}