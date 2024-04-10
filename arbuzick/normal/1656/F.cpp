#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i] + a[i];
    }
    long long ans = -1e18;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ans = max(ans, -a[i] * 1LL * a[i] * (n - 1));
            if (-a[i] * 1LL * a[i] * (n - 1) < 1 * 1LL * (pr[n] - pr[1] + (-a[i] + 1) * 1LL * (n - 1)) - (a[i] - 1) * 1LL * (a[i] - 1) * (n - 1)) {
                cout << "INF\n";
                return;
            }
        } else if (i == n - 1) {
            ans = max(ans, -a[i] * 1LL * a[i] * (n - 1));
            if (-a[i] * 1LL * a[i] * (n - 1) < -1 * 1LL * (pr[n - 1] + (-a[i] - 1) * 1LL * (n - 1)) - (a[i] + 1) * 1LL * (a[i] + 1) * (n - 1)) {
                cout << "INF\n";
                return;
            }
        } else {
            ans = max(ans, (a[0] - a[i]) * 1LL * (pr[n] - pr[i + 1] - a[i] * 1LL * (n - i - 1)) + 
                           (a[n - 1] - a[i]) * 1LL * (pr[i] - pr[1] - a[i] * 1LL * (i - 1)) - a[i] * 1LL * a[i] * (n - 1));
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