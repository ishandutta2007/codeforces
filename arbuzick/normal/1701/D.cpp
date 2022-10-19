#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n), p(n);
    vector<vector<pair<int, int>>> add(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (d[i] == 0) {
            add[(i + 1) / (d[i] + 1) + 1].emplace_back(n * 10, i);
        } else {
            add[(i + 1) / (d[i] + 1) + 1].emplace_back((i + 1) / d[i], i);
        }
    }
    set<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) {
        for (auto pr : add[i]) {
            s.insert(pr);
        }
        p[s.begin()->second] = i;
        s.erase(s.begin());
    }
    int pos = 0;
    for (auto [val, ind] : s) {
        p[ind] = ++pos;
    }
    for (auto val : p) {
        cout << val << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}