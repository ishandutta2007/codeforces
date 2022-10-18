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

const int N = 6e2, P = 1e9 + 7;

int n, ans, sz[N + 10], fa[N + 10], a[N + 10], cnt[N + 10], g[N + 10][N + 10], h[N + 10], f[N + 10], fac[N + 10], ifac[N + 10];

void work(int &x) {
    for (int i = 2; i * i <= x; i++)
        while (x % (i * i) == 0) x /= (i * i);
}

int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
void merge(int u, int v) { u = find(u), v = find(v); (u != v) && (fa[u] = v, sz[v] += sz[u]);}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fac[0] = ifac[0] = fac[1] = ifac[1] = g[0][0] = 1;
    for (int i = 2; i <= N; i++) ifac[i] = (P - P / i) * ifac[P % i] % P;
    for (int i = 2; i <= N; i++) fac[i] = fac[i - 1] * i % P, ifac[i] = ifac[i] * ifac[i - 1] % P;
    for (int i = 2; i <= N; i++)
        for (int j = 1; j * 2 <= i; j++) g[i][j] = (g[i - 1][j] + g[i - 2][j - 1]) % P;
    for (int _ = 1; _--;) {
        fr(n), ans = 0;
        for (int i = 1; i <= n; i++) fr(a[i]), work(a[i]), fa[i] = i, f[i] = 0, sz[i] = 1;
        sort(a + 1, a + 1 + n), f[0] = 1;
        for (int i = 2; i <= n; i++) if (a[i] == a[i - 1]) merge(i, i - 1);
        for (int i = 1, up = 0; i <= n; i++)
            if (fa[i] == i) {
                int m = sz[i];
                for (int j = 1; j <= m; j++) h[j] = 0;
                for (int j = 2; j <= m; j++)
                    for (int k = 1; k * 2 <= j; k++) h[j - k] = (h[j - k] + g[j][k] * fac[m] % P * ifac[m - j] % P * ifac[k] % P) % P;
                for (int j = up; ~j; j--)
                    for (int k = 1; k < m; k++) f[j + k] = (f[j + k] + f[j] * h[k] % P) % P;
                up += m - 1;
            }
        for (int i = 0; i < n; i++) ans = (ans + ((i & 1) ? -1 : 1) * f[i] * fac[n - i] % P + P) % P;
        printf("%lld\n", ans);
    }
    return 0;
}