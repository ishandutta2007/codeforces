// 392699

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

const int N = 3e2, P = 1e9 + 7;

int n, d[N + 10], f[N + 10][N + 10], g[N + 10][N + 10][N + 10];

int dfs(int i, int j, int k) {
    if (i < 0 || j < 0) return 0;
    if (g[i][j][k] != -1) return g[i][j][k];
    if (k) g[i][j][k] = (i * dfs(i - 1, j, k - 1) % P + j * dfs(i + 1, j - 1, k - 1) % P) % P;
    else if (i) g[i][j][k] = ((i - 1) * dfs(i - 2, j, k) % P + j * dfs(i, j - 1, k) % P) % P;
    else if (j >= 3) {
        g[i][j][k] = 0;
        for (int l = 3, C = ((j - 1) * (j - 2) / 2) % P; l <= j; l++) {
            g[i][j][k] = (g[i][j][k] + C * dfs(i, j - l, k) % P) % P;
            C = C * (j - l) % P;
        }
    } else if (j == 0) g[i][j][k] = 1;
    else g[i][j][k] = 0;
	// printf("g[%lld][%lld][%lld] = %lld\n", i, j, k, g[i][j][k]);
    return g[i][j][k];
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n), memset(g, -1, sizeof(g));
    for (int i = 0; i < n; i++) fr(d[i]);
    for (int i = n; i; i--) {
        int x = (d[i] == 2), y = x ^ 1;
        for (int j = i + 1; j <= n; j++) {
            if (j == n) f[i][j] = dfs(x, y, 0);
            else for (int k = j + 1; k <= n; k++) f[i][j] = (f[i][j] + dfs(x, y, k - j) * f[j][k] % P) % P;
            x += (d[j] == 2), y += (d[j] == 3);
        }
    }
    printf("%lld\n", f[1][1 + d[0]]);
    return 0;
}