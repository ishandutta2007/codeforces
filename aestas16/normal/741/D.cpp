#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 5e5;

int n, timer, ans[N + 10], a[N + 10], dis[N + 10], dep[N + 10], book[(1 << 22) + 10], arr[N + 10], ifn[N + 10], ofn[N + 10], sz[N + 10], ch[N + 10];
vector<int> e[N + 10];

void adde(int x, int y) { e[x].push_back(y); }

void dfs1(int u, int p) {
    ifn[u] = ++timer, arr[timer] = u, sz[u] = 1, dis[u] = dis[p] ^ a[u], dep[u] = dep[p] + 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs1(v, u), sz[u] += sz[v];
        if (sz[v] > sz[ch[u]]) ch[u] = v;
    }
    ofn[u] = timer;
}
void dfs2(int u, int p, bool f) {
    for (auto v : e[u]) {
        if (v == p || v == ch[u]) continue;
        dfs2(v, u, 0), ans[u] = max(ans[u], ans[v]);
    }
    if (ch[u]) dfs2(ch[u], u, 1), ans[u] = max(ans[u], ans[ch[u]]);
    if (book[dis[u]]) ans[u] = max(ans[u], book[dis[u]] - dep[u]);
    for (int i = 0; i < 22; i++) if (book[dis[u] ^ (1 << i)]) ans[u] = max(ans[u], book[dis[u] ^ (1 << i)] - dep[u]);
    book[dis[u]] = max(book[dis[u]], dep[u]);
    for (auto v : e[u]) {
        if (v == p || v == ch[u]) continue;
        for (int i = ifn[v]; i <= ofn[v]; i++) {
            int x = arr[i];
            if (book[dis[x]]) ans[u] = max(ans[u], dep[x] + book[dis[x]] - dep[u] * 2);
            for (int i = 0; i < 22; i++) if (book[dis[x] ^ (1 << i)]) ans[u] = max(ans[u], dep[x] + book[dis[x] ^ (1 << i)] - dep[u] * 2);
        }
        for (int i = ifn[v]; i <= ofn[v]; i++) {
            int x = arr[i];
            book[dis[x]] = max(book[dis[x]], dep[x]);
        }
    }
    if (f == 0)
        for (int i = ifn[u]; i <= ofn[u]; i++) {
            int v = arr[i];
            book[dis[v]] = 0;
        }
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 2, p; i <= n; i++) fr(p), adde(i, p), adde(p, i), a[i] = (1 << (getchar() - 'a'));
    dfs1(1, 0), dfs2(1, 0, 1);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}