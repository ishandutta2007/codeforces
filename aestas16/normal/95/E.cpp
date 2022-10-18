#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e5, INF = 0x3f3f3f3f;

int n, m, tot, atot, TOT, ans = INF, a[N + 10], arr[N + 10], cnt[N + 10], f[2][N + 10], A[N + 10], B[N + 10];
vector<int> e[N + 10];
bool vis[N + 10];

void adde(int x, int y) { e[x].push_back(y); }

void dfs(int u) {
    if (vis[u]) return ;
    a[tot]++, vis[u] = 1;
    for (auto v : e[u]) dfs(v);
}

bool chk(int u) {
    while (u) {
        if (u % 10 != 4 && u % 10 != 7) return 0;
        u /= 10;
    }
    return 1;
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n, m), memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 1, u, v; i <= m; i++) fr(u, v), adde(u, v), adde(v, u);
    for (int i = 1; i <= n; i++) if (vis[i] == 0) tot++, dfs(i), cnt[a[tot]]++;
    sort(a + 1, a + 1 + tot), tot = unique(a + 1, a + 1 + tot) - a - 1;
    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= cnt[a[i]]; j <<= 1) TOT++, A[TOT] = j * a[i], B[TOT] = j, cnt[a[i]] -= j;
        if (cnt[a[i]]) TOT++, A[TOT] = cnt[a[i]] * a[i], B[TOT] = cnt[a[i]];
    }
    for (int i = 1, up = 0; i <= TOT; i++) {
        memcpy(f[i & 1], f[(i - 1) & 1], sizeof(f[i & 1]));
        for (int j = 0; j <= up; j++) f[i & 1][A[i] + j] = min(f[i & 1][A[i] + j], f[(i - 1) & 1][j] + B[i]);
        up += A[i];
    }
    for (int i = 1; i <= n; i++)
        if (chk(i)) ans = min(ans, f[TOT & 1][i] - 1);
    return printf("%d\n", ans >= n ? -1 : ans), 0;
}