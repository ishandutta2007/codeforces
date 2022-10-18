#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int inf = 5e18, mod = 1e9 + 7, maxk = 11, maxn = 2e5;

int dp[maxn][maxk][3];
vector<int> g[maxn];
int m, k;

void dfs(int v = 0, int p = 0)
{
    dp[v][0][0] = k - 1;
    dp[v][1][1] = 1;
    dp[v][0][2] = m - k;
    for(auto u: g[v])
    {
        if(u == p)
            continue;
        dfs(u, v);
        int ndp[maxk][3];
        memset(ndp, 0, sizeof(int) * maxk * 3);
        for(int j = 0; j < maxk; j++)
        {
            for(int k = 0; k <= j; k++)
            {
                ndp[j][0] += dp[v][j - k][0] * (dp[u][k][0] + dp[u][k][1] + dp[u][k][2]);
                ndp[j][1] += dp[v][j - k][1] * dp[u][k][0];
                ndp[j][2] += dp[v][j - k][2] * (dp[u][k][0] + dp[u][k][2]);
                ndp[j][0] %= mod;
                ndp[j][1] %= mod;
                ndp[j][2] %= mod;
            }
        }
        memcpy(dp[v], ndp, sizeof(int) * maxk * 3);
    }
    
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    int x;
    cin >> k >> x;
    int ans = 0;
    dfs();
    for(int i = 0; i <= x; i++)
    {
        ans += dp[0][i][0] + dp[0][i][1] + dp[0][i][2];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}