#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;

struct DSU {
    vector<int> par, sz, e;
    DSU(int n) : par(n), sz(n, 1), e(n, 0) { iota(par.begin(), par.end(), 0); }
    int get(int v) { return v == par[v] ? v : par[v] = get(par[v]); }
    bool unite(int u, int v) {
        u = get(u); v = get(v);
        if(u == v && e[u] + 1 > sz[u]) return false;
        if(u != v && e[u] + e[v] + 1 > sz[u] + sz[v]) return false;
        if(u != v) {
            if(sz[u] < sz[v]) swap(u, v);
            sz[u] += sz[v]; par[v] = u;
            e[u] += e[v];
        }
        e[u]++;
        return true;
    }
};

int n, m, u[maxn], v[maxn], w[maxn], id[maxn], ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--; id[i] = i;
    }
    sort(id, id + m, [](int a, int b){ return w[a] > w[b]; });
    DSU dsu(n);
    for(int i = 0; i < m; i++) if(dsu.unite(u[id[i]], v[id[i]])) ans += w[id[i]];
    cout << ans;
}