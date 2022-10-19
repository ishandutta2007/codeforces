#include <bits/stdc++.h>

using namespace std;
#define int long long
int mod = 998244353;
signed main() {
    int n;
    cin >> n;
    vector <int> s(n + 1);
    s[0] = 1;
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] * 10;
        s[i] %= mod;
    }
    vector <int> dp(n + 1);
    int pref = 0, pref1 = 0;
    for (int i = 1; i <= n; ++i) {
        pref += pref1;
        int tmp = ((i * s[i] - pref) % mod + mod) % mod;
        dp[i] = tmp;
        //pref += dp[i];
        pref %= mod;
        //pref += pref1;
        pref1 += dp[i];
        pref += dp[i];
    }
    for (int i = n; i >= 1; --i) {
        cout << dp[i] << " ";
    }
    return 0;
}