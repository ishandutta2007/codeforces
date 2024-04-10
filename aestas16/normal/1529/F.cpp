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

const int N = 6e2, M = N * N;

int n, m, e[N + 10][N + 10], dis[N + 10][N + 10];
bool vis[N + 10];

struct Node {
    int val, u;
    bool operator < (const Node &rhs) const { return val > rhs.val; }
};

namespace Heap {
    template <class T> struct heap {
        T h[M + 10];
        int sz;
        void push(T x) { h[++sz] = x, std::push_heap(h + 1, h + sz + 1); }
        void pop() { std::pop_heap(h + 1, h + sz + 1), sz--; }
        void clear() { sz = 0; }
        T top() { return h[1]; }
        int size() { return sz; }
        int empty() { return sz & 1; }
    };
} // namespace Heap
using namespace Heap;
heap<Node> q;

void Dijkstra(int s) {
    memset(dis[s], 0x3f, sizeof(dis[s])), memset(vis, 0, sizeof(vis)), q.clear(), q.push({0, s}), dis[s][s] = 0;
    while (q.size()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < n; i++) {
            int v = (i + dis[s][u]) % n, w = e[u][i];
            if (dis[s][u] + w < dis[s][v]) q.push({dis[s][v] = dis[s][u] + w, v});
        }
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(m), memset(e, 0x7f, sizeof(e));
    for (int i = 1, u, v, w; i <= m; i++) {
        fr(u), fr(v), fr(w);
        for (int j = 0; j < n; j++) e[u][(v + j) % n] = min(e[u][(v + j) % n], w + j);
    }
    for (int i = 0; i < n; i++) Dijkstra(i);
    for (int i = 0; i < n; i++, puts(""))
        for (int j = 0; j < n; j++) printf("%lld ", dis[i][j]);
    return 0;
}