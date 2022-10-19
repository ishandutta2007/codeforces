#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i] + a[i];
    }
    long long ans = 0;
    if (k <= n) {
        for (int i = 0; i + k <= n; ++i) {
            ans = max(ans, pr[i + k] - pr[i] + k * 1LL * (k - 1) / 2);
        }
    } else {
        ans = pr[n] + (k - 1 + k - n) * 1LL * n / 2;
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