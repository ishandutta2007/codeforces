#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

struct Edge {
    int v, u, w;
    Edge(int _v = 0, int _u = 0, int _w = 0) : v(_v), u(_u), w(_w) {}
};

struct Dsu {
private:
    int n;
    vector <int> p, sz;
public:
    Dsu(int _n) {
        n = _n;
        p.resize(n, -1);
        sz.resize(n, 1);
    }

    int get(int v) {
        if (p[v] == -1)
            return v;
        return p[v] = get(p[v]);
    }

    void unite(int v, int u) {
        v = get(v), u = get(u);
        if (v == u)
            return;
        if (sz[v] > sz[u])
            swap(v, u);
        p[v] = u;
        sz[u] += sz[v];
    }
};

vector <vector <pii>> tr;
vector <int> bad;

void mst(int n, vector <Edge>& edges) {
    Dsu d(n);
    sort(all(edges), [&](Edge a, Edge b){return a.w < b.w;});
    for (auto e : edges) {
        if (d.get(e.v) != d.get(e.u)) {
            d.unite(e.v, e.u);
            tr[e.v].eb(e.u, e.w), tr[e.u].eb(e.v, e.w);
        } else {
            bad.pb(e.v);
        }
    }
}

const int INF = 1e18;

void dijkstra(int st, const vector <vector <pii>>& gr, vector <int>& dst) {
    dst.resize(sz(gr), INF);
    set <pii> s;
    s.emplace(0, st);
    dst[st] = 0;
    while (!s.empty()) {
        int v = s.begin() -> sc;
        s.erase(s.begin());
        for (pii u : gr[v]) {
            if (dst[v] + u.sc < dst[u.fs]) {
                s.erase({dst[u.fs], u.fs});
                dst[u.fs] = dst[v] + u.sc;
                s.emplace(dst[u.fs], u.fs);
            }
        }
    }
}

vector <vector <pii>> gr;

struct Segtree {
private:
    int n;
    vector <pii> tr;
    pii neutral_tr = {INT_MAX, 0};

    pii merge(pii a, pii b) {
        if (a.fs < b.fs)
            return a;
        else 
            return b;
    }

    void build(const vector <pii>& a) {
        forn (i, 0, n) 
            tr[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    Segtree(const vector <pii>& a) {
        n = sz(a);
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    pii get(int l, int r) {
        pii ans = neutral_tr;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                ans = merge(ans, tr[l++]);
            if (r % 2)
                ans = merge(ans, tr[--r]);
        }
        return ans;
    }
};

vector <int> h, first;
vector <pii> euler;

void dfs(int v, int p, int cur_h, int weight) {
    h[v] = weight;
    first[v] = sz(euler);
    euler.eb(cur_h, v);
    for (pii u : tr[v]) {
        if (u.fs != p) {
            dfs(u.fs, v, cur_h + 1, weight + u.sc);
            euler.eb(cur_h, v);
        }
    }
}

int lca(int v, int u, Segtree& a) {
    if (first[v] > first[u])
        swap(v, u);
    return a.get(first[v], first[u] + 1).sc;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <Edge> edges(m);
    gr.resize(n);
    forn (i, 0, m) {
        cin >> edges[i].v >> edges[i].u >> edges[i].w, edges[i].v--, edges[i].u--;
        gr[edges[i].v].eb(edges[i].u, edges[i].w), gr[edges[i].u].eb(edges[i].v, edges[i].w);
    }
    tr.resize(n);
    mst(n, edges);
    vector <vector <int>> dst(sz(bad));
    forn (i, 0, sz(bad))
        dijkstra(bad[i], gr, dst[i]);
    h = first = vector <int> (n);
    dfs(0, -1, 0, 0);
    Segtree a(euler);
    int q;
    cin >> q;
    while (q --> 0) {
        int v, u;
        cin >> v >> u, v--, u--;
        int ans = h[v] + h[u] - 2 * h[lca(v, u, a)];
        forn (i, 0, sz(dst))
            ans = min(ans, dst[i][v] + dst[i][u]);
        cout << ans << "\n";
    }
    return 0;
}