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

const int N = 2e5;

int ans[N + 10];
vector<int> e[N + 10];

void adde(int u, int v) { e[u].push_back(v); }

namespace TreeLink {
    int timer, sz[N + 10], dfn[N + 10], fa[N + 10], dep[N + 10], ltop[N + 10], ch[N + 10];
    void dfs1(int u, int p) {
        sz[u] = 1, fa[u] = p, dep[u] = dep[p] + 1, ch[u] = -1;
        for (auto v : e[u]) {
            if (v == p) continue;
            dfs1(v, u), sz[u] += sz[v];
            if (ch[u] == -1 || sz[v] > sz[ch[u]]) ch[u] = v;
        }
    }
    void dfs2(int u, int p) {
        dfn[u] = ++timer, ltop[u] = p;
        if (ch[u] == -1) return;
        dfs2(ch[u], p);
        for (auto v : e[u]) {
            if (v == fa[u] || v == ch[u]) continue;
            dfs2(v, v);
        }
    }
    int lca(int u, int v) {
        while (ltop[u] != ltop[v]) {
            if (dep[ltop[u]] < dep[ltop[v]]) swap(u, v);
            u = fa[ltop[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        return u;
    }
} // namespace TreeLink
using namespace TreeLink;

bool isinsubtree(int u, int v) { return dfn[u] <= dfn[v] && dfn[v] <= dfn[u] + sz[u] - 1; }

int getsz(int u) {
    for (auto i : e[0])
        if (isinsubtree(i, u)) return sz[i];
    return 0;
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    for (int _ = fr(); _--;) {
        int n = fr(), l = -1, r = -1, sum = 1; timer = 0;
        for (int i = 0; i <= n; i++) e[i].clear(), ans[i] = 0;
        for (int i = 1, x, y; i < n; i++) fr(x, y), adde(x, y), adde(y, x);
        dfs1(0, 0), dfs2(0, 0);
        for (auto i : e[0]) sum += sz[i];
        for (auto i : e[0]) ans[0] += sz[i] * (sum - sz[i]), sum -= sz[i];
        for (int i = 1, szl; i < n; i++) {
            // printf("%d %d\n", l, r);
            if (l == -1) l = i, szl = getsz(l);
            else if (isinsubtree(l, i)) l = i;
            else if (isinsubtree(i, l)) goto cat;
            else if (r == -1) {
                if (lca(l, i) == 0) r = i;
                else break;
            } else if (isinsubtree(r, i)) r = i;
            else if (isinsubtree(i, r) == 0) break;
            cat:;
            // printf("%d %d\n", l, r);
            if (r == -1) ans[i] = sz[l] * (n - szl);
            else ans[i] = sz[l] * sz[r];
        }
        // for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
        printf("%lld ", n * (n - 1) / 2 - ans[0]);
        for (int i = 1; i <= n; i++) printf("%lld%c", ans[i - 1] - ans[i], " \n"[i == n]);
    }
    return 0;
}