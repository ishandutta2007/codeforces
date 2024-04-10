#include <bits/stdc++.h>

using namespace std;
//#define int long long

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        vector <vector <int>> all_t0(26), all_t1(26);
        for (int i = 0; i < (int)t.size(); ++i) {
            if (i % 2 == 0) all_t0[t[i] - 'a'].push_back(i);
            else all_t1[t[i] - 'a'].push_back(i);
        }
        vector <pair <int, int>> dp((int)s.size() + 1);
        dp[0] = make_pair(0, -1);
        for (int i = 0; i < (int)s.size(); ++i) {
            int dp0 = dp[i].first, dp1 = dp[i].second;
            int new_dp0, new_dp1;
            auto it = upper_bound(all_t0[s[i] - 'a'].begin(), all_t0[s[i] - 'a'].end(), dp0);
            if (it == all_t0[s[i] - 'a'].begin()) new_dp1 = -1;
            else new_dp1 = *(it - 1) + 1;
            if (dp1 == -1) new_dp0 = 0;
            else {
                it = upper_bound(all_t1[s[i] - 'a'].begin(), all_t1[s[i] - 'a'].end(), dp1);
                if (it == all_t1[s[i] - 'a'].begin()) new_dp0 = 0;
                else new_dp0 = *(it - 1) + 1;
            }
            new_dp0 = max(new_dp0, dp1 - 1);
            new_dp1 = max(new_dp1, dp0 - 1);
            if (i >= 1) {
                new_dp0 = max(new_dp0, dp[i - 1].first);
                new_dp1 = max(new_dp1, dp[i - 1].second);
            }
            dp[i + 1] = make_pair(new_dp0, new_dp1);
        }
        if (dp[(int)s.size()].first == (int)t.size() || dp[(int)s.size()].second == (int)t.size()) cout << "YES\n";
        else cout << "NO\n";
    }
}