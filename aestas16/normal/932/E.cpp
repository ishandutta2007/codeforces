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

const int N = 5e3, P = 1e9 + 7;

int n, k, ans, S[N + 10][N + 10];

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
    fr(n, k), S[0][0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= i; j++) S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j] % P) % P;
    int fac = 1, f = 1;
    for (int i = 1; i <= k && i <= n; i++)
        f = f * (n - i + 1) % P * qpow(i, P - 2) % P, fac = fac * i % P, ans = (ans + fac * f % P * qpow(2, n - i) % P * S[k][i] % P) % P;
    return printf("%lld\n", ans), 0;
}