#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = (1 << 18) + 10;
int a[maxn];
int dp[maxn][20];
int inf = 1e15;

inline int s(int j, int t) {
    int ans = 0;
    for (int i = t - 1; i >= t - j; --i) ans += (1 << i);
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j < 19; ++j) dp[i][j] = inf;
    }
    dp[n + 1][0] = 0;
    int t = 0, x = n;
    while (x > 1) x /= 2, t++;
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= t; ++j) {
            if (n - i >= j && n - i + 1 <= s(j, t)) dp[i][j] = dp[i + 1][j];
            dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + a[i]);
        }
    }
    int pos = -1, ans = inf;
    for (int i = 1; i <= n; ++i) if (a[i] == -1) pos = i;
    if (pos == n) {
        cout << 0;
        return 0;
    }
    for (int j = 0; j <= t; ++j) {
        if (n - pos >= j && n - pos <= s(j, t)) {
            ans = min(ans, dp[pos + 1][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}