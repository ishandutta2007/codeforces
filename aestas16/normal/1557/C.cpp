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

const int N = 6e5, P = 1e9 + 7;

int n, m, fac[N + 10], ifac[N + 10], p2[N + 10];

void InitC() {
    fac[0] = fac[1] = ifac[0] = ifac[1] = p2[0] = 1, p2[1] = 2;
    for (int i = 2; i <= N; i++) ifac[i] = (P - P / i) * ifac[P % i] % P, p2[i] = p2[i - 1] * 2 % P;
    for (int i = 2; i <= N; i++) fac[i] = fac[i - 1] * i % P, ifac[i] = ifac[i] * ifac[i - 1] % P;
}

int C(int x, int y) {
    if (y > x || x < 0 || y < 0) return 0;
    return fac[x] * ifac[y] % P * ifac[x - y] % P;
}

int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    InitC();
    for (int T = fr(); T--;) {
        int n = fr(), k = fr(), ans = 0;
        if (n & 1) {
            for (int i = 0; i <= (n >> 1); i++) ans = (ans + C(n, i << 1)) % P;
            ans++, ans = qpow(ans, k);
        } else {
            for (int i = 0; i < (n >> 1); i++) ans = (ans + C(n, i << 1)) % P;
            int tmp = ans;
            ans = qpow(ans, k);
            for (int i = 1; i <= k; i++) ans = (ans + qpow(tmp, i - 1) * qpow(p2[n], k - i) % P) % P;
        }
        printf("%lld\n", ans);
    }
    return 0;
}