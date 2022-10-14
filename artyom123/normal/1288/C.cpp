#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    long long dpa[m][n + 1], dpb[m][n + 1];
    for (int j = 1; j <= n; j++) {
        dpa[0][j] = dpb[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            dpa[i][j] = dpb[i][j] = 0;
            for (int j1 = 1; j1 <= n; j1++) {
                if (j1 <= j) {
                    dpa[i][j] += dpa[i - 1][j1];
                    dpa[i][j] %= mod;
                }
                if (j1 >= j) {
                    dpb[i][j] += dpb[i - 1][j1];
                    dpb[i][j] %= mod;
                }
            }
        }
    }
    long long ans = 0;
    for (int ja = 1; ja <= n; ja++) {
        for (int jb = ja; jb <= n; jb++) {
            ans += dpa[m - 1][ja] * dpb[m - 1][jb];
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}