#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 1e9 + 7;
int dp[100005];

main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (auto c : s) {
        if (c == 'm' || c == 'w') {
            cout << 0 << '\n';
            return 0;
        }
    }
    dp[0] = 1;
    s = "0" + s;
    for (int i = 1; i < (int)s.size(); ++i) {
        dp[i] = dp[i - 1];
        if (s[i] == 'u' && s[i - 1] == 'u') dp[i] += dp[i - 2];
        if (s[i] == 'n' && s[i - 1] == 'n') dp[i] += dp[i - 2];
        dp[i] %= mod;
    }
    cout << dp[(int)s.size() - 1] << '\n';
    return 0;
}