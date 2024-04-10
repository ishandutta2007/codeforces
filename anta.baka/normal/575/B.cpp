#include <bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;

int n, tin[100000], tout[100000], tik_tak, dp[100000][17], downadd[100000], downsub[100000], upadd[100000], upsub[100000], k, ans, up[100000], down[100000];
vector<pair<int,int>> g[100000];

void dfs1(int v, int p)
{
    dp[v][0] = p;
    for(int i = 1; i < 17; i++) dp[v][i] = dp[dp[v][i - 1]][i - 1];
    tin[v] = tik_tak++;
    for(pair<int,int> edge : g[v])
    {
        int to = edge.first;
        if(to == p) continue;
        dfs1(to, v);
    }
    tout[v] = tik_tak++;
}

inline bool upper(int u, int v)
{
    return tin[u] < tin[v] && tout[u] > tout[v];
}

inline int LCA(int u, int v)
{
    if(tin[u] > tin[v]) swap(u, v);
    if(upper(u, v)) return u;
    for(int i = 16; i >= 0; i--)
        if(!upper(dp[u][i], v))
            u = dp[u][i];
    return dp[u][0];
}

int mypow(int n)
{
    if(n < 0) return 0;
    if(!n) return 1;
    if(n & 1) return (2 * mypow(n - 1)) % mod;
    int x = mypow(n >> 1);
    return (1LL * x * x) % mod;
}

void dfs2(int v, int p)
{
    up[v] = upadd[v] - upsub[v];
    down[v] = downadd[v] - downsub[v];
    for(pair<int,int> edge : g[v])
    {
        int to = edge.first;
        if(to == p) continue;
        dfs2(to, v);
        up[v] += up[to];
        down[v] += down[to];
        if(edge.second == 0) ans = (ans + mypow(up[to]) - 1) % mod;
        else if(edge.second == 1) ans = (ans + mypow(down[to]) - 1) % mod;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v, x; cin >> u >> v >> x; --u; --v;
        if(x == 0) g[u].push_back({v, -1}), g[v].push_back({u, -1});
        else g[u].push_back({v, 0}), g[v].push_back({u, 1});
    }
    dfs1(0, 0);
    cin >> k;
    int u = 0;
    for(int i = 0; i < k; i++)
    {
        int v; cin >> v; --v;
        if(u == v) continue;
        int g = LCA(u, v);
        if(g == u)
        {
            downadd[v]++;
            downsub[u]++;
        }
        else if(g == v)
        {
            upadd[u]++;
            upsub[v]++;
        }
        else
        {
            upadd[u]++;
            upsub[g]++;
            downadd[v]++;
            downsub[g]++;
        }
        u = v;
    }
    dfs2(0, -1);
    cout << ans;
}