#include <bits/stdc++.h>

using namespace std;

namespace Dinic {
    #define sz(x) (int)(x).size()
    // indeksowany od 1
    // uzupeniamy [n, s, t] i dodajemy krawedzie
    typedef int T;
    const int N = 50'005;
    const T INF = 1e7;
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
    int n;
    scanf("%d", &n);

    vector <vector <int> > in(n);
    for (int i = 0; i < n; ++i) {
        in[i].resize(n);
        for (auto &cell: in[i]) {
            scanf("%d", &cell);
        }
    }

    vector <vector <int> > good(n);
    for (int i = 0; i < n; ++i) {
        good[i].resize(n);
        for (auto &cell: good[i]) {
            scanf("%d", &cell);
        }
    }

    int offset = n * n, sum = 0;
    int source = n * n * 2 + 1, sink = n * n * 2 + 2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Dinic::add_edge(source, i * n + j + 1, good[i][j] + n);
            Dinic::add_edge(offset + i * n + j + 1, sink, good[i][j] + n);
            Dinic::add_edge(offset + i * n + j + 1, i * n + j + 1, Dinic::INF);
            sum += good[i][j] + n;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (in[i][j] == in[i][k] - 1) {
                    Dinic::add_edge(i * n + j + 1, i * n + k + 1 + offset, Dinic::INF);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (in[i][j] == in[k][j] - 1) {
                    Dinic::add_edge(i * n + j + 1, k * n + j + 1 + offset, Dinic::INF);
                }
            }
        }
    }

    sum -= n * n;
    printf("%d\n", sum - Dinic::dinic(2 * offset + 2, source, sink));
}