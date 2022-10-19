#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXB = 64;

void solve() {
    int n, m;
    cin >> n >> m;
    int dp[MAXB][2][2][2];
    for (int i = 0; i < MAXB; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
    dp[MAXB - 1][0][0][0] = 1;
    for (int i = MAXB - 2; i >= 0; --i) {
        int bn = ((n >> i) & 1);
        int bm = ((m >> i) & 1);
        for (int b = 0; b < 2; ++b) {
            for (int p = 0; p < 2; ++p) {
                for (int c = 0; c < 2; ++c) {
                    int pp;
                    if (b + p + bn >= 2) pp = 1;
                    else pp = 0;
                    int x = (c ^ b);
                    if ((b + p + bn) % 2 == 1) x ^= 1;
                    if (b < bm) {
                        dp[i][c][p][1] += dp[i + 1][x][pp][0] + dp[i + 1][x][pp][1];
                    } else if (b == bm) {
                        dp[i][c][p][0] += dp[i + 1][x][pp][0];
                        dp[i][c][p][1] += dp[i + 1][x][pp][1];
                    } else {
                        dp[i][c][p][1] += dp[i + 1][x][pp][1];
                    }
                }
            }
        }
    }
    cout << dp[0][1][0][1] << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) solve();
}