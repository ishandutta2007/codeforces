#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 205;
const int MOD = 1000000007;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = res * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return res;
}

int inv(int x) { return power(x, MOD - 2); }

int n;
vector<int> g[N];
int d[N][N];
int pr[N][N];
int dp[N][N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    pr[0][0] = 1;
    int i2 = inv(2);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) continue;
            pr[i][j] = ((i > 0 ? pr[i - 1][j] * i2 : 0) + (j > 0 ? pr[i][j - 1] * i2 : 0)) % MOD; 
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < j; k++) {
                dp[i][j] = (dp[i][j] + pr[i - 1][k] * i2) % MOD;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) d[i][j] = 1e9;
        d[i][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        d[u][v] = 1; d[v][u] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int in = inv(n);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int r = 1; r <= n; r++) {
                if (d[r][i] + d[i][j] == d[r][j]) continue;
                if (d[r][j] + d[j][i] == d[r][i]) {
                    res = (res + in) % MOD;
                    // cout << i << ' ' << j << ' ' << r << endl;
                    continue;
                }
                int arm = (d[r][i] + d[r][j] - d[i][j]) / 2;
                int di = d[r][i] - arm;
                int dj = d[r][j] - arm;
                // cout << i << ' ' << j << ' ' << r << endl;
                res = (res + dp[dj][di] * in) % MOD;
            }
        }
    }
    cout << res << '\n';

    return 0;
}