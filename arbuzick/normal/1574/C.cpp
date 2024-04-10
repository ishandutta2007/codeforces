#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    while (m--) {
        long long x, y;
        cin >> x >> y;
        long long ans = x + y;
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (pos != a.size()) {
            ans = min(ans, max(0LL, y - (sum - a[pos])));
        }
        if (pos > 0) {
            ans = min(ans, x - a[pos - 1] + max(0LL, y - (sum - a[pos - 1])));
        }
        cout << ans << '\n';
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