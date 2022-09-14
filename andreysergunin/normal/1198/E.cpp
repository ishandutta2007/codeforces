#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

struct Rect {
    int x1, y1, x2, y2;
};

bool inside(const Rect &r, int x, int y) {  
    return (r.x1 <= x) && (x <= r.x2) && (r.y1 <= y) && (y <= r.y2);
}

const int INF = 2e9;

class Dinic {
public: 
    Dinic(): n(0) {};

    Dinic(int k, bool dir) {
        n = k;
        direct = dir;
        g.resize(n);
    }

    void addOneEdge(int u, int v, int cap) {
        g[u].push_back(sz(edges));
        edges.push_back(Edge{u, v, cap, 0});
    }

    void addEdge(int u, int v, int cap) {
        addOneEdge(u, v, cap);
        addOneEdge(v, u, direct ? 0 : cap);
    }

    long long maxFlow(int s, int t) {
        long long ans = 0;
        vector<int> dist(n);
        while (bfs(s, t, dist)) {
            int flow = 0;
            vector<int> ptr(n);
            while ((flow = dfs(s, t, dist, ptr, INF)) > 0) 
                ans += (long long)flow;
        }
        return ans;
    }

    void clear() {
        for (int i = 0; i < sz(edges); ++i)
            edges[i].flow = 0;
    }

private:
    bool bfs(int s, int t, vector<int> &dist) {
        queue<int> q;
        dist.assign(sz(dist), -1);
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int cur = q.front();
            for (auto e : g[cur]) {
                if (dist[edges[e].to] == -1 && edges[e].cap > edges[e].flow) {
                    q.push(edges[e].to);
                    dist[edges[e].to] = dist[cur] + 1;
                }
            }
            q.pop();
        }
        return (dist[t] >= 0);
    }

    int dfs(int v, int t, vector<int> &dist, vector<int> &ptr, int maxFlow) {
        if (v == t)
            return maxFlow;
        for (int i = ptr[v]; i < sz(g[v]); ++i) {
            int e = g[v][i];
            if (dist[v] + 1 == dist[edges[e].to] && edges[e].cap - edges[e].flow > 0) {
                int curFlow = min(maxFlow, edges[e].cap - edges[e].flow);
                int flow = dfs(edges[e].to, t, dist, ptr, curFlow);
                if (flow > 0) {
                    edges[e].flow += flow;
                    edges[e ^ 1].flow -= flow;
                    return flow;
                }
            }
            ++ptr[v];
        }
        return 0;
    }

    struct Edge {
        int from;
        int to;
        int cap;
        int flow;
    };

    int n;
    bool direct;
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> pos;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  

    int n, tmp;
    cin >> tmp >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<Rect> r(n);
    vector<int> x, y;
    for (int i = 0; i < n; ++i) {
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
        x.push_back(r[i].x1);
        x.push_back(r[i].x2 + 1);
        y.push_back(r[i].y1);
        y.push_back(r[i].y2 + 1);
    }

    sort(all(x));
    x.resize(unique(all(x)) - x.begin());

    sort(all(y));
    y.resize(unique(all(y)) - y.begin());

    int m1 = sz(x) - 1;
    int m2 = sz(y) - 1;

    Dinic net(m1 + m2 + 2, 1);

    int source = m1 + m2;
    int target = m1 + m2 + 1;

    for (int i = 0; i < m1; ++i) {
        net.addEdge(source, i, x[i + 1] - x[i]);
    } 
    for (int i = 0; i < m2; ++i) {
        net.addEdge(i + m1, target, y[i + 1] - y[i]);
    }    

    for (int i = 0; i < m1; ++i) {
        for (int j = 0; j < m2; ++j) {
            bool flag = false;
            for (int k = 0; k < n; ++k) {
                flag |= inside(r[k], x[i], y[j]);
            }

            if (flag) {
                net.addEdge(i, j + m1, INF);
            }   
        }
    }

    cout << net.maxFlow(source, target) << endl;

}