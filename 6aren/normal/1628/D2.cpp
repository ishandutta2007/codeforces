#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        y >>= 1;
        x = 1LL * x * x % MOD;
    }
    return res;
}

int fac[N], ifac[N];

int C(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    ifac[N - 1] = power(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) {
        ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;
    }
    int i2 = (MOD + 1) / 2;
    int q;
    cin >> q;
    while (q--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n - m == 0) {
            cout << 1LL * k * n % MOD << '\n';
            continue;
        }
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            res = (res + 1LL * i * C(n - i - 1, n - m - 1) % MOD * power(i2, n - i)) % MOD;
        }
        cout << 1LL * res * k % MOD << '\n';
    }
    return 0;
}