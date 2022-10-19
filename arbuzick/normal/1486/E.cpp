#include <bits/stdc++.h>

//#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;
const int maxn = 51 * 1e5, inf = 1e9;
vector<pii> g[maxn];
int dist[maxn];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[v].pb({u + w * n, 0});
        g[u].pb({v + w * n, 0});
        for (int kek = 1; kek <= 50; ++kek) {
            g[u + kek * n].pb({v, (kek + w) * (kek + w)});
            g[v + kek * n].pb({u, (kek + w) * (kek + w)});
        }
    }
    for (int i = 0; i < n * 51; ++i) {
        dist[i] = inf;
    }
    dist[0] = 0;
    set<pii> s;
    s.insert({0, 0});
    while (!s.empty()) {
        int v = s.begin()->s;
        s.erase(s.begin());
        for (auto [u, w]: g[v]) {
            if (dist[u] > dist[v] + w) {
                s.erase({dist[u], u});
                dist[u] = dist[v] + w;
                s.insert({dist[u], u});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dist[i] == inf) {
            cout << -1 << ' ';
        } else {
            cout << dist[i] << ' ';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q = 1;
    //cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}