#ifndef LOCAL
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

#include "bits/stdc++.h"

#ifdef DEBUG
    #include "includes/debug/debug.hpp"
#else
    #define debug(...) 0
#endif

using ll = int64_t;
using ull = uint64_t;
using ld = long double;

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // cout << setprecision(20) << fixed;
    int _tests = 1;
    // cin >> _tests;
    for (int _test = 1; _test <= _tests; ++_test) {
        // cout << "Case #" << _test << ": ";
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        // find vertex-weighted diameter
        vector<ll> d(n);
        vector<int> prv(n);
        auto dfs = [&](auto& self, int u, int p, ll dist) -> void {
            prv[u] = p;
            d[u] = dist;
            for (auto v : g[u]) {
                if (v == p) continue;
                self(self, v, u, dist + a[v]);
            }
        };
        dfs(dfs, 0, -1, a[0]);
        int l = int(max_element(begin(d), end(d)) - begin(d));
        dfs(dfs, l, -1, a[l]);
        int r = int(max_element(begin(d), end(d)) - begin(d));
        vector<int> path;
        for (int i = r; i != -1; i = prv[i]) path.push_back(i);
        vector<ll> max_length;
        // max_length[i] = max length of path (path[i], v] for v in subtree of
        // path[i] asdas
        ll max_diameter = 0;
        vector<bool> removed(n);
        for (auto u : path) removed[u] = true;
        for (int i = 0; i < (int)path.size(); ++i) {
            ll val = 0;
            auto dfs_subtree = [&](auto& self, int u, int p,
                                   ll dist) -> void {
                val = max(val, dist);
                for (auto v : g[u]) {
                    if (v == p || removed[v]) continue;
                    self(self, v, u, dist + a[v]);
                }
            };
            dfs_subtree(dfs_subtree, path[i], -1, 0);
            max_length.push_back(val);
            for (auto U : g[path[i]]) {
                if (removed[U]) continue;
                // find diameter of this subtree
                ll max_distance = -1;
                int endpoint = -1;
                auto dfs_lengths = [&](auto& self, int u, int p,
                                       ll dist) -> void {
                    if (dist > max_distance) {
                        max_distance = dist;
                        endpoint = u;
                    }
                    for (auto v : g[u]) {
                        if (v == p || removed[v]) continue;
                        self(self, v, u, dist + a[v]);
                    }
                };
                dfs_lengths(dfs_lengths, U, -1, a[U]);
                int left = endpoint;
                max_distance = -1;
                endpoint = -1;
                dfs_lengths(dfs_lengths, left, -1, a[left]);
                max_diameter = max(max_diameter, max_distance);
            }
        }
        ll ans = max_diameter;
        for (auto u : path) ans += a[u];
        vector<ll> prefix, suffix;
        ll length = 0;
        ll mx = 0;
        for (int i = 0; i < (int)path.size(); ++i) {
            length += a[path[i]];
            mx = max(mx, length + max_length[i]);
            prefix.push_back(mx);
        }
        length = 0;
        mx = 0;
        for (int i = (int)path.size() - 1; i >= 0; --i) {
            length += a[path[i]];
            mx = max(mx, length + max_length[i]);
            suffix.push_back(mx);
        }
        reverse(begin(suffix), end(suffix));
        for (int i = 0; i + 1 < (int)path.size(); ++i)
            ans = max(ans, prefix[i] + suffix[i + 1]);
        cout << ans << '\n';
    }
}