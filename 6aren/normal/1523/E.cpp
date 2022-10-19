#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;
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

int fac[N], ifac[N];

int C(int n, int k) {
    if (k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[N - 1] = power(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % MOD;

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        int res = 1;
        for (int i = 1; i <= n; i++) {
            int foo = C(n - (k - 1) * (i - 1), i) * power(C(n, i), MOD - 2) % MOD;
            res = (res + foo) % MOD;
        }
        cout << res << '\n';
    }

    return 0;
}