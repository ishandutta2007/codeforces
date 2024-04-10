#include <bits/stdc++.h>
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using namespace std;
#define int long long
const int maxn = 1e5, INF = 2e12;

struct DSU {
    vector<int> par, tsz;
    DSU(int n) : par(n), tsz(n, 1) { iota(all(par), 0); }
    int get(int v) {
        return (v == par[v] ? v : par[v] = get(par[v]));
    }
    int unite(int u, int v) {
        if((u = get(u)) != (v = get(v))) {
            if(tsz[v] > tsz[u]) swap(u, v);
            par[v] = u; tsz[u] += tsz[v];
        }
    }
};

struct edge {
    int u, v, id;
    char ch;
};

int n, m;
edge e[maxn];

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    if(!(n & 1)) return cout << -1, 0;
    for(int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].ch;
        e[i].u--; e[i].v--; e[i].id = i;
    }
    DSU mst0(n);
    for(int i = 0; i < m; i++) if(e[i].ch == 'S' && mst0.get(e[i].u) != mst0.get(e[i].v)) {
        mst0.unite(e[i].u, e[i].v);
    }
    vector<edge> moroz;
    for(int i = 0; i < m; i++) if(e[i].ch == 'M' && mst0.get(e[i].u) != mst0.get(e[i].v)) {
        moroz.push_back(e[i]); mst0.unite(e[i].u, e[i].v);
    }
    if(mst0.tsz[mst0.get(0)] != n) return cout << -1, 0;
    DSU mst1(n);
    for(edge g : moroz) mst1.unite(g.u, g.v);
    for(int i = 0; i < m && sz(moroz) != (n - 1) / 2; i++) if(e[i].ch == 'M' && mst1.get(e[i].u) != mst1.get(e[i].v)) {
        mst1.unite(e[i].u, e[i].v); moroz.push_back(e[i]);
    }
    if(sz(moroz) != (n - 1) / 2) return cout << -1, 0;
    cout << n - 1 << '\n';
    for(edge g : moroz) cout << g.id + 1 << ' ';
    for(int i = 0; i < m; i++) if(e[i].ch == 'S' && mst1.get(e[i].u) != mst1.get(e[i].v)) {
        mst1.unite(e[i].u, e[i].v); cout << e[i].id + 1 << ' ';
    }
}