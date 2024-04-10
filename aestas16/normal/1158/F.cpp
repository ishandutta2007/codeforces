/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(signed &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
signed fr() {
    signed a;
    return fr(a), a;
}

const int N = 3e3, P = 998244353;

int n, c, a[N + 10], p2[N + 10], invp2[N + 10], ans[N + 10], g[N + 10][N + 10], f[N + 10][N + 10];

int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P) b & 1 ? ret = 1ll * ret * a % P : 0;
    return ret;
}

void work() {
    int s = (1 << c) - 1;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = n / c; j >= 0; j--)
            for (int k = s - 1; k >= 0; k--)
                if (f[j][k]) {
                    if ((k | 1 << a[i]) == s)
                        f[j + 1][0] = (f[j + 1][0] + f[j][k]) % P;
                    else
                        f[j][k | 1 << a[i]] = (f[j][k | 1 << a[i]] + f[j][k]) % P;
                }
    for (int i = 0; i <= n; i++) {
        int ans = i ? 0 : P - 1;
        for (int j = 0; j < s; j++) ans = (ans + f[i][j]) % P;
        printf("%d ", ans);
    }
    puts("");
}

struct OI {
    int RP, score;
} FJOI2021;

signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    fr(n), fr(c);
    for (int i = 1; i <= n; i++) a[i] = fr() - 1;
    if (c <= 11) return work(), 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < c; j++) g[i][j] = g[i - 1][j];
        g[i][a[i]]++;
    }
    for (int i = 1; i <= n; i++) p2[i] = qpow(2, i) - 1, invp2[i] = qpow(p2[i], P - 2);
    f[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        int tot = 0, tmp = 1, qwq = p2[n - i] + 1;
        for (int j = i + 1; j <= n; j++) {
            int d = g[j][a[j]] - g[i][a[j]];
            if (d > 1)
                tmp = 1ll * tmp * p2[d] % P * invp2[d - 1] % P;
            else
                tot++;
            if (tot == c) {
                tmp = 1ll * tmp * invp2[d] % P;
                qwq = (qwq + 1ll * (P - tmp) * (p2[n - j] + 1)) % P;
                for (int k = i / c; k >= 0; k--) f[j][k + 1] = (f[j][k + 1] + 1ll * f[i][k] * tmp) % P;
                tmp = 1ll * tmp * p2[d] % P;
            }
        }
        for (int j = i / c; j >= 0; j--) ans[j] = (ans[j] + 1ll * f[i][j] * qwq) % P;
    }
    ans[0] = (ans[0] - 1 + P) % P;
    for (int i = 0; i <= n; ++i) printf("%d ", ans[i]);
    return puts(""), 0;
}