#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
const int mod = 1e9 + 7;
 
ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    ll loops = 0;
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[v]++;
        deg[u]++;
        if (v == u) {
            loops++;
        } else {
            g[v].push_back(u);
            g[u].push_back(v);
        }
    }
    ll ans = loops * (m - loops) + loops * (loops - 1) / 2;
    for (int i = 1; i <= n; i++) {
        ans += ((ll)g[i].size() - 1) * g[i].size() / 2;
    }

    vector<int> used(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!g[i].empty()) {
            used[i] = 1;
            q.push(i);
            break;
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (!used[u]) {
                used[u] = 1;
                q.push(u);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] && !used[i]) {
            ans = 0;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}