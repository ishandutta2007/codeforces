#include <bits/stdc++.h>

using namespace std;

#define int long long
char a[2005][2005];
int dp[2005][2005][2];
int pref[2005][2005];
int sum[2005][2005];
int row[2005][2005][2];
int col[2005][2005][2];
int mod = 1e9 + 7;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
        for (int j = 1; j <= m; ++j) {
            pref[i][j] = pref[i][j - 1];
            if (a[i][j] == 'R') pref[i][j]++;
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            sum[j][i] = sum[j][i - 1];
            if (a[i][j] == 'R') sum[j][i]++;
        }
    }
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    row[1][1][0] = 1;
    row[1][1][1] = 1;
    col[1][1][1] = 1;
    col[1][1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;
            int x = 0;
            int lef = 0, righ = j;
            while (righ - lef > 1) {
                int mid = (righ + lef) / 2;
                if (pref[i][m] - pref[i][mid] <= m - j) righ = mid;
                else lef = mid;
            }
            //if (i == n && j == m) cout << righ << '\n';
            /*for (int lst = j - 1; lst >= 1; --lst) {
                if (pref[i][m] - pref[i][lst] <= m - j) {
                    dp[i][j][1] += dp[i][lst][0];
                    dp[i][j][1] %= mod;
                }
            }*/
            dp[i][j][1] = (dp[i][j][1] + row[i][j - 1][0] - row[i][righ - 1][0] + mod) % mod;
            /*for (int lst = i - 1; lst >= 1; --lst) {
                if (sum[j][n] - sum[j][lst] <= n - i) {
                    dp[i][j][0] += dp[lst][j][1];
                    dp[i][j][0] %= mod;
                }
            }*/
            lef = 0, righ = i;
            while (righ - lef > 1) {
                int mid = (righ + lef) / 2;
                if (sum[j][n] - sum[j][mid] <= n - i) righ = mid;
                else lef = mid;
            }
            //if (i == n && j == m)
            dp[i][j][0] = (dp[i][j][0] + col[j][i - 1][1] - col[j][righ - 1][1] + mod) % mod;
            row[i][j][0] = (row[i][j - 1][0] + dp[i][j][0]) % mod;
            row[i][j][1] = (row[i][j - 1][1] + dp[i][j][1]) % mod;
            col[j][i][0] = (col[j][i - 1][0] + dp[i][j][0]) % mod;
            col[j][i][1] = (col[j][i - 1][1] + dp[i][j][1]) % mod;
        }
    }
    //cout << dp[2][2][0] << '\n';
    cout << (dp[n][m][0] + dp[n][m][1]) % mod << '\n';
    return 0;
}