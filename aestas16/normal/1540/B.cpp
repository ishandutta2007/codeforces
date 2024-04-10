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

const int N = 2e2, M = 8, P = 1e9 + 7, inv2 = (P + 1) / 2;

int n, timer, ans, dep[N + 10], dfn[N + 10], efn[(N << 1) + 10][M + 3], lg2[(N << 1) + 10], f[N + 5][N + 5];
vector<int> e[N + 10];

void adde(int x, int y) { e[x].push_back(y); }

void dfs(int u, int p) {
    dep[u] = dep[p] + 1, dfn[u] = ++timer, efn[timer][0] = u;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u), efn[++timer][0] = u;
    }
}
int cmin(int a, int b) { return dep[a] < dep[b] ? a : b; }
void InitST() {
    for (int i = 2; i <= timer; i++) lg2[i] = lg2[i >> 1] + 1;
    for (int j = 1; j <= lg2[timer]; j++)
        for (int i = 1; i + (1 << j) - 1 <= timer; i++) efn[i][j] = cmin(efn[i][j - 1], efn[i + (1 << (j - 1))][j - 1]);
}
int lca(int u, int v) {
    int l = dfn[u], r = dfn[v];
    if (l > r) swap(l, r);
    int s = lg2[r - l + 1];
    return cmin(efn[l][s], efn[r - (1 << s) + 1][s]);
}

int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1, x, y; i < n; i++) fr(x, y), adde(x, y), adde(y, x);
    for (int i = 1; i <= n; i++) f[0][i] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = (f[i - 1][j] + f[i][j - 1]) * inv2 % P;
    for (int rt = 1; rt <= n; rt++) {
        timer = 0, dfs(rt, 0), InitST();
        for (int i = 1; i <= n; i++) for (int j = 1, k; j < i; j++) k = lca(i, j), ans = (ans + f[dep[i] - dep[k]][dep[j] - dep[k]]) % P;
    }
    return printf("%lld\n", ans * qpow(n, P - 2) % P), 0;
}