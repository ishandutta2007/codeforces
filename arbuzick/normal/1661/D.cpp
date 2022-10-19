#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<long long> cnt(n);
    long long ans = 0;
    long long nw_sum = 0, nw_cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i + k < n) {
            nw_cnt -= cnt[i + k];
            nw_sum -= (i + 1) * cnt[i + k];
        }
        b[i] = b[i] - ((i + 1) * nw_cnt - nw_sum);
        if (b[i] > 0) {
            cnt[i] = (b[i] - 1) / min(k, i + 1) + 1;
            nw_sum += cnt[i] * (i - min(k, i + 1) + 1);
            nw_cnt += cnt[i];
            ans += cnt[i];
        }
    }
    cout << ans << endl;
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