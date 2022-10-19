#include <functional>
#include <iostream>
#include <set>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;

const int MOD = 998244353;

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

void solve() {
    int n;
    cin >> n;
    struct Edge {
        int u;
        int x, y;
    };
    vector<vector<int>> primes(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!primes[i].empty())
            continue;
        primes[i].push_back(i);
        for (int j = i * 2; j <= n; j += i) {
            int m = j;
            while (m % i == 0) {
                primes[j].push_back(i);
                m /= i;
            }
        }
    }

    vector<vector<Edge>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        g[a].push_back(Edge{b, y, x});
        g[b].push_back(Edge{a, x, y});
    }

    vector<int> low(n + 1);
    vector<int> cnt(n + 1);
    auto dfs = [&](const auto& self, int v, int p) -> void {
        for (auto &e : g[v]) {
            if (e.u == p)
                continue;
            for (int p : primes[e.x]) {
                cnt[p]++;
            }
            for (int p : primes[e.y]) {
                cnt[p]--;
                low[p] = min(low[p], cnt[p]);
            }
            self(self, e.u, v);
            for (int p : primes[e.x]) {
                cnt[p]--;
            }
            for (int p : primes[e.y]) {
                cnt[p]++;
            }
        }
    };
    dfs(dfs, 1, 0);

    vector<ll> ans(n + 1, 1), inv(n + 1);
    for (int p = 2; p <= n; p++) {
        ans[1] = ans[1] * binpow(p, -low[p]) % MOD;
        inv[p] = binpow(p, MOD - 2);
    }
    auto kek = [&](const auto& self, int v, int p) -> void {
        for (auto &e : g[v]) {
            if (e.u == p)
                continue;
            ans[e.u] = ans[v];
            for (int p : primes[e.x]) {
                // cout << v << " -> " << e.u << " *= " << p << endl;
                ans[e.u] = ans[e.u] * p % MOD;
            }
            for (int p : primes[e.y]) {
                ans[e.u] = ans[e.u] * inv[p] % MOD;
            }
            self(self, e.u, v);
        }
    };
    kek(kek, 1, 0);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        (res += ans[i]) %= MOD;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}