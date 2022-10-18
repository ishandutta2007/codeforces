#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 707;

int dp[maxn][maxn][2];
int gg[maxn][maxn];
int a[maxn];
int usd[maxn][maxn][2];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < i; j++) {
            gg[i][j] = gg[j][i] = __gcd(a[i], a[j]);
        }
    }
    for(int i = 0; i < n; i++) {
        dp[i][i][0] = dp[i][i][1] = 1;
    }
    for(int ln = 2; ln <= n; ln++) {
        for(int l = 0; l + ln <= n; l++) {
            int r = l + ln - 1;
            for(int m = l + 1; m <= r - 1; m++) {
                dp[l][r][0] |= (gg[l][m] > 1) & dp[l + 1][m][1] & dp[m][r][0];
                dp[l][r][1] |= (gg[m][r] > 1) & dp[l][m][1] & dp[m][r - 1][0];
            }
            dp[l][r][0] |= (gg[l][r] > 1) & dp[l + 1][r][1];
            dp[l][r][1] |= (gg[l][r] > 1) & dp[l][r - 1][0];
        }
    }
    for(int i = 0; i < n; i++) {
        if(dp[0][i][1] && dp[i][n - 1][0]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}