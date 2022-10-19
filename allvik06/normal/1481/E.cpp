#include <bits/stdc++.h>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <int>> all(n + 1);
    vector <int> num(n + 1);
    for (int i = 0; i < n; ++i) {
        num[i] = all[a[i]].size();
        all[a[i]].push_back(i);
    }
    bool ok = true;
    vector <int> bad;
    for (int i = 1; i <= n; ++i) {
        if (all[i].empty()) continue;
        if (all[i].back() - all[i].front() + 1 != all[i].size()) {
            ok = false;
            bad.push_back(i);
        }
    }
    if (ok) {
        cout << 0;
        return 0;
    }
    vector <int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        if (i == all[a[i]].back()) dp[i + 1] = max(dp[i + 1], dp[all[a[i]].front()] + (int)all[a[i]].size());
    }
    int minn = n - dp.back();
    for (int i = 0; i < n; ++i) {
        minn = min(minn, num[i] + n - dp[i] - (int)all[a[i]].size());
    }
    cout << minn;
}