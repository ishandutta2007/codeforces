#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MOD = 1000000007;

int power(int x, long long y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        y >>= 1;
        x = 1LL * x * x % MOD;
    }
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        int cur = 1;
        int res = 0;
        for (int i = k - 1; i >= 0; i--) {
            // greater
            {
                int tmp = 1LL * cur * (n % 2 == 0);
                res = (res + 1LL * tmp * power(2, i * n)) % MOD;
            }
            // equal
            {
                int tmp = power(2, n - 1);
                tmp = (tmp + (n % 2 ? 1 : -1) + MOD) % MOD;
                cur = 1LL * cur * tmp % MOD;
            }
        }
        res = (res + cur) % MOD;
        cout << res << '\n';
    }

    return 0;
}