#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

#define int long long

const int MOD = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return a * b % MOD;
}

signed main() {
    int n;
    cin >> n;
    vector<int> ppow(n + 1);
    ppow[0] = 1;
    for (int i = 1; i <= n; i++) {
        ppow[i] = ppow[i - 1] * 3 % MOD;
    }
    string s;
    cin >> s;
    int cnt1 = 0;
    for (char c : s)
        if (c == '?')
            cnt1++;
    int ans = 0;
    for (int mask = 0; mask < (1 << 3); mask++) {
        vector<vector<int>> dp(n, vector<int> (3));
        string t = "abc";
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (mask & (1 << i)) {
                t[i] = '?';
                cnt++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == t[0]) {
                dp[i][0] = 1;
            }
            if (i != 0) {
                dp[i][0] = add(dp[i][0], dp[i - 1][0]);
            }
        }
        for (int j = 1; j < 3; j++) {
            for (int i = j; i < n; i++) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            }
        }
        ans = add(ans, mul(dp.back().back(), ppow[cnt1 - cnt]));
    }
    cout << ans << endl;
}