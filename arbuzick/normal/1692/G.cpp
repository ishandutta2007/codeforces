#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int pos = -n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i - 1] >= a[i] * 2) {
            pos = i - 1;
        }
        if (pos + k <= i && k <= i + 1) {
            ans++;
        }
    }
    cout << ans << '\n';
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