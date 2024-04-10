#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, z;
    cin >> n >> z;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans = max(ans, a[i] | z);
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