/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

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

const int N = 5e5;

int n, q;

namespace ChthollyTree {
    #define it set<Node>::iterator

    struct Node {
        mutable int l, r, v;
        Node(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
        bool operator < (const Node &rhs) const { return l < rhs.l; }
    };
    set<Node> s;

    it split(int pos) {
        it p = s.lower_bound(Node(pos));
        if (p != s.end() && p->l == pos) return p;
        p--;
        int l = p->l, r = p->r, v = p->v;
        return s.erase(p), s.insert(Node(l, pos - 1, v)), s.insert(Node(pos, r, v)).first;
    }
    void assign(int l, int r, int v) {
        it pr = split(r + 1), pl = split(l);
        s.erase(pl, pr), s.insert(Node(l, r, v));
    }
    int qpos(int pos) { return split(pos)->v; }
} // namespace ChthollyTree
using namespace ChthollyTree;

namespace Edges {
    struct Edge {
        int to, nxt;
    } e[(N << 1) + 10];
    int etot = 1, hd[N + 10];
    void adde(int x, int y) { e[++etot] = {y, hd[x]}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

namespace TreeLink {
    int timer, sz[N + 10], fa[N + 10], dep[N + 10], top[N + 10], ch[N + 10], dfn[N + 10];
    void dfs1(int u, int p) {
        sz[u] = 1, fa[u] = p, dep[u] = dep[p] + 1;
        for (int i = hd[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (v == p) continue;
            dfs1(v, u), sz[u] += sz[v];
            if (sz[v] > sz[ch[u]]) ch[u] = v;
        }
    }
    void dfs2(int u, int p) {
        top[u] = p, dfn[u] = ++timer;
        if (ch[u] == 0) return;
        dfs2(ch[u], p);
        for (int i = hd[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (v == fa[u] || v == ch[u]) continue;
            dfs2(v, v);
        }
    }
    void modify(int u, int v, int x) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            assign(dfn[top[u]], dfn[u], x), u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        assign(dfn[u], dfn[v], x);
    }
} // namespace TreeLink
using namespace TreeLink;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), s.insert(Node(1, n, 0));
    for (int i = 1, u, v; i < n; i++) fr(u), fr(v), adde(u, v), adde(v, u);
    dfs1(1, 0), dfs2(1, 1), fr(q);
    for (int i = 1, opt, u; i <= q; i++) {
        fr(opt), fr(u);
        if (opt == 1) assign(dfn[u], dfn[u] + sz[u] - 1, 1);
        else if (opt == 2) modify(1, u, 0);
        else printf("%d\n", qpos(dfn[u]));
    }
    return 0;
}