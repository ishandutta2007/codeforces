// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &...a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e6, P = 1e9 + 7;

int n, k, ans, fac[N + 10], ifac[N + 10], lf[N + 10], rf[N + 10];

int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n, k), fac[0] = fac[1] = ifac[0] = ifac[1] = lf[0] = rf[k + 3] = 1;
    for (int i = 2; i <= k + 2; i++) fac[i] = fac[i - 1] * i % P, ifac[i] = (P - P / i) * ifac[P % i] % P;
    for (int i = 2; i <= k + 2; i++) ifac[i] = ifac[i - 1] * ifac[i] % P;
    for (int i = 1; i <= k + 2; i++) lf[i] = lf[i - 1] * ((n - i + P) % P) % P;
    for (int i = k + 2; i; i--) rf[i] = rf[i + 1] * ((n - i + P) % P) % P;
    for (int i = 1, anss, ansm, sum = 0; i <= k + 2; i++) {
        sum = (sum + qpow(i, k)) % P, anss = sum * lf[i - 1] % P * rf[i + 1] % P, ansm = ifac[i - 1] * ifac[k + 2 - i] % P;
        if ((k + 2 - i) & 1) ans = ((ans - anss * ansm % P) + P) % P;
        else ans = (ans + anss * ansm % P) % P;
    }
    return printf("%lld\n", ans), 0;
}