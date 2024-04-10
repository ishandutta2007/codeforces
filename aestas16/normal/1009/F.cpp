// 392699

#include <bits/stdc++.h>

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

const int N = 1e6;

int n, mem[N + 10], *atot = mem, *f[N + 10], ht[N + 10], ch[N + 10], ans[N + 10];
vector<int> e[N + 10];

void adde(int x, int y) { e[x].push_back(y); }

void dfs1(int u, int p) {
    ht[u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs1(v, u), ht[u] = max(ht[u], ht[v] + 1);
        if (ht[ch[u]] < ht[v]) ch[u] = v;
    }
}

void dfs(int u, int p) {
    if (f[u] == 0) f[u] = atot, atot += ht[u];
    f[u][0] = 1;
    if (ch[u]) f[ch[u]] = f[u] + 1, dfs(ch[u], u), ans[u] = ans[ch[u]] + 1;
    for (auto v : e[u]) {
        if (v == p || v == ch[u]) continue;
        dfs(v, u);
        for (int i = 1; i <= ht[v]; i++) {
            f[u][i] += f[v][i - 1];
            if (f[u][i] > f[u][ans[u]]) ans[u] = i;
            if (f[u][i] == f[u][ans[u]] && i < ans[u]) ans[u] = i;
        }
    }
    if (f[u][ans[u]] == 1) ans[u] = 0;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n);
    for (int i = 1, u, v; i < n; i++) fr(u, v), adde(u, v), adde(v, u);
    dfs1(1, 0), dfs(1, 0);
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}