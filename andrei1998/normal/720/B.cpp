#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

const int NMAX = 10005;
const int MMAX = 3 * NMAX;

template <const int NMAX, const int MMAX>
class MaxFLow {
public:
    MaxFLow() {}

    inline void setN(int _n) { n = _n; }
    inline void setS(int _s) { s = _s; }
    inline void setT(int _t) { t = _t; }

    inline int getN() { return n; }
    inline int getS() { return s; }
    inline int getT() { return t; }

    void clear() {
        m = 0;
        for (int i = 1; i <= n; ++ i)
            graph[i].clear();
    }

    void reset() {
        for (int i = 0; i < m; ++ i)
            edges[i].flow = 0;
    }

    void addEdge(int from, int to, int cap) {
        edges[m ++] = Edge(from, to, 0, cap);
        edges[m ++] = Edge(to, from, 0, 0);

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }

    int computeFlow() {
        return Dinic();
    }

private:
    struct Edge {
        int from, to;
        int flow, cap;

        Edge(int _from = 0, int _to = 0, int _flow = 0, int _cap = 0):
            from(_from), to(_to), flow(_flow), cap(_cap) {}
        inline int other(int node) {
            return from ^ to ^ node;
        }
    };

    int n, m, s, t;

    vector <int> graph[NMAX];
    Edge edges[2 * MMAX];

    int father[NMAX];
    bool vis[NMAX];
    queue <int> _queue;

    bool bfs() {
        memset(vis, 0, (n + 1) * sizeof(bool));

        vis[s] = true;
        _queue.push(s);

        int node;
        while (!_queue.empty()) {
            node = _queue.front();
            _queue.pop();

            for (auto it: graph[node])
                if (!vis[edges[it].other(node)] && edges[it].flow < edges[it].cap) {
                    father[edges[it].other(node)] = it;
                    vis[edges[it].other(node)] = true;
                    _queue.push(edges[it].other(node));
                }
        }

        return vis[t];
    }

    int Dinic() {
        int flow = 0;
        while (bfs()) {
            for (auto it: graph[t])
                if (vis[edges[it ^ 1].other(t)] && edges[it ^ 1].flow < edges[it ^ 1].cap) {
                    int node = edges[it ^ 1].other(t);
                    int minimum = edges[it ^ 1].cap - edges[it ^ 1].flow;

                    while (node != s) {
                        minimum = min(minimum, edges[father[node]].cap - edges[father[node]].flow);
                        node = edges[father[node]].other(node);
                    }

                    node = edges[it ^ 1].other(t);
                    edges[it ^ 1].flow += minimum;
                    edges[it].flow -= minimum;
                    flow += minimum;

                    while (node != s) {
                        edges[father[node]].flow += minimum;
                        edges[father[node] ^ 1].flow -= minimum;

                        node = edges[father[node]].other(node);
                    }
                }
        }

        return flow;
    }
};

int n, m;
vector <pair <int, int> > graph[NMAX];

int father[NMAX];
int color[NMAX];
bool used[NMAX];

bool vis[NMAX];

MaxFLow <2 * MMAX, 3 * MMAX> mf;

int cycles;
void backtrace(int node1, int node2, int c) {
    ++ cycles;

    int sz = 1;
    while (node1 != node2) {
        mf.addEdge(cycles, color[node1], 1);
        used[node1] = true;
        node1 = father[node1];

        ++ sz;
    }

    mf.addEdge(cycles, c, 1);
    mf.addEdge(mf.getS(), cycles, sz - 1);
}

int h[NMAX];

void dfs(int node) {
    vis[node] = true;
    for (auto it: graph[node])
        if (!vis[it.first]) {
            father[it.first] = node;
            color[it.first] = it.second;
            h[it.first] = 1 + h[node];
            dfs(it.first);
        }
        else if (it.first != father[node] && h[it.first] < h[node])
            backtrace(node, it.first, it.second);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m;

    int u, v, c;
    for (int i = 1; i <= m; ++ i) {
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }

    mf.setS(m + 1);
    mf.setT(m + 2);
    cycles = m + 2;

    dfs(1);

    for (int i = 2; i <= n; ++ i)
        if (!used[i]) {
            mf.addEdge(++ cycles, color[i], 1);
            mf.addEdge(mf.getS(), cycles, 1);
        }

    for (int i = 1; i <= m; ++ i)
        mf.addEdge(i, mf.getT(), 1);

    mf.setN(cycles);

    cout << mf.computeFlow() << '\n';
    return 0;
}