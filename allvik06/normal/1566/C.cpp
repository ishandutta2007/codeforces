#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;

inline int upd_mask(int mask, char c1, char c2) {
    return (mask | (1 << (c1 - '0')) | (1 << (c2 - '0')));
}

inline int get_cal(int mask) {
    if (mask == 3) return 2;
    if (mask & 1) return 1;
    return 0;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector <int> dp(4, -INF);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            vector <int> dp1(4, -INF);
            for (int last = 0; last < 4; ++last) {
                dp1[upd_mask(last, a[i], b[i])] = max(dp1[upd_mask(last, a[i], b[i])], dp[last]);
                dp1[upd_mask(0, a[i], b[i])] = max(dp1[upd_mask(0, a[i], b[i])], dp[last] + get_cal(last));
            }
            dp.swap(dp1);
        }
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            ans = max(ans, dp[i] + get_cal(i));
        }
        cout << ans << "\n";
    }
}