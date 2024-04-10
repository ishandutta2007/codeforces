#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int INF = 1e9, maxn = 1e5;

struct DSU {
    vector<int> tsz, par, hed;
    DSU(int n) : tsz(n, 1), par(n), hed(n) { iota(all(par), 0); iota(all(hed), 0); }
    int get(int v) {
        return (par[v] == v ? v : par[v] = get(par[v]));
    }
    int unite(int u, int v) {
        u = get(u), v = get(v);
        if(tsz[u] > tsz[v]) {
            par[v] = u;
            tsz[u] += tsz[v];
        } else {
            hed[v] = hed[u];
            par[u] = v;
            tsz[v] += tsz[u];
        }
    }
};

struct query {
    int t, a, b;
} a[maxn];

int n, q, degin[maxn];
vector<int> g[maxn];
int tin[maxn], tout[maxn], tik_tak;

void dfs(int v, int p) {
    tin[v] = tik_tak++;
    for(int to : g[v]) if(to != p) dfs(to, v);
    tout[v] = tik_tak++;
}

bool upper(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> q;
    for(int i = 0; i < q; i++) {
        cin >> a[i].t >> a[i].a, a[i].a--;
        if(a[i].t != 2) cin >> a[i].b, a[i].b--;
        if(a[i].t == 1) g[a[i].b].push_back(a[i].a), degin[a[i].a]++;
    }
    for(int i = 0; i < n; i++) if(!degin[i]) dfs(i, -1);
    DSU dsu(n);
    vector<int> u, v;
    for(int i = 0; i < q; i++) {
        if(a[i].t == 1) dsu.unite(a[i].b, a[i].a);
        else if(a[i].t == 2) {
            v.push_back(a[i].a);
            u.push_back(dsu.hed[dsu.get(a[i].a)]);
        } else {
            int id = a[i].b, w = a[i].a;
            int uu = u[id], vv = v[id];
            cout << (upper(uu, w) && upper(w, vv) ? "YES" : "NO") << '\n';
        }
    }
}