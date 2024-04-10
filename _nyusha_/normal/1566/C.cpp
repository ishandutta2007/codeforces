#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
string s[2];
int dp[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> s[0] >> s[1];
        s[0] = "#" + s[0];
        s[1] = "#" + s[1];
        int last0 = -1, last1 = -1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            if (s[0][i] == '0') last0 = i;
            if (s[0][i] == '1') last1 = i;
            if (s[1][i] == '0') last0 = i;
            if (s[1][i] == '1') last1 = i;
            if (last0 != -1) dp[i] = max(dp[i], dp[last0 - 1] + 1);
            if (last0 != -1 && last1 != -1) dp[i] = max(dp[i], dp[min(last0, last1) - 1] + 2);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}