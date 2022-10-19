#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

const int N = 2005;

ll dp[N][N][2];
char f[N][N];
int cnt[N][N][2];
int id[N][N][2];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
    }
    if (n + m == 2) {
        cout << "1\n";
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            cnt[i][j][0] = cnt[i + 1][j][0] + (f[i + 1][j] == 'R');
            cnt[i][j][1] = cnt[i][j + 1][1] + (f[i][j + 1] == 'R');
        }
    }
    dp[0][0][0] = dp[0][0][1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j == 0) continue;
            if (j) {
                id[i][j][0] = id[i][j - 1][0];
                dp[i][j][0] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % mod;
                if (i == 0 & j == 1) dp[i][j][0]--;
                while (cnt[i][id[i][j][0]][1] >= m - j && id[i][j][0] < j) {
                    dp[i][j][0] = (dp[i][j][0] + mod - dp[i][id[i][j][0]][1]) % mod;
                    id[i][j][0]++;
                }
            }
            if (i) {
                id[i][j][1] = id[i - 1][j][1];
                dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % mod;
                if (i == 1 && j == 0) dp[i][j][1]--;
                while (cnt[id[i][j][1]][j][0] >= n - i && id[i][j][1] < i) {
                    dp[i][j][1] = (dp[i][j][1] + mod - dp[id[i][j][1]][j][0]) % mod;
                    id[i][j][1]++;
                }
            }
        }
    }

    cout << (dp[n - 1][m - 1][0] + dp[n - 1][m - 1][1]) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}