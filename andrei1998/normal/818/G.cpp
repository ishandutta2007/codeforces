#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

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

    void addEdge(int from, int to, int cap, int cost) {
        edges[m ++] = Edge(from, to, 0, cap, cost);
        edges[m ++] = Edge(to, from, 0, 0, -cost);

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }

    inline pair <int, int> computeFlow() {
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

    const int INF = 1E9 + 15;

    int potentials[NMAX];
    bool vis[NMAX];
    int BellmanDP(int node) {
        if (vis[node])
            return potentials[node];
        if (node == s) {
            potentials[s] = 0;
            return 0;
        }
        vis[node] = true;

        potentials[node] = INF;
        for (auto edg: graph[node])
            if (edges[edg ^ 1].flow < edges[edg ^ 1].cap)
                potentials[node] = min(potentials[node], BellmanDP(edges[edg ^ 1].other(node)) + edges[edg ^ 1].cost);
        return potentials[node];
    }

    int dist[NMAX];
    int father[NMAX];
    priority_queue <pair <int, int> > _queue;

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

    pair <int, int> JohnsonDinic() {
        memset(potentials, 0, (n + 1) * sizeof(int));
        BellmanDP(t);

        int flow = 0, cost = 0;
        while (Dijkstra()) {
            int node = t;
            int minimum = INF;
            int sum = 0;

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

const int NMAX = 3000 + 5;
const int MMAX = NMAX * NMAX;

MaxFlowMinCost <2 * NMAX, MMAX> f;

int N;
int a[NMAX];

const int VALMAX = 100000 + 5;
vector <int> freq[VALMAX];
vector <int> freq7[7];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];

    f.setN(2 * N + 3);
    f.setS(2 * N + 1);
    f.setT(2 * N + 3);


    f.addEdge(2 * N + 2, 2 * N + 3, 4, 0);

    for (int i = 1; i <= N; ++ i) {
        f.addEdge(2 * N + 1, i, 1, -1);
        f.addEdge(i, N + i, 1, 0);
        f.addEdge(N + i, 2 * N + 2, 1, 0);
    }

    /*for (int i = N; i; -- i) {
        for (int j = 0; j < freq[a[i] + 1].size() && j < 4; ++ j)
            f.addEdge(N + i, freq[a[i] + 1][freq[a[i] + 1].size() - j - 1], 1, -1);
        for (int j = 0; j < freq[a[i] - 1].size() && j < 4; ++ j)
            f.addEdge(N + i, freq[a[i] - 1][freq[a[i] - 1].size() - j - 1], 1, -1);
        for (int j = 0; j < freq7[a[i] % 7].size() && j < 4; ++ j)
            f.addEdge(N + i, freq7[a[i] % 7][freq7[a[i] % 7].size() - j - 1], 1, -1);

        freq[a[i]].push_back(i);
        freq7[a[i] % 7].push_back(i);
    }*/

    for (int i = 1; i <= N; ++ i)
        for (int j = i + 1; j <= N; ++ j)
            if (a[j] == 1 + a[i] || a[j] == a[i] - 1 || a[i] % 7 == a[j] % 7)
                 f.addEdge(N + i, j, 1, -1);

    auto ans = f.computeFlow();
    cout << -ans.second << '\n';
    return 0;
}