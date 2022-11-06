#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

struct edge {
    int a, b;
    ldouble cap, tcap, flow;

    edge(int a, int b, ldouble tcap) : a(a), b(b), tcap(tcap) {
    }
};

const int MAXN = 50;
const lint INF = 1e18;

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge(int a, int b, int cap) {
    edge e1 = edge(a, b, cap);
    edge e2 = edge(b, a, 0);
    g[a].push_back((int) e.size());
    e.push_back(e1);
    g[b].push_back((int) e.size());
    e.push_back(e2);
}

bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i = 0; i < g[v].size(); ++i) {
            int id = g[v][i],
                    to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

ldouble dfs(int v, ldouble flow) {
    if (abs(flow) <= 1e-9) return 0;
    if (v == t) return flow;
    for (; ptr[v] < (int) g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
                to = e[id].b;
        if (d[to] != d[v] + 1) continue;
        ldouble pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

ldouble dinic() {
    ldouble flow = 0;
    for (; ;) {
        if (!bfs()) break;
        memset(ptr, 0, n * sizeof ptr[0]);
        while (ldouble pushed = dfs(s, INF))
            flow += pushed;
    }
    return flow;
}

int main() {
    sci(n);
    sciid(m, k);
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        add_edge(--x, --y, z);
    }
    s = 0;
    t = n - 1;
    ldouble l = 0, r = 1e6;
    for (int sc = 0; sc < 200; sc++) {
        ldouble md = (l + r) / 2;
        for (edge& ed : e) {
            ed.flow = 0;
            ed.cap = floor(ed.tcap / md);
        }
        ldouble flow = dinic();
        if (flow >= k) {
            l = md;
        } else {
            r = md;
        }
    }

    cout.precision(11);
    cout << fixed << l * k;

    return 0;
}