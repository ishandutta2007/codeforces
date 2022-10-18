/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 3e5;

int n, timer, ans, dfn[N + 10], sz[N + 10];

namespace Edges {
    struct Edge {
        int to, nxt;
    } e[2][(N << 1) + 10];
    int etot[2] = {1, 1}, hd[2][N + 10];
    void adde(int op, int x, int y) { e[op][++etot[op]] = {y, hd[op][x]}, hd[op][x] = etot[op]; }
} // namespace Edges
using namespace Edges;

namespace BIT {
    int c[N + 10];
    int lowbit(int x) { return x & (-x); }
    int query(int pos) {
        int ret = 0;
        for (int i = pos; i; i -= lowbit(i)) ret += c[i];
        return ret;
    }
    void update(int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) c[i] += val;
    }
    void modify(int l, int r, int val) { update(l, val), update(r + 1, -val); }
} // namespace BIT
using namespace BIT;

void dfs1(int u, int p) {
    sz[u] = 1, dfn[u] = ++timer;
    for (int i = hd[1][u]; i; i = e[1][i].nxt) {
        int v = e[1][i].to;
        if (v == p) continue;
        dfs1(v, u), sz[u] += sz[v];
    }
}

void dfs2(int u, int p, int cnt = 0) {
    int id = query(dfn[u]);
    if (id) modify(dfn[id], dfn[id] + sz[id] - 1, -id);
    else cnt++;
    ans = max(ans, cnt), modify(dfn[u], dfn[u] + sz[u] - 1, u);
    for (int i = hd[0][u]; i; i = e[0][i].nxt) {
        int v = e[0][i].to;
        if (v == p) continue;
        dfs2(v, u, cnt);
    }
    modify(dfn[u], dfn[u] + sz[u] - 1, -u);
    if (id) modify(dfn[id], dfn[id] + sz[id] - 1, id);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T; T--) {
        fr(n), etot[0] = etot[1] = 1, timer = ans = 0;
        for (int i = 1; i <= n; i++) hd[0][i] = hd[1][i] = 0;
        for (int i = 2, fa; i <= n; i++) fr(fa), adde(0, fa, i), adde(0, i, fa);
        for (int i = 2, fa; i <= n; i++) fr(fa), adde(1, fa, i), adde(1, i, fa);
        dfs1(1, 0), dfs2(1, 0), printf("%lld\n", ans);
    }
    return 0;
}