#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42;
int n, m;
pair<int, int> edge[maxn];
vector<int> g[maxn];
int used[maxn];
int dp[maxn];

void dfs(int v)
{
    if(used[v])
        return;
    used[v] = 1;
    dp[v] = 1;
    for(auto u: g[v])
    {
        dfs(u);
        dp[v] = max(dp[v], dp[u] + 1);
    }
}

bool check(int m)
{
    memset(used, 0, sizeof(used));
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
        g[i].clear();
    for(int i = 0; i < m; i++)
        g[edge[i].first].push_back(edge[i].second);
    bool ret = 0;
    for(int i = 0; i < n; i++)
    {
        dfs(i);
        if(dp[i] == n)
            ret = 1;
    }
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[i] = {u - 1, v - 1};
    }
    int l = 0, r = m + 1;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        if(!check(m))
            l = m;
        else
            r = m;
    }
    if(l < m)
        cout << l + 1 << "\n";
    else
        cout << -1 << "\n";
}