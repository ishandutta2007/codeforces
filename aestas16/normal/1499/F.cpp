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

const int N = 5e3, P = 998244353;

int n, k, ans, f[N + 10][N + 10], sz[N + 10], dep[N + 10] = {-1}, g[N + 10], mx[N + 10];
vector<int> e[N + 10];

void adde(int x, int y) { e[x].push_back(y); }

void dfs(int u, int p) {
    sz[u] = 1, mx[u] = dep[u] = dep[p] + 1, f[u][0] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u); int up = mx[u] - dep[u];
        for (int i = 0; i <= max(mx[u], mx[v]) - dep[u]; i++) g[i] = 0;
        for (int i = 0; i <= up; i++)
            for (int j = 0; j <= mx[v] - dep[u]; j++) {
                g[i] = (g[i] + f[u][i] * f[v][j] % P) % P;
                if (i + j + 1 > k) continue;
                g[max(i, j + 1)] = (g[max(i, j + 1)] + f[u][i] * f[v][j] % P) % P;
            }
        mx[u] = max(mx[u], mx[v]), sz[u] += sz[v];
        for (int i = 0; i <= mx[u] - dep[u]; i++) f[u][i] = g[i];
    }
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, k);
    for (int i = 1, x, y; i < n; i++) fr(x, y), adde(x, y), adde(y, x);
    dfs(1, 0);
    for (int i = 0; i <= k; i++) ans = (ans + f[1][i]) % P;
    return printf("%lld\n", ans), 0;
}