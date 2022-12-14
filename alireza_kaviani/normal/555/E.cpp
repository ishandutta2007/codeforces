/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Alireza Kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, q, timer, st[MAXN], mn[MAXN], mark[MAXN], par[LOG][MAXN], bridge[MAXN], H[MAXN], P[MAXN], sz[MAXN];
ll ps[MAXN];
vector<pll> E, adj[MAXN];
vector<ll> g[MAXN];

void DFS(ll v, ll id = -1) {
    mark[v] = 1;
    st[v] = ++timer;
    for (pll i : adj[v]) {
        ll u = i.X, ind = i.Y;
        if (!mark[u]) {
            DFS(u, ind);
            mn[v] = min(mn[v], mn[u]);
            if (mn[u] > st[v]) bridge[ind] = 1;
        } else if (ind != id) {
            mn[v] = min(mn[v], st[u]);
        }
    }
}

ll Find(ll v) {
    return (P[v] == -1 ? v : P[v] = Find(P[v]));
}

void Union(ll v, ll u) {
    v = Find(v), u = Find(u);
    if (v == u) return;
    if (sz[v] < sz[u]) swap(v, u);
    P[u] = v;
    sz[v] += sz[u];
}

void DFS2(ll v, ll p = 0) {
    mark[v] = 1;
    H[v] = H[p] + 1;
    par[0][v] = p;
    for (ll u : g[v]) if (u != p) DFS2(u, v);
}

ll getPar(ll v, ll h) {
    for (ll i = 0; i < LOG; i++) {
        if (h & (1ll << i)) {
            v = par[i][v];
        }
    }
    return v;
}

ll LCA(ll v, ll u) {
    if (H[v] > H[u]) swap(v, u);
    u = getPar(u, H[u] - H[v]);
    if (u == v) return v;
    for (ll i = LOG - 1; i >= 0; i--) {
        if (par[i][v] != par[i][u]) {
            v = par[i][v];
            u = par[i][u];
        }
    }
    return par[0][v];
}

void DFS3(ll v, ll p = 0) {
    for (ll u : g[v]) {
        if (u != p) {
            DFS3(u, v);
            ps[v] += ps[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(mn, mn + MAXN, INF);
    fill(P, P + MAXN, -1);
    fill(sz, sz + MAXN, 1);

    cin >> n >> m >> q;
    for (ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        E.push_back({u, v});
        adj[v].push_back({u, i});
        adj[u].push_back({v, i});
    }
    for (ll i = 1; i <= n; i++) if (!mark[i]) DFS(i);

    for (ll i = 0; i < m; i++) {
        ll v = E[i].X, u = E[i].Y;
        if (!bridge[i]) Union(u, v);
    }

    for (ll i = 0; i < m; i++) {
        ll v = E[i].X, u = E[i].Y;
        if (bridge[i]) {
            g[Find(v)].push_back(Find(u));
            g[Find(u)].push_back(Find(v));
        }
    }

    fill(mark, mark + MAXN, 0);
    for (ll i = 1; i <= n; i++) if (!mark[Find(i)]) DFS2(Find(i));

    for (ll i = 1; i < LOG; i++) {
        for (ll j = 0; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    while (q--) {
        ll v, u;
        cin >> v >> u;
        u = Find(u), v = Find(v);
        ll lca = LCA(v, u);
        if (lca == 0) return cout << "No" << endl, 0;
        ps[v] += MAXN;
        ps[lca] -= MAXN;
        ps[u]++;
        ps[lca]--;
    }

    for (ll i = 1; i <= n; i++) if (Find(i) == i && par[0][Find(i)] == 0) DFS3(Find(i));
    for (ll i = 1; i <= n; i++) {
        if (ps[i] >= MAXN && ps[i] % MAXN != 0) return cout << "No" << endl, 0;
    }
    cout << "Yes" << endl;

    return 0;
}
/*

*/