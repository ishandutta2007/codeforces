#include <bits/stdc++.h>

const int N = 200000;
const int P = 1000000007;

int fac[N + 1], inv[N + 1];

int qpow(int a, int b) {
    int s = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            s = 1ll * s * a % P;
        }
        a = 1ll * a * a % P;
    }
    return s;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }
    inv[N] = qpow(fac[N], P - 2);
    for (int i = N; i >= 1; --i) {
        inv[i - 1] = 1ll * inv[i] * i % P;
    }
}

int C(int n, int m) {
    if (m < 0 || m > n) {
        return 0;
    }
    return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (n & 1) {
        int v = qpow(2, n - 1);
        int ans = 0;
        int pw = 1;
        for (int i = 0; i <= m; ++i) {
            ans = (ans + 1ll * C(m, i) * pw) % P;
            pw = 1ll * pw * v % P;
        }
        std::cout << ans << "\n";
    } else {
        int v1 = qpow(2, n - 1), v2 = qpow(2 * v1 % P, P - 2);
        int ans = 0;
        int pw = 1;
        for (int i = 1; i <= m; ++i) {
            pw = 2ll * pw * v1 % P;
        }
        for (int i = 0; i <= m; ++i) {
            if (i < m) {
                pw = 1ll * pw * v2 % P;
            }
            ans = (ans + pw) % P;
            pw = 1ll * pw * (v1 - 1) % P;
        }
        std::cout << ans << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    init();

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}