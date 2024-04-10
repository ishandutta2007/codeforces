#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, maxn = 255;

int binpow(int n, int k) {
    if (k == 0) {
        return 1;
    }
    if (k % 2) {
        return binpow(n, k - 1) * 1LL * n % mod;
    }
    int m = binpow(n, k / 2);
    return m * 1LL * m % mod;
}

int f[maxn], _f[maxn];

int c(int n, int k) {
    return f[n] * 1LL * _f[k] % mod * _f[n - k] % mod;
}

int dp[maxn][maxn], pr[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    f[0] = _f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * 1LL * i % mod;
        _f[i] = binpow(f[i], mod - 2);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        pr[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int nw = 1; nw <= k; ++nw) {
            for (int j = 0; j < i; ++j) {
                dp[i][nw] = (dp[i][nw] + pr[j][nw] * 1LL * c(n - j - 1, i - j) % mod * binpow(k - nw + 1, (i - j) * j + (i - j) * (i - j - 1) / 2)) % mod;
            }
            pr[i][nw + 1] = (pr[i][nw] + dp[i][nw]) % mod;
        }
    }
    cout << pr[n - 1][k + 1];
    return 0;
}