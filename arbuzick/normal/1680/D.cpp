#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 0) {
            cnt++;
        }
    }
    if (abs(sum) > k * 1LL * cnt) {
        cout << -1 << '\n';
        return;
    }
    vector<long long> pr_sum(n + 1);
    vector<int> pr_cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        pr_sum[i + 1] = pr_sum[i] + a[i];
        pr_cnt[i + 1] = pr_cnt[i];
        if (a[i] == 0) {
            pr_cnt[i + 1]++;
        }
    }
    long long ans = 0;
    for (int pos_min = 0; pos_min <= n; ++pos_min) {
        for (int pos_max = 0; pos_max <= n; ++pos_max) {
            if (pos_min < pos_max) {
                long long val1 = (pr_cnt[n] - pr_cnt[pos_max] + pr_cnt[pos_min]) * 1LL * k;
                long long add1 = min((pr_cnt[pos_max] - pr_cnt[pos_min]) * 1LL * k, val1 - pr_sum[n]);
                if (add1 < -(pr_cnt[pos_max] - pr_cnt[pos_min]) * 1LL * k) {
                    continue;
                }
                ans = max(ans, pr_sum[pos_max] - pr_sum[pos_min] + add1);
            } else if (pos_min != pos_max) {
                long long val1 = (pr_cnt[n] - pr_cnt[pos_min] + pr_cnt[pos_max]) * 1LL * k;
                long long add1 = min((pr_cnt[pos_min] - pr_cnt[pos_max]) * 1LL * k, val1 + pr_sum[n]);
                if (add1 < -(pr_cnt[pos_min] - pr_cnt[pos_max]) * 1LL * k) {
                    continue;
                }
                ans = max(ans, pr_sum[pos_max] - pr_sum[pos_min] + add1);
            }
        }
    }
    cout << ans + 1 << '\n';
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