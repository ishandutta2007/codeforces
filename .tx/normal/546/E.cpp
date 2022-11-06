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

int a[111];
int b[111];

struct edge {
    int from, to, c, f;
};

vector<int> g[222];
vector<edge> edges;

void add_edge(int u, int v, int cap) {
    g[u].push_back(edges.size());
    edges.push_back(edge{u, v, cap, 0});
    g[v].push_back(edges.size());
    edges.push_back(edge{v, u, 0, 0});
}

int n, t;
vector<int> d;

void bfs(int s) {
    d.assign(2 * n + 2, 1e9);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i : g[v]) {
            edge& e = edges[i];
            if (e.c - e.f > 0 && d[e.to] > d[v] + 1) {
                d[e.to] = d[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int ptr[222];

int dfs(int v, int flow) {
    if (v == t) {
        return flow;
    }
    for (; ptr[v] < g[v].size(); ptr[v]++) {
        int i = g[v][ptr[v]];
        edge& e = edges[i];
        if (d[e.to] == d[v] + 1 && e.c - e.f > 0) {
            int pushed = dfs(e.to, min(flow, e.c - e.f));
            if (pushed != 0) {
                e.f += pushed;
                edges[i ^ 1].f -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int ans[222][222];

int main() {
    sci(n);
    scid(m);
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        sa += a[i];
    }
    for (int i = 0; i < n; i++) {
        sci(b[i]);
        sb += b[i];
    }
    if (sa != sb) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        add_edge(x, y + n, 1e9);
        add_edge(y, x + n, 1e9);
    }
    for (int i = 0; i < n; i++) {
        add_edge(i + 1, i + n + 1, 1e9);
        add_edge(0, i + 1, a[i]);
        add_edge(i + 1 + n, 2 * n + 1, b[i]);
    }

    int flow = 0;
    t = 2 * n + 1;
    while (true) {
        bfs(0);
        if (d[t] == 1e9) {
            break;
        }
        memset(ptr, 0, sizeof(ptr));
        int pushed;
        while ((pushed = dfs(0, 1e9)) != 0) {
            flow += pushed;
        }
    }

    if (flow != sa) {
        cout << "NO";
        return 0;
    }

    for (edge& e : edges) {
        if (e.from == 0 || e.to == t || e.from > e.to) {
            continue;
        }
        ans[e.from - 1][e.to - n - 1] = e.f;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}