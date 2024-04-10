#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int subor[n][n];
    memset(subor, 0, sizeof(subor));
    for(int i = 0; i < n; i++) {
        subor[i][i] = a[i];
    }
    for(int j = 1; j < n; j++) {
        for(int i = 0; i + j < n; i++) {
            subor[i][i + j] = subor[i][i + j - 1] + a[i + j];
        }
    }
    const int logn = 60;
    int cmask = 0;
    for(int z = logn - 1; z >= 0; z--) {
        int tmask = cmask | (1LL << z);
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                for(int ii = 0; ii < i; ii++) {
                    if((subor[ii][i - 1] & tmask) == tmask) {
                        dp[i][j] |= dp[ii][j - 1];
                    }
                }
            }
        }
        if(dp[n][k]) {
            cmask = tmask;
        }
    }
    cout << cmask << endl;
    return 0;
}