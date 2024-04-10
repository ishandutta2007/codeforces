#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
#define ll long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    ll c[n + 1][n + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
        }
    }
    vector <ll> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i) fact[i] = (ll)fact[i - 1] * i % p;
    ll dp[n + 1][m + 1][k + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int z = 0; z <= k; ++z) {
                dp[i][j][z] = 0;
            }
        }
    }
    for (int i = 0; i <= m; ++i) dp[0][i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0][0] = fact[i];
        for (int kk = 0; kk <= min(k, i); ++kk) {
            for (int j = 0; j < i; ++j) {
                for (int mm = 1; mm <= m; ++mm) {
                    if (mm > i && kk != 0) break;
                    for (int cnt_left = 0; cnt_left <= min(kk, j); ++cnt_left) {
                        int cnt_right = kk - cnt_left;
                        if (mm == 1) cnt_right--;
                        if (cnt_right < 0 || dp[j][mm - 1][cnt_left] == 0 || dp[i - j - 1][mm - 1][cnt_right] == 0) continue;
                        dp[i][mm][kk] += dp[j][mm - 1][cnt_left] * dp[i - j - 1][mm - 1][cnt_right] % p * c[i - 1][j];
                        dp[i][mm][kk] %= p;
                    }
                }
            }
        }
    }
    cout << dp[n][m][k];
}

/*

 */