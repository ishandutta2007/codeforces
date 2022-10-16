#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

template <const int NMAX, const int MMAX>
class MaxFLow {
public:
    MaxFLow() { m = 0; }

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

    int addEdge(int from, int to, int cap) {
        edges[m ++] = Edge(from, to, 0, cap);
        edges[m ++] = Edge(to, from, 0, 0);

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);

        return m - 2;
    }

    inline int computeFlow() {
        return Dinic();
    }

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

			if (node == t)
				continue;

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

const int NMAX = 5000 + 5;
const int MMAX = 5000 + 5;
MaxFLow <7 * NMAX, 7 * MMAX> f;

int n, m;
int edgeA[MMAX];
int edgeB[MMAX];
int x[MMAX];

bool works(int LIM, bool print = false) {
    f.clear();
    f.setN(n + m + 2);
    f.setS(n + m + 1);
    f.setT(n + m + 2);

    int S = n + m + 1;
    int T = n + m + 2;

    for (int i = 1; i <= m; ++ i) {
        int a = edgeA[i];
        int b = edgeB[i];
        x[i] = f.addEdge(i, m + a, 1);
        f.addEdge(i, m + b, 1);
        f.addEdge(S, i, 1);
    }
    for (int i = 1; i <= n; ++ i)
        f.addEdge(m + i, T, LIM);

    if (f.computeFlow() == m) {
        if (print) {
            for (int i = 1; i <= m; ++ i)
                if (f.edges[x[i]].flow == 1)
                    cout << edgeA[i] << ' ' << edgeB[i] << '\n';
                else
                    cout << edgeB[i] << ' ' << edgeA[i] << '\n';
        }
        return true;
    }
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; ++ i) {
        cin >> a >> b;
        edgeA[i] = a;
        edgeB[i] = b;
    }

    int st = 0;
    int dr = n;
    int ans = dr + 1;

    while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (works(mid)) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    cout << ans << '\n';
    works(ans, true);
    return 0;
}