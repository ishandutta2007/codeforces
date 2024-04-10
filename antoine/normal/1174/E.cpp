#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = (int) 1e9 + 7;

int n;
int grid[21][2];
ll dp[2][2][(int) 1e6 + 9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 2; ++j)
            grid[i][j] = n / ((1 << i) * (j ? 3 : 1));

    for (int i = 0;; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (!grid[i][j])
                continue;
            for (int k = 0; k < grid[i][j]; ++k) {
                ll &res = dp[i&1][j][k] = !i && !j && !k;
                if (k)
                    res += k * dp[i&1][j][k - 1];
                if (i > 0) {
                    const int c = grid[i - 1][j] - grid[i][j];
                    res += c * dp[~i&1][j][k + c - 1];
                }
                if (j > 0) {
                    const int c = grid[i][j - 1] - grid[i][j];
                    res += c * dp[i&1][j - 1][k + c - 1];
                }
                res %= mod;
            }
        }
        if (!grid[i + 1][0]) {
            ll ans = grid[i][0] * dp[i&1][0][grid[i][0] - 1];
            if (i > 0 && grid[i - 1][1])
                ans += grid[i - 1][1] * dp[~i&1][1][grid[i - 1][1] - 1];
            cout << (ans % mod + mod) % mod;
            return 0;
        }
    }
}