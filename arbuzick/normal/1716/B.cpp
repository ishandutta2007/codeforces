#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << n << '\n';
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[j] << ' ';
        }
        cout << '\n';
        if (i + 1 < n) {
            swap(ans[0], ans[i + 1]);
        }
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