#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int dp[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, p, k, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> p >> k;
        string s;
        cin >> s;
        cin >> x >> y;
        s = "#" + s;
        dp[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            int val = 0;
            if (s[i] == '0') {
                val += x;
            }
            val += dp[min(n + 1, i + k)];
            dp[i] = val;
        }
        int ans = dp[p];
        for (int i = 1; i <= n; ++i) {
            if (n - i + 1 < p) continue;
            ans = min(ans, dp[i + p - 1] + (i - 1) * y);
        }
        cout << ans << '\n';
    }
    return 0;
}