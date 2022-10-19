#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, b;
    long long s;
    cin >> n >> k >> b >> s;
    if (s < k * 1LL * b) {
        cout << -1 << '\n';
        return;
    }
    vector<long long> ans(n);
    ans[0] = k * 1LL * b;
    s -= ans[0];
    for (int i = 0; i < n; ++i) {
        long long val = min(s, (long long)k - 1);
        ans[i] += val;
        s -= val;
    }
    if (s) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
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