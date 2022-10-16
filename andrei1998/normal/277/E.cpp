#include <bits/stdc++.h>

using namespace std;

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

    void addEdge(int from, int to, int cap, double cost) {
        edges[m ++] = Edge(from, to, 0, cap, cost);
        edges[m ++] = Edge(to, from, 0, 0, -cost);

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }

    inline pair <int, double> computeFlow() {
        return JohnsonDinic();
    }
private:
    struct Edge {
        int from, to;
        int flow, cap;
        double cost;

        Edge(int _from = 0, int _to = 0, int _flow = 0, int _cap = 0, double _cost = 0):
            from(_from), to(_to), flow(_flow), cap(_cap), cost(_cost) {}
        inline int other(int node) {
            return from ^ to ^ node;
        }
    };

    int n, m, s, t;

    vector <int> graph[NMAX];
    Edge edges[2 * MMAX];

    const double INF = 1e9 + 15;

    double dist[NMAX];
    int father[NMAX];
    bool vis[NMAX];
    double potentials[NMAX];
    priority_queue <pair <double, int> > _queue;

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
                double cost = edges[edge].cost + potentials[node] - potentials[other];

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

    pair <int, double> JohnsonDinic() {
        memset(potentials, 0, (n + 1) * sizeof(double));
        Dijkstra();

        int flow = 0;
        double cost = 0;
        while (Dijkstra()) {
            int node = t;
            int minimum = INF;
            double sum = 0;

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

            memcpy(potentials, dist, (n + 1) * sizeof(double));
        }

        return make_pair(flow, cost);
    }
};

const int NMAX = 400 + 5;
const int MMAX = NMAX * NMAX / 2 + 5;

struct Point {
    double x, y;
} v[NMAX];

double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

MaxFlowMinCost <2 * NMAX, MMAX> f;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i].x >> v[i].y;

    f.setN(2 * n + 2);
    f.setS(2 * n + 1);
    f.setT(2 * n + 2);

    for (int i = 1; i <= n; ++ i) {
        f.addEdge(f.getS(), i, 1, 0);
        f.addEdge(n + i, f.getT(), 2, 0);
    }

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (i != j && v[j].y > v[i].y)
                f.addEdge(i, n + j, 1, dist(v[i], v[j]));

    pair <int, double> ans = f.computeFlow();
    if (ans.first != n - 1)
        cout << "-1\n";
    else
        cout << fixed << setprecision(15) << ans.second << '\n';
    return 0;
}