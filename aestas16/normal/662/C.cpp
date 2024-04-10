#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 22, M = 2e5, P = 998244353;

int n, m, ans = N * M + 10, a[1 << N | 5], b[1 << N | 5], c[1 << N | 5];
char mp[N + 1][M + 1];

void XOR(int *f, int v) {
    for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
        for (int i = 0; i < n; i += o)
            for (int j = 0, x, y; j < k; j++) x = (f[i + j] + f[i + j + k]) % P, y = (f[i + j] - f[i + j + k] + P) % P, f[i + j] = v * x % P, f[i + j + k] = v * y % P;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, m);
    for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
    for (int i = 0; i < (1 << n); i++) b[i] = __builtin_popcount(i), b[i] = min(b[i], n - b[i]);
    for (int i = 1; i <= m; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++) x = (x << 1) | (mp[j][i] - '0');
        a[x]++;
    }
    n = 1 << n, XOR(a, 1), XOR(b, 1);
    for (int i = 0; i < n; i++) c[i] = a[i] * b[i] % P;
    XOR(c, (P + 1) / 2);
    for (int i = 0; i < n; i++) ans = min(ans, c[i]);
    return printf("%lld\n", ans), 0;
}