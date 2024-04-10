#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    vector<long long> delt(n);
    delt[0] = a[0];
    for (int i = 1; i < n; ++i) {
        delt[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i < n; ++i) {
        ans += abs(delt[i]);
        if (delt[i] < 0) {
            delt[0] += delt[i];
        }
    }
    ans += abs(delt[0]);
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