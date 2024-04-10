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

struct Edge{
    int v, u;
    ll w;
    Edge(int _v = 0, int _u = 0, ll _w = 0) {v = _v, u = _u, w = _w;}
};

vector <int> p, sz;

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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <ll> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <Edge> edges(m);
    forn (i, 0, m) {
        cin >> edges[i].v >> edges[i].u >> edges[i].w;
        edges[i].v--, edges[i].u--;
    }
    int j = min_element(all(a)) - a.begin();
    forn (i, 0, n)
        if (i != j)
            edges.eb(i, j, a[i] + a[j]);
    sort(all(edges), [&](Edge a, Edge b){return a.w < b.w;});
    p.resize(n, -1), sz.resize(n, 1);
    ll ans = 0;
    for (Edge e : edges) {
        if (get(e.v) != get(e.u)) {
            unite(e.v, e.u);
            ans += e.w;
        }
    }
    cout << ans;
    return 0;
}