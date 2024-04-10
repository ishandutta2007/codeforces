#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<int> usd;

vector<vector<int>> g;

void dfs(int v, int &sz, int bad) {
    usd[v] = 1;
    sz++;
    for (auto &to : g[v]) {
        if (usd[to] || to == bad) continue;
        dfs(to, sz, bad);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b; a--; b--;
        g.clear();
        g.resize(n);
        usd.assign(n, 0);
        while (m--) {
            int u, v;
            cin >> u >> v; u--; v--;
            g[v].pb(u); g[u].pb(v);
        }
        vector<int> sz_without_a(1);
        dfs(b, sz_without_a[0], a);
        for (int v = 0; v < n; v++) {
            if (v != a && !usd[v]) {
                sz_without_a.pb(0);
                dfs(b, sz_without_a.back(), a);
            }
        }
        if (sz_without_a.size() == 1) {
            cout << 0 << "\n";
            continue;
        }
        usd.assign(n, 0);
        vector<int> sz_without_b(1);
        dfs(a, sz_without_b[0], b);
        for (int v = 0; v < n; v++) {
            if (v != b && !usd[v]) {
                sz_without_b.pb(0);
                dfs(a, sz_without_b.back(), b);
            }
        }
        if (sz_without_b.size() == 1) {
            cout << 0 << "\n";
            continue;
        }
        cout << (ll)(n - 1 - sz_without_a[0]) * (ll)(n - 1 - sz_without_b[0]) << "\n";
    }
    return 0;
}