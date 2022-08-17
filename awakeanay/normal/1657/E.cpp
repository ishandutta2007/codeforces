#include <iostream>

#define int long long

const int MOD = 998244353;

int expo(int x, int p) {
    int ret = 1;
    while(p > 0) {
        if(p&1)
            ret = (ret*x)%MOD;

        p >>= 1;
        x = (x*x)%MOD;
    }
    return ret;
}

signed main() {
    int n, k;
    std::cin >> n >> k;

    int dp[k+1][n];
    int binom[n+1][n+1];

    for(int i = 0; i <= n; i++)
        binom[i][i] = binom[i][0] = 1;

    for(int i = 0; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            binom[i][j] = (binom[i-1][j] + binom[i-1][j-1])%MOD;
        }
    }

    for(int i = 0; i < n; i++)
        dp[0][i] = i == 0;

    for(int j = 1; j <= k; j++) {
        for(int i = 0; i < n; i++) {
            dp[j][i] = 0;
            for(int p = 0; p <= i; p++) {
                int v = (n-1-i)*p + (p*(p-1))/2;
                int cur = expo(j, v)*dp[j-1][i-p];
                cur %= MOD;
                dp[j][i] += cur*binom[i][p];
                dp[j][i] %= MOD;
            }
        }
    }

    std::cout << dp[k][n-1] << std::endl;
}