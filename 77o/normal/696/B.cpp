#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <map>
#include <random>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= a) %= MOD;
        p >>= 1;
        (a *= a) %= MOD;
    }
    return res;
}

mt19937 rng(123);

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    vector<double> sz(n + 1);
    vector<double> ans(n + 1);
    auto dfs = [&](const auto& self, int v) -> void {
        sz[v] = 1;
        for (int u : g[v]) {
            self(self, u);
            sz[v] += sz[u];
        }
    };
    ans[1] = 1;
    auto dfs2 = [&](const auto& self, int v) -> void {
        for (int u : g[v]) {
            ans[u] = ans[v] + 1 + (sz[v] - 1 - sz[u]) / 2;
            self(self, u);
        }
    };
    dfs(dfs, 1);
    dfs2(dfs2, 1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}