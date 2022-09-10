#include <bits/stdc++.h>

using namespace std;

namespace Dinic {
    #define sz(x) (int)(x).size()
    // indeksowany od 1
    // uzupeniamy [n, s, t] i dodajemy krawedzie
    typedef long long T;
    const int N = 2005;
    const T INF = 1'001'002'003'004'005'006LL;
    struct edge {
        int a, b;
        T cap, flow;
    };
    int n, s, t, d[N], ptr[N], q[N];
    vector < edge > e;
    vector < int > g[N];
    void clear() {
        e.clear();
        for(int i = 1; i <= n; ++i)
            g[i].clear();
    }
    /* Edges can be added only using add_edge to use this function! */
    void clear_flow() {
        for(int i = 0; i < (int)e.size(); i += 2)
            e[i].flow = 0, e[i + 1].flow = e[i + 1].cap;
    }
    int add_edge(int a, int b, T cap) {
        edge e1 = { a, b, cap, 0 };
        edge e2 = { b, a, cap, cap };
        g[a].push_back(sz(e));
        e.push_back(e1);
        g[b].push_back(sz(e));
        e.push_back(e2);
        return sz(e) - 2;
    }
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        memset(d + 1, -1, n * sizeof d[0]);
        d[s] = 0;
        while(qh < qt && d[t] == -1) {
            int v = q[qh++];
            for(int i = 0; i < sz(g[v]); ++i) {
                int id = g[v][i], to = e[id].b;
                if(d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }
    T dfs(int v, T flow) {
        if(flow <= 0)  return 0;
        if(v == t)  return flow;
        T res = 0;
        for(; ptr[v]<sz(g[v]); ++ptr[v]) {
            int id = g[v][ptr[v]], to = e[id].b;
            if(d[to] != d[v] + 1) continue;
            T pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            res += pushed;
            flow -= pushed;
            if(flow == 0) break;
        }
        return res;
    }
    T dinic(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        T flow = 0;
        for (;;) {
            if(!bfs())  break;
            memset(ptr, 0, (n + 1) * sizeof ptr[0]);
            flow += dfs(s, INF);
        }
        return flow;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a, b;
    scanf("%d %d", &a, &b);

    Dinic::add_edge(n + n + 1, a, Dinic::INF);
    Dinic::add_edge(a + n, n + n + 2, Dinic::INF);

    Dinic::add_edge(n + n + 1, n + b, Dinic::INF);
    Dinic::add_edge(b, n + n + 2, Dinic::INF);

    while (m--) {
        int u, v, l;
        scanf("%d %d %d", &u, &v, &l);

        Dinic::add_edge(u, n + v, l);
        Dinic::add_edge(n + u, v, l);

        Dinic::add_edge(v, n + u, l);
        Dinic::add_edge(n + v, u, l);
    }

    printf("%lld\n", Dinic::dinic(n + n + 2, n + n + 1, n + n + 2));
    for (int i = 1; i <= n; ++i) {
        if (Dinic::d[i] != -1 && Dinic::d[n + i] == -1) {
            printf("A");
        } else if (Dinic::d[i] == -1 && Dinic::d[n + i] != -1) {
            printf("B");
        } else {
            printf("C");
        }
    }

    puts("");
    return 0;
}