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

struct Edge{
    int v, u, w;
    Edge(int _v = 0, int _u = 0, int _w = 0) : v(_v), u(_u), w(_w) {}
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <Edge> e(m);
    forn (i, 0, m) 
        cin >> e[i].v >> e[i].u >> e[i].w, e[i].v--, e[i].u--;
    sort(all(e), [&](Edge a, Edge b){return a.w < b.w;});
    Dsu a(n);
    int ans = 0;
    vector <bool> used(n);
    forn (i, 0, m) {
        int j = i;
        while (j < m && e[j].w == e[i].w)
            j++;
        int good = 0;
        forn (k, i, j) 
            good += a.get(e[k].v) == a.get(e[k].u);
        forn (k, i, j) {
            if (a.get(e[k].v) != a.get(e[k].u)) {
                good++;
                a.unite(e[k].v, e[k].u);
            }
        }
        ans += j - i - good;
        i = j - 1;
    }
    cout << ans;
    return 0;
}