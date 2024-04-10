#include <bits/stdc++.h>

using namespace std;

int n, m, st[100000][20], sum[100000][20], tin[100000], tout[100000], tik_tak, q;
vector<int> g[100000], dep, up;
set<pair<int,int>> br;
vector<bool> was;

void dfs1(int v, int p = -1)
{
    for(int to : g[v])
        if(dep[to] != -1)
        {
            if(dep[to] < dep[v] && to != p) up[v] = min(up[v], dep[to]);
        }
        else
        {
            dep[to] = dep[v] + 1;
            dfs1(to, v);
            up[v] = min(up[v], up[to]);
            if(up[to] > dep[v]) br.insert({v, to});
        }
}

void dfs2(int v, int p)
{
    tin[v] = tik_tak++;
    was[v] = true;
    st[v][0] = p;
    if(br.find({p, v}) != br.end()) sum[v][0] = 1;
    for(int i = 1; i < 20; i++)
    {
        st[v][i] = st[st[v][i - 1]][i - 1];
        sum[v][i] = sum[v][i - 1] + sum[st[v][i - 1]][i - 1];
    }
    for(int to : g[v])
    {
        if(was[to]) continue;
        dfs2(to, v);
    }
    tout[v] = tik_tak++;
}

inline bool upper(int u, int v)
{
    return tin[u] < tin[v] && tout[v] < tout[u];
}

inline int query(int u, int v)
{
    if(u == v) return 0;
    int res = 0;
    if(tin[u] > tin[v]) swap(u, v);
    if(upper(u, v))
    {
        for(int i = 19; i >= 0; i--)
            if(!upper(st[v][i], u))
            {
                res += sum[v][i];
                v = st[v][i];
            }
        return res;
    }
    for(int i = 19; i >= 0; i--)
        if(!upper(st[u][i], v))
        {
            res += sum[u][i];
            u = st[u][i];
        }
    for(int i = 19; i >= 0; i--)
        if(!upper(st[v][i], u))
        {
            res += sum[v][i];
            v = st[v][i];
        }
    return res + sum[u][0] + sum[v][0];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v; --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dep.assign(n, -1);
    up.assign(n, INT_MAX);
    dep[0] = 0;
    dfs1(0);
    was.assign(n, false);
    dfs2(0, 0);
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int u, v; cin >> u >> v; --u; --v;
        cout << query(u, v) << endl;
    }
}