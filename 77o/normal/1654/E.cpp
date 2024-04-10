#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
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
    // n = 100000;
    vector<int> a(n);
    map<int, int> asfasf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // a[i] = n;
        asfasf[a[i]]++;
    }
    int ans = n;
    for (auto [val, c] : asfasf)
        ans = min(ans, n - c);

    const int N = 2e5 + 1;
    const int SHIFT = 1e5;
    const int RT = 320;
    vector<ll> cnt(N);
    vector<pair<int,int>> g[N];
    for (int len = 1; len <= RT; len++) {
        for (int i = 0; i + len < n; i++) {
            if ((a[i + len] - a[i]) % len == 0) {
                int d = (a[i + len] - a[i]) / len;
                if (d)
                    g[d + SHIFT].emplace_back(i, i + len);
            }
        }
    }
    vector<int> mapping(n);
    vector<int> vertices;
    vector<int> p(n), sz(n);

    auto getRoot = [&](const auto& self, int v) -> int {
        return v == p[v] ? v : p[v] = self(self, p[v]);
    };
    auto unite = [&](int v, int u) {
        v = getRoot(getRoot, v);
        u = getRoot(getRoot, u);
        if (v == u)
            return;
        sz[v] += sz[u];
        p[u] = v;
        ans = min(ans, n - sz[v]);
    };

    for (int d = 0; d < N; d++) {
        if (g[d].empty())
            continue;
        vertices.clear();
        for (auto [l, r] : g[d]) {
            vertices.push_back(l);
            vertices.push_back(r);
        }
        sort(vertices.begin(), vertices.end());
        vertices.resize(unique(vertices.begin(), vertices.end()) - vertices.begin());
        int m = vertices.size();
        for (int i = 0; i < m; i++)
            mapping[vertices[i]] = i;
        iota(p.begin(), p.begin() + m, 0);
        fill(sz.begin(), sz.begin() + m, 1);
        for (auto [l, r] : g[d])
            unite(mapping[l], mapping[r]);
    }

    // for (int d = -SHIFT; d <= SHIFT; d++) {
    //     if (abs(d) <= RT)
    //         continue;
    //     if (cnt[d + SHIFT] == 0)
    //         continue;
    //     int c = sqrt(2 * cnt[d + SHIFT]);
    //     while (c * (c - 1) / 2 >= cnt[d + SHIFT])
    //         c--;
    //     while (c * (c + 1) / 2 <= cnt[d + SHIFT])
    //         c++;
    //     // assert(c * (c - 1) / 2 == cnt[d + SHIFT]);
    //     cout << d << ' ';
    //     cout << c << ' ' << cnt[d + SHIFT] << endl;
    //     ans = min(ans, n - c);
    // }
    vector<int> kek(n);
    for (int d = -RT; d <= RT; d++) {
        for (int i = 0; i < n; i++)
            kek[i] = a[i] - i * d;
        sort(kek.begin(), kek.end());
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur++;
            if (i + 1 == n || kek[i] != kek[i + 1]) {
                ans = min(ans, n - cur);
                cur = 0;
            }
        }
    }
    cout << ans << endl;
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