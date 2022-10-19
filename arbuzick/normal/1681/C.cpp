#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        int pos = i;
        for (int j = i; j < n; ++j) {
            if (a[j] < a[pos]) {
                pos = j;
            }
        }
        if (pos != i) {
            ans.emplace_back(i, pos);
            swap(a[i], a[pos]);
        }
    }
    bool ch = true;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i].second > a[i + 1].second) {
            ch = false;
            break;
        }
    }
    if (!ch) {
        cout << -1 << '\n';
        return;
    }
    cout << ans.size() << '\n';
    for (auto [i, j] : ans) {
        cout << i + 1 << ' ' << j + 1 << '\n';
    }
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