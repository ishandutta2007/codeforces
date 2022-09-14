#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

const double EPS = 1e-9;
const int MAXCAP = 1 << 20;

vector<int> dx{1, 0, -1, 0};
vector<int> dy{0, 1, 0, -1};

struct Edge {
    long long cap;
    long long flow;
    int to;
};

vector<Edge> allEdges;
vector< vector<int> > edge;
vector<int> vis;

long long findFlow(int v, int t, long long a) {
    vis[v] = 1;
    if (v == t)
        return a;
    for (int i = 0; i < edge[v].size(); ++i) {
        Edge cur = allEdges[edge[v][i]];
        if (vis[cur.to] == 0 && cur.cap - cur.flow >= a) {
            long long flow = findFlow(cur.to, t, a);
            if (flow != 0) {
                allEdges[edge[v][i]].flow += flow;
                allEdges[edge[v][i] ^ 1].flow -= flow;
                return flow;
            }
        }
    }
    return 0;
}

long long maxFlow(int s, int t, int n, long long x) {
    long long ans = 0;
    for (long long a = MAXCAP; a > 0; a /= 2) {
        long long flow;
        vis = vector<int>(n, 0);
        while ((flow = findFlow(s, t, a * x)) > 0) {
            ans += flow;
            vis = vector<int>(n, 0);
        }
    }
    return ans;
}


vector<long long> c;

void addEdge(int u, int v, long long cap) {
    allEdges.push_back(Edge{cap, 0, v});
    edge[u].push_back((int)allEdges.size() - 1);
    c.push_back(cap);
    allEdges.push_back(Edge{0, 0, u});
    edge[v].push_back((int)allEdges.size() - 1);
    c.push_back(0);
}



int main() {
    int n, m, x;
    cin >> n >> m >> x;
    edge.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        double c;
        cin >> u >> v >> c;
        u--; v--;
        addEdge(u, v, c);
    }
    
    double l = EPS;
    double r = 1e12;
    for (int i = 0; i < 100; ++i) {
        double m = (l + r) / 2;
        for (int j = 0; j < allEdges.size(); j++) {
            allEdges[j].flow = 0;
            allEdges[j].cap = trunc(c[j] / m);
        }
        long long flow = maxFlow(0, n - 1, n, 1);
        if (flow >= x)
            l = m;
        else
            r = m;
    }
    printf("%.10lf\n", (double)l * x);
    return 0;
}