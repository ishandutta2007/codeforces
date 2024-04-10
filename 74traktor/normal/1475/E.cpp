#include<bits/stdc++.h>

using namespace std;

int a[1005];
int mod = 1e9 + 7;
int dp[1005][1005];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    for (int i = 0; i <= 1000; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        int c = a[n - k + 1];
        int cnt = 0, all = 0, need = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == c) {
                all++;
                if (i >= n - k + 1) need++;
            }
        }
        cout << dp[all][need] << '\n';
    }
    return 0;
}