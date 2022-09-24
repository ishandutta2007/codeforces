#include <bits/stdc++.h>

using namespace std;

vector<int> color;
vector<vector<int>> g;
vector<int> ans, dp;

void dfs(int u, int p)
{
    dp[u] = 1;
    if (color[u] == 0) dp[u] = -1;
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if (v==p) continue;
        dfs(v,u);
        if (dp[v]>0) dp[u] += dp[v];
    }
}

void dfs2(int u, int p, int cur)
{
    ans[u] = cur+dp[u];
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if (v==p) continue;
        if (dp[v]>0)
        {
            dfs2(v,u,max(cur-dp[v]+dp[u],0));
        }
        else
        {
            dfs2(v,u,max(cur+dp[u],0));
        }
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    color.resize(n);
    dp.resize(n);
    ans.resize(n);
    for (int i=0;i<n;i++)
    {
        cin >> color[i];
    }
    for (int i=0;i<n-1;i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1, 0);
    for (int i=0;i<n;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}