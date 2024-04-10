#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    int count1_pr = 0, count2_pr = 0, count1_suf = 0, count2_suf = 0;
    for (auto [val, c] : cnt) {
        if (c > 1) {
            count2_suf++;
        } else {
            count1_suf++;
        }
    }
    ans = max(ans, count2_suf + count1_suf / 2);
    for (auto [val, c] : cnt) {
        if (c > 1) {
            count2_suf--;
        } else {
            count1_suf--;
        }
        ans = max(ans, count2_pr + count2_suf + 1 + (count1_pr + count1_suf) / 2);
        if (c > 1) {
            count2_pr++;
        } else {
            count1_pr++;
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