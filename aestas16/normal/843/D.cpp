#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef ONLINE_JUDGE
    #define getchar() (_S == _T && (_T = (_S = _B) + fread(_B, 1, 1 << 15, stdin), _S == _T) ? EOF : *_S++)
#endif
char _B[1 << 15], *_S = _B, *_T = _B;

template <class T> inline void fr(register T &a, register bool f = 0, register char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> inline void fr(register T &t, register Y &... a) { fr(t), fr(a...); }
inline int fr() { register int a; return fr(a), a; }

const int N = 1e5, M = 1e5, INF = 0x3f3f3f3f3f3f3f3f;

int n, m, _, dis[N + 10], add[N + 10];
bool vis[N + 10];
queue<int> Q[N + 10];

namespace Edges {
    struct Edge { int to, nxt, val; } e[M + 10];
    int hd[N + 10], etot;
    inline void adde(register int x, register int y, register int z) { e[++etot] = {y, hd[x], z}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

struct Node {
    int val, u;
    inline bool operator<(register const Node &a) const { return val > a.val; }
};

namespace Heap {
    template <class T> struct heap {
        T h[N + (M << 1) + 10];
        int sz;
        inline void push(register T x) { h[++sz] = x, std::push_heap(h + 1, h + sz + 1); }
        inline void pop() { std::pop_heap(h + 1, h + sz + 1), sz--; }
        inline T top() { return h[1]; }
        inline int size() { return sz; }
    };
} // namespace Heap
using namespace Heap;
heap<Node> q;

void Dijkstra() {
    memset(dis, 0x3f, sizeof(dis)), memset(vis, 0, sizeof(vis)), q.push({0, 1}), dis[1] = 0;
    while (q.size()) {
        register int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (register int i = hd[u]; i; i = e[i].nxt) {
            register int v = e[i].to, w = e[i].val;
            if (dis[u] + w < dis[v]) q.push({dis[v] = dis[u] + w, v});
        }
    }
}

void bfs(int _) {
    memset(add, 0x3f, sizeof(add)), add[1] = 0, Q[0].push(1);
    for (int k = 0; k <= _; k++) {
        while (Q[k].empty() == 0) {
            int u = Q[k].front(); Q[k].pop();
            if (add[u] != k) continue;
            for (int i = hd[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if (dis[u] + add[u] + e[i].val < dis[v] + add[v]) {
                    add[v] = dis[u] + add[u] + e[i].val - dis[v];
                    if (add[v] <= _) Q[add[v]].push(v);
                }
            }
        }
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n, m, _);
    for (register int i = 1, x, y, z; i <= m; i++) fr(x, y, z), adde(x, y, z);
    Dijkstra();
    for (register int i = 1; i <= _; i++) {
        register int opt = fr();
        if (opt == 1) {
            register int u = fr();
            printf("%lld\n", dis[u] == INF ? -1 : dis[u]);
        } else {
            register int c = fr();
            for (register int j = 1; j <= c; j++) e[fr()].val++;
            bfs(min(n - 1, c));
            for (register int j = 1; j <= n; j++)
                if (dis[j] != INF && add[j] != INF) dis[j] += add[j];
        }
    }
    return 0;
}