#include <bits/stdc++.h>

using namespace std;

int n, m, d, f[100000], D[100000], ans;
vector<bool> I;
vector<int> g[100000], pref[100000], suff[100000];

inline int get(int x)
{
    if(x == -1) return x;
    return x + 1;
}

void dfs1(int v, int p)
{
    if(I[v]) f[v] = 0;
    else f[v] = -1;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(to == p) { g[v].erase(g[v].begin() + i); i--; continue; }
        dfs1(to, v);
        f[v] = max(f[v], get(f[to]));
    }
    if(g[v].empty()) return;
    pref[v].resize(g[v].size());
    pref[v][0] = get(f[g[v][0]]);
    for(int i = 1; i < g[v].size(); i++)
        pref[v][i] = max(pref[v][i - 1], get(f[g[v][i]]));
    suff[v].resize(g[v].size());
    suff[v][g[v].size() - 1] = get(f[g[v].back()]);
    for(int i = (int)g[v].size() - 2; i >= 0; i--)
        suff[v][i] = max(suff[v][i + 1], get(f[g[v][i]]));
}


void dfs2(int v, int up)
{
    if(I[v] && up == -1) up = 0;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        D[to] = max({f[to], get(up), (i ? get(pref[v][i - 1]) : -1), (i < g[v].size() - 1 ? get(suff[v][i + 1]) : -1)});
        dfs2(to, max({get(up), (i ? get(pref[v][i - 1]) : -1), (i < g[v].size() - 1 ? get(suff[v][i + 1]) : -1)}));
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> d;
    I.assign(n, false);
    for(int i = 0; i < m; i++)
    {
        int v; cin >> v; --v; I[v] = true;
    }
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v; --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs1(0, -1);
    D[0] = f[0];
    dfs2(0, -1);
    for(int i = 0; i < n; i++) ans += (D[i] <= d);
    cout << ans;
}