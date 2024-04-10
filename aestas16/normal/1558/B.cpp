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
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 8e6;

int n, P, ans, f[N + 10], g[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n, P);
    for (int i = 1; i <= n; i++) {
        if (i == 1) f[i] = 1;
        else f[i] = g[i] = (g[i] + g[i - 1]) % P;
        g[i + 1] = (g[i + 1] + f[i]) % P;
        for (int j = i + i, k = 2; j <= n; j += i, k++) g[j] = (g[j] + f[i]) % P, g[j + k] = (g[j + k] - f[i] + P) % P;
    }
    printf("%lld\n", f[n]);
    return 0;
}