#include<bits/stdc++.h>

using namespace std;

int const maxn = 105;
int a[maxn];
int dp[maxn][maxn][maxn][2];
int inf = 1e9;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cnt0 = 0, cnt1 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i] != 0 && a[i] % 2 == 0) cnt0++;
        if (a[i] != 0 && a[i] % 2 == 1) cnt1++;
    }
    cnt0 = n / 2 - cnt0;
    cnt1 = (n + 1) / 2 - cnt1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int z = 0; z <= n; ++z) {
                dp[i][j][z][0] = inf, dp[i][j][z][1] = inf;
            }
        }
    }
    if (a[1] == 0) {
        if (cnt1 > 0) dp[1][cnt1 - 1][cnt0][1] = 0;
        if (cnt0 > 0) dp[1][cnt1][cnt0 - 1][0] = 0;
    }
    else dp[1][cnt1][cnt0][a[1] % 2] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= cnt1; ++j) {
            for (int z = 0; z <= cnt0; ++z) {
                if (a[i] == 0) {
                    dp[i][j][z][0] = min(dp[i - 1][j][z + 1][0], dp[i - 1][j][z + 1][1] + 1);
                    dp[i][j][z][1] = min(dp[i - 1][j + 1][z][1], dp[i - 1][j + 1][z][0] + 1);
                }
                else {
                    dp[i][j][z][a[i] % 2] = min(dp[i - 1][j][z][a[i] % 2], dp[i - 1][j][z][(1^(a[i] % 2))] + 1);
                }
            }
        }
    }
    cout << min(dp[n][0][0][0], dp[n][0][0][1]) << '\n';
    return 0;
}