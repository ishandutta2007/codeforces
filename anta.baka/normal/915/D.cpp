#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[500], g1[500];
vector<bool> was;
vector<int> tps;

void dfs1(int v) {
    if(was[v]) return;
    was[v] = true;
    for(int to : g[v])
        dfs1(to);
    tps.push_back(v);
}

int cnow;
vector<int> inc, sz;

void dfs2(int v) {
    inc[v] = cnow;
    sz[cnow]++;
    for(int to : g1[v])
        if(inc[to] == -1)
            dfs2(to);
}

int bu, bv;
vector<int> col;

bool dfs3(int v) {
    col[v] = 1;
    bool ret = false;
    for(int to : g[v])
        if(v == bu && to == bv);
        else if(col[to] == 1)
            ret = true;
        else if(col[to] == 0)
            ret |= dfs3(to);
    col[v] = 2;
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g1[v].push_back(u);
    }
    was.assign(n, false);
    for(int i = 0; i < n; i++) dfs1(i);
    reverse(tps.begin(), tps.end());
    inc.assign(n, -1);
    for(int v : tps)
        if(inc[v] == -1)
            sz.push_back(0), dfs2(v), cnow++;
    int ncyc = 0;
    for(int i = 0; i < cnow; i++) ncyc += (sz[i] != 1);
    if(ncyc == 0) return cout << "YES", 0;
    if(ncyc > 1) return cout << "NO", 0;
    vector<int> deg(n, 0), vin(n);
    for(int u = 0; u < n; u++)
        for(int v : g[u])
            if(inc[u] == inc[v])
                deg[v]++, vin[v] = u;
    for(int u = 0; u < n; u++)
        if(deg[u] == 1) {
            bu = vin[u], bv = u;
            col.assign(n, 0);
            bool ok = true;
            for(int i = 0; i < n; i++)
                if(col[i] == 0)
                    ok &= !dfs3(i);
            if(ok) return cout << "YES", 0;
        }
    cout << "NO";
}