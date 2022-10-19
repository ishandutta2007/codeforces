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
    vector<int> color(m + 1);
    vector<vector<int>> ic(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        ic[i].resize(s);
        for (int j = 0; j < s; j++) {
            cin >> ic[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int v, int par) {
        set<int> kek;
        for (int i = 1; i <= ic[v].size(); i++) {
            kek.insert(i);
        }
        for (int c : ic[v]) {
            kek.erase(color[c]);
        }
        for (int c : ic[v]) {
            if (color[c]) continue;
            color[c] = *kek.begin();
            kek.erase(kek.begin());
        }
        for (int u : g[v]) {
            if (u != par) {
                dfs(u, v);
            }
        }
    };
    dfs(1, -1);
    for (int i = 1; i <= m; i++) {
        if (!color[i]) color[i] = 1;
    }
    cout << *max_element(color.begin() + 1, color.end()) << '\n';
    for (int i = 1; i <= m; i++) {
        cout << color[i] << " \n"[i == m];
    }
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