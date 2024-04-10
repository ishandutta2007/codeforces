#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> used(n);
    for (int i = n - 1; i >= 0; --i) {
        if (used[a[i]]) {
            cout << i + 1 << '\n';
            return;
        }
        used[a[i]] = 1;
    }
    cout << 0 << '\n';
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