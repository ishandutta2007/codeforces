#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int inf = 1e16;

const int maxn = 5555;
vector<int> g[maxn], dp[maxn][2];
int p[maxn], c[maxn], d[maxn];
int sz[maxn];

void dfs(int v = 0)
{
    sz[v] = 1;
    for(auto u: g[v])
    {
        dfs(u);
        sz[v] += sz[u];
    }
    dp[v][0].assign(2, inf);
    dp[v][1].assign(2, inf);
    dp[v][0][0] = 0;
    dp[v][0][1] = c[v];
    dp[v][1][1] = c[v] - d[v];
    for(auto u: g[v])
    {
        vector<int> ndp[2];
        int t = dp[v][0].size();
        dp[v][0].resize(dp[v][0].size() + sz[u]);
        dp[v][1].resize(dp[v][1].size() + sz[u]);
        for(int i = t; i < dp[v][0].size(); i++)
            dp[v][0][i] = dp[v][1][i] = inf;
        ndp[0] = dp[v][0];
        ndp[1] = dp[v][1];
        for(int i = 0; i < ndp[0].size(); i++)
            for(int j = max(0LL, i - t); j <= min(i, sz[u]); j++) // i - j <= t
            {
                ndp[0][i] = min(ndp[0][i], dp[v][0][i - j] + dp[u][0][j]);
                ndp[1][i] = min(ndp[1][i], dp[v][1][i - j] + min(dp[u][0][j], dp[u][1][j]));
            }
        dp[v][0] = ndp[0];
        dp[v][1] = ndp[1];
    }
    //assert(dp[v][0].size() == sz[v] + 1);
    //assert(dp[v][1].size() == sz[v] + 1);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i] >> d[i];
        if(i > 0)
        {
            cin >> p[i];
            p[i]--;
            g[p[i]].push_back(i);
        }
    }
    dfs();
    int ans = 0;
    for(int i = 0; i <= n; i++)
        if(min(dp[0][1][i], dp[0][0][i]) <= b)
            ans = i;
    cout << ans << endl;
}