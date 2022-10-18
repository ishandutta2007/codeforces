// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef Aestas16
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 0
#endif

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 3e6 + 10, P = 1e9 + 7;

int sum[N + 10][5], fac[N + 10], ifac[N + 10], inv[N + 10];

void InitC() {
    fac[0] = fac[1] = ifac[0] = ifac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = (P - P / i) * inv[P % i] % P;
    for (int i = 2; i <= N; i++) fac[i] = fac[i - 1] * i % P, ifac[i] = ifac[i - 1] * inv[i] % P;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    int n = fr(), q = fr();
    InitC();
    sum[1][1] = (3 * n - 1) % P * n % P * inv[2] % P, sum[1][2] = (3 * n + 1) % P * n % P * inv[2] % P, sum[1][3] = (3 * n + 3) % P * n % P * inv[2] % P;
    for (int i = 2; i <= n * 3; i++) {
        int a = i * sum[i - 1][1] % P, b = i * sum[i - 1][2] % P, c = fac[3 * n + 1] * ifac[3 * n - i] % P * inv[i + 1] % P;
        sum[i][1] = (c - ((a + a) % P + b) % P + P) % P;
        sum[i][1] = sum[i][1] * inv[3] % P;
        sum[i][2] = (sum[i][1] + a) % P;
        sum[i][3] = (sum[i][2] + b) % P;
    }
    while (q--) {
        int x = fr();
        printf("%lld\n", sum[x][3] * ifac[x] % P);
    }
    return 0;
}