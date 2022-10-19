#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve() {
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    map<int, int> cv;
    for (int i = 0; i < n; ++i) {
        int c, v;
        cin >> c >> v;
        cv[c] = max(cv[c], v);
    }
    vector<pair<int, int>> b;
    for (auto [c, v] : cv) {
        if (b.empty() || v > b.back().second) {
            b.push_back({c, v});
        }
    }
    vector<int> g(k);
    for (int i = 0; i < k; ++i) {
        cin >> g[i];
    }
    g.push_back(0);
    g.push_back(s);
    sort(g.begin(), g.end());
    int l = -1, r = b.size();
    while (l < r - 1) {
        int m = (l + r) / 2;
        int mn = 0;
        for (int i = 1; i <= k + 1; ++i) {
            if (g[i] - g[i - 1] > b[m].second) {
                mn = t + 1;
                break;
            }
            mn += (g[i] - g[i - 1]) * 2 - min(g[i] - g[i - 1], b[m].second - (g[i] - g[i - 1]));
        }
        if (mn <= t) {
            r = m;
        } else {
            l = m;
        }
    }
    if (r == b.size()) {
        cout << -1 << '\n';
    } else {
        cout << b[r].first << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}