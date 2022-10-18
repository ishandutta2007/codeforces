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

const int N = 50, M = 1e5, P = 998244353;

int n, m, ans, l[N + 10], r[N + 10], sum[M + 10], g[M + 10];
int pnum[M + 10], ptot, mu[M + 10];
bool isnp[M + 10];

void InitP() {
    isnp[1] = 1;
    mu[1] = 1;
    for (int i = 2; i <= M; i++) {
        if (isnp[i] == 0) pnum[++ptot] = i, mu[i] = -1;
        for (int j = 1; j <= ptot && i * pnum[j] <= M; j++) {
            isnp[i * pnum[j]] = 1;
            if (i % pnum[j] == 0) {
                mu[i * pnum[j]] = 0;
                break;
            } else {
                mu[i * pnum[j]] = -mu[i];
            }
        }
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    InitP(), fr(n), fr(m);
    for (int i = 1; i <= n; i++) fr(l[i], r[i]);
    for (int i = 1; i <= m; i++) {
        int k = m / i, f = 0;
        for (int j = 1; j <= n; j++) {
            int L = (l[j] + i - 1) / i, R = r[j] / i;
            L = max(L, 1ll);
            if (L > R) {
                f = 1;
                break;
            }
            if (j > 1) {
                for (int K = 1; K <= k; K++) g[K] = sum[max(0ll, K - L)] - sum[max(0ll, K - R - 1)];
                for (int K = 1; K <= k; K++) sum[K] = 0;
                for (int K = 1; K <= k; K++) sum[K] = (sum[K - 1] + g[K]) % P;
            } else {
                for (int K = 1; K <= k; K++) sum[K] = 0;
                for (int K = L; K <= R; K++) sum[K] = 1;
                for (int K = 2; K <= k; K++) sum[K] = (sum[K] + sum[K - 1]) % P;
            }
        }
        if (f) continue;
        int tmp = 0;
        for (int j = 0; j <= k; j++) tmp = (tmp + g[j]) % P;
        ans = (ans + mu[i] * tmp % P + P) % P;
    }
    printf("%lld\n", ans);
    return 0;
}