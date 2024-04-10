#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

typedef long long int lint;

template <int NMAX, int MMAX>
class MaxFlowMinCost {
public:
    MaxFlowMinCost() { m = 0; }

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

    void addEdge(int from, int to, int cap, int cost) {
        edges[m ++] = Edge(from, to, 0, cap, cost);
        edges[m ++] = Edge(to, from, 0, 0, -cost);

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }

    inline pair <int, lint> computeFlow() {
        return JohnsonDinic();
    }
private:
    struct Edge {
        int from, to;
        int flow, cap, cost;

        Edge(int _from = 0, int _to = 0, int _flow = 0, int _cap = 0, int _cost = 0):
            from(_from), to(_to), flow(_flow), cap(_cap), cost(_cost) {}
        inline int other(int node) {
            return from ^ to ^ node;
        }
    };

    int n, m, s, t;

    vector <int> graph[NMAX];
    Edge edges[2 * MMAX];

    const lint INF = 1E18 + 15;

    lint dist[NMAX];
    int father[NMAX];
    bool vis[NMAX];
    lint potentials[NMAX];
    priority_queue <pair <lint, int> > _queue;

    bool Dijkstra() {
        memset(vis, 0, (n + 1) * sizeof(bool));
        for (int i = 1; i <= n; ++ i)
            dist[i] = INF;

        dist[s] = 0;
        _queue.push(make_pair(0, s));

        int node;
        while (!_queue.empty()) {
            node = _queue.top().second;
            _queue.pop();

            if (vis[node])
                continue;
            vis[node] = true;

            for (auto edge: graph[node]) {
                int other = edges[edge].other(node);
                int cost = edges[edge].cost + potentials[node] - potentials[other];

                if (edges[edge].flow < edges[edge].cap && dist[node] + cost < dist[other]) {
                    dist[other] = dist[node] + cost;
                    father[other] = edge;
                    _queue.push(make_pair(-dist[other], other));
                }
            }
        }

        for (int i = 1; i <= n; ++ i)
            dist[i] += (potentials[i] - potentials[s]);

        return vis[t];
    }

    pair <int, lint> JohnsonDinic() {
        memset(potentials, 0, (n + 1) * sizeof(lint));
        Dijkstra();

        int flow = 0;
        lint cost = 0;
        while (Dijkstra()) {
            int node = t;
            int minimum = 1E9 + 15;
            lint sum = 0;

            while (node != s) {
                minimum = min(minimum, edges[father[node]].cap - edges[father[node]].flow);
                sum += edges[father[node]].cost;
                node = edges[father[node]].other(node);
            }

            node = t;
            while (node != s) {
                edges[father[node]].flow += minimum;
                edges[father[node] ^ 1].flow -= minimum;
                node = edges[father[node]].other(node);
            }

            flow += minimum;
            cost += minimum * sum;

            memcpy(potentials, dist, (n + 1) * sizeof(int));
        }

        return make_pair(flow, cost);
    }
};

const int NMAX = 5000 + 5;
const int MMAX = 4 * NMAX;

MaxFlowMinCost <NMAX, 2 * MMAX> f;

int N, K;
int a[NMAX];
int b[NMAX];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];
    for (int i = 1; i <= N; ++ i)
        cin >> b[i];

    f.addEdge(2 * N + 1, 2 * N + 2, K, 0);

    for (int i = 1; i <= N; ++ i)
        f.addEdge(2 * N + 2, i, 1, a[i]);
    for (int i = N + 1; i <= 2 * N; ++ i)
        f.addEdge(i, 2 * N + 3, 1, b[i - N]);

    for (int i = 1; i <= N; ++ i)
        f.addEdge(i, N + i, 1, 0);
    for (int i = N + 1; i < 2 * N; ++ i)
        f.addEdge(i, i + 1, K, 0);

    f.setS(2 * N + 1);
    f.setT(2 * N + 3);
    f.setN(2 * N + 3);

    cout << f.computeFlow().second << '\n';
    return 0;
}