#pragma GCC optimize("O3")
//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <numeric>
#include <cmath>

//#define _USE_MATH_DEFINES
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<int> cnt(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
    }
    int q;
    cin >> q;
    vector<vector<int>> ans(q);
    for (int _ = 0; _ < q; ++_) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        vector<int> dist(n, -1), pr(n, -1);
        set<pair<int, int>> s;
        dist[a] = 0;
        s.insert({0, a});
        while (!s.empty()) {
            int v = s.begin()->second;
            s.erase(s.begin());
            for (auto[u, w]: g[v]) {
                if (dist[u] == -1 || dist[u] > dist[v] + 1 - cnt[w]) {
                    pr[u] = v;
                    s.erase({dist[u], u});
                    dist[u] = dist[v] + 1 - cnt[w];
                    s.insert({dist[u], u});
                }
            }
        }
        for (int v = b; v != a; v = pr[v]) {
            ans[_].push_back(v);
            for (auto[u, w]: g[v]) {
                if (u == pr[v]) {
                    cnt[w] ^= 1;
                }
            }
        }
        ans[_].push_back(a);
        reverse(ans[_].begin(), ans[_].end());
    }
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += cnt[i];
    }
    if (sum == 0) {
        cout << "YES\n";
        for (auto v: ans) {
            cout << (int)v.size() << '\n';
            for (auto v1: v) {
                cout << v1 + 1 << ' ';
            }
            cout << '\n';
        }
    } else {
        int ans1 = 0;
        for (int i = 0; i < n; ++i) {
            int ch = 0;
            for (auto [j, w]: g[i]) {
                if (cnt[w]) {
                    ch++;
                }
            }
            ans1 += ch % 2;
        }
        cout << "NO\n";
        cout << ans1 / 2;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}