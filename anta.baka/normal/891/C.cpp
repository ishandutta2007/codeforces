#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 5e5;

struct DSU {
    int n;
    vector<int> sz, par, x, y;
    DSU(int _n) {
        n = _n;
        sz.resize(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int find(int v) {
        while(v != par[v]) v = par[v];
        return v;
    }
    int unite(int u, int v) {
        u = find(u); v = find(v);
        if(u != v) {
            if(sz[u] < sz[v]) swap(u, v);
            sz[u] += sz[v]; par[v] = u;
            x.push_back(u); y.push_back(v);
            return 1;
        }
        return 0;
    }
    void redo(int cnt) { // 
        for(int i = 0; i < cnt; i++) {
            int u = x.back(), v = y.back();
            sz[u] -= sz[v]; par[v] = v;
            x.pop_back(); y.pop_back();
        }
    }
};

int n, m, U[maxn], V[maxn], W[maxn], q;
vector<bool> ans(maxn, true);
vector<int> z[maxn];
vector<pair<int, vector<int>>> vec[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; --u; --v; --w;
        U[i] = u; V[i] = v; W[i] = w;
        z[w].push_back(i);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        int sz; cin >> sz;
        for(int j = 0; j < sz; j++) {
            int id; cin >> id; id--;
            int w = W[id];
            if(vec[w].empty() || vec[w].back().fi != i) vec[w].push_back({i, {}});
            vec[w].back().se.push_back(id);
        }
    }
    DSU mst(n);
    for(int i = 0; i < maxn; i++) { // MAXW
        for(int j = 0; j < vec[i].size(); j++) {
            int qu = vec[i][j].fi;
            if(!ans[qu]) continue;
            vector<int> &ve = vec[i][j].se;
            int ste = 0;
            for(int id : ve) {
                ste += mst.unite(U[id], V[id]);
            }
            if(ste != ve.size()) ans[qu] = false;
            mst.redo(ste);
        }
        for(int id : z[i])
            mst.unite(U[id], V[id]);
    }
    for(int i = 0; i < q; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';
}