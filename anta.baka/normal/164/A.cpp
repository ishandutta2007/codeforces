#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int n, m, f[maxn];
vector<int> g[maxn], g1[maxn];
bool was1[maxn], was2[maxn];

void dfs(int v) {
    was1[v] = true;
    for(int to : g[v])
        if(!was1[to])
            dfs(to);
}

void dfs2(int v) {
    was2[v] = true;
    if(f[v] == 1) return;
    for(int to : g1[v])
        if(!was2[to])
            dfs2(to);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> f[i];
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g1[v].push_back(u);
    }
    for(int u = 0; u < n; u++)
        if(f[u] == 1 && !was1[u])
            dfs(u);
    for(int u = 0; u < n; u++)
        if(f[u] == 2 && !was2[u])
            dfs2(u);
    for(int u = 0; u < n; u++)
        cout << (was1[u] && was2[u] ? 1 : 0) << ' ';
}