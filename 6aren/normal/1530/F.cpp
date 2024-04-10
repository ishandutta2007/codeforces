#include <bits/stdc++.h>
using namespace std;

#define bit(x, y) ((x >> y) & 1)

const int MOD = 31607;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2) res = res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int invv = power(10000, MOD - 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] = a[i][j] * invv % MOD;
        }
    }

    vector<int> last_bit(1 << n);
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            if (bit(mask, j)) {
                last_bit[mask] = j;
                break;
            }
        }
    }

    // xac suat co row hoac column
    auto hasColOrRow = [&](vector<vector<int>> &prob) {
        int res = 0;
        vector<int> prob_row(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) prob_row[i] = prob_row[i] * prob[i][j] % MOD;
        }
        
        vector<vector<int>> prob_col((1 << n), vector<int>(n, 1));
        for (int mask = 1; mask < (1 << n); mask++) {
            int last = last_bit[mask];
            for (int j = 0; j < n; j++) {
                prob_col[mask][j] = prob_col[mask ^ (1 << last)][j] * prob[last][j] % MOD;
            }
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            int sign = (__builtin_popcountll(mask) % 2 == 0 ? 1 : MOD - 1);
            int tmp = 1;
            vector<int> tmp2(n, 1);
            for (int i = 0; i < n; i++) {
                if (bit(mask, i)) {
                    tmp = tmp * prob_row[i] % MOD;
                }
                tmp = tmp * (MOD + 1 - prob_col[((1 << n) - 1) ^ mask][i]) % MOD;
            }
            res = (res + sign * tmp % MOD) % MOD;
            if (res < 0) res += MOD;
        }
        return (MOD + 1 - res) % MOD;
    };

    int ans = hasColOrRow(a);
    {
        int B = 1;
        int C = 1;
        for (int i = 0; i < n; i++) {
            B = B * a[i][i] % MOD;
            C = C * a[i][n - 1 - i] % MOD;
        }
        int BC = B * C % MOD;
        if (n % 2) BC = BC * power(a[n / 2][n / 2], MOD - 2);
        ans = (ans + B + C - BC) % MOD;
        if (ans < 0) ans += MOD;
    }
    
    {
        // AB
        auto tmp = a;
        int foo = 1;
        for (int i = 0; i < n; i++) {
            tmp[i][i] = 1;
            foo = foo * a[i][i] % MOD;
        }
        ans = (ans - hasColOrRow(tmp) * foo % MOD + MOD) % MOD;
    }

    {
        // AC
        auto tmp = a;
        int foo = 1;
        for (int i = 0; i < n; i++) {
            tmp[i][n - 1 - i] = 1;
            foo = foo * a[i][n - 1 - i] % MOD;
        }
        ans = (ans - hasColOrRow(tmp) * foo % MOD + MOD) % MOD;
    }
    {
        // ABC
        auto tmp = a;
        int foo = 1;
        for (int i = 0; i < n; i++) {
            tmp[i][n - 1 - i] = 1;
            foo = foo * a[i][n - 1 - i] % MOD;
            tmp[i][i] = 1;
            if (i + i != n - 1) foo = foo * a[i][i] % MOD;
        }
        ans = (ans + hasColOrRow(tmp) * foo % MOD + MOD) % MOD;
    }
    cout << ans << '\n';

    return 0;
}