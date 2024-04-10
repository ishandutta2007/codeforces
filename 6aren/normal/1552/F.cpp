#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    vector<int> dp(n);
    vector<int> delta(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i]; 
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[0] = x[0] + x[0] - y[0] + 1;
            if (dp[0] < 0) dp[0] += MOD;
            continue;
        }
        int cur = (dp[i - 1] + x[i] - (x[i - 1] + 1)) % MOD;
        if (cur < 0) cur += MOD;
        int id = upper_bound(x.begin(), x.end(), y[i]) - x.begin() - 1;
        int l_time = 0;
        if (id == -1) {
            l_time = y[i] % MOD;
        } else {
            l_time = (dp[id] + y[i] - (x[id] + 1)) % MOD;
            if (l_time < 0) l_time += MOD;
        }
        delta[i] = (dp[i - 1] - l_time + x[i] - x[i - 1]) % MOD;
        if (delta[i] < 0) delta[i] += MOD;
        cur = (cur + dp[i - 1] - l_time + x[i] - x[i - 1]) % MOD;
        if (cur < 0) cur += MOD;
        dp[i] = cur;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == 1) cur = dp[i] % MOD;
            else cur = (x[i] + 1) % MOD;
            continue;
        }
        if (s[i] == 0) {
            cur = (x[i] - x[i - 1] + cur) % MOD;
            if (cur < 0) cur += MOD;
        } else {
            cur = (cur + delta[i] + x[i] - (x[i - 1] + 1)) % MOD;
            if (cur < 0) cur += MOD;
        }
    }
    cout << cur << '\n';

    return 0;
}