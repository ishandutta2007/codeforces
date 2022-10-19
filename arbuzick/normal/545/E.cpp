#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

const int maxn = 3e5 + 5, inf = 1e18;
vector<pair<pair<int, int>, int>> g[maxn];
int dist[maxn], pr[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({{v, w}, i});
        g[v].pb({{u, w}, i});
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
    }
    int kek;
    cin >> kek;
    kek--;
    dist[kek] = 0;
    for (int i =0 ; i < n; ++i) {
        s.insert({dist[i], i});
    }
    while (!s.empty()) {
        int v = s.begin()->s;
        s.erase(s.begin());
        for (auto [e, i]: g[v]) {
            auto [u, w] = e;
            if (dist[u] > dist[v] + w) {
                s.erase({dist[u], u});
                dist[u] = dist[v] + w;
                s.insert({dist[u], u});
            }
        }
    }
    int ans = 0;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (i == kek) {
            continue;
        }
        pr[i] = -1;
        int s = -1;
        for (auto [e, j]: g[i]) {
            if (dist[i] == dist[e.f] + e.s && (pr[i] == -1 || e.s < s)) {
                s = e.s;
                pr[i] = j;
            }
        }
        ans += s;
        a.pb(pr[i] + 1);
    }
    cout << ans << '\n';
    for (auto e: a) {
        cout << e << ' ';
    }
    return 0;
}