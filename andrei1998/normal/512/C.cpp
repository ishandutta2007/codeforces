#include <iostream>
#include <cstring>
#include <queue>
#include <bitset>
#include <vector>

using namespace std;

int prime(int nr) {
    if (nr <= 1)
        return false;
    for (int i = 2; i * i <= nr; ++ i)
        if (nr % i == 0)
            return false;
    return true;
}

const int VALMAX = 10000 + 5;
bool isPrime[2 * VALMAX];

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

    void addEdge(int from, int to, int cap) {
        edges[m ++] = Edge(from, to, 0, cap);
        edges[m ++] = Edge(to, from, 0, 0);

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
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

const int NMAX = 205;

MaxFLow <NMAX, NMAX * NMAX> f;

int val[NMAX];

pair <int, int> evens[NMAX];
int evensC;

pair <int, int> odds[NMAX];
int oddsC;

vector <vector <int> > sol;

int N;
void dfs(int node) {
    if (node > N)
        return ;
    f.vis[node] = true;
    sol.back().push_back(val[node]);
    for (auto it: f.graph[node])
        if (!f.vis[f.edges[it].other(node)] && f.edges[it].flow != 0)
            dfs(f.edges[it].other(node));
}

int main()
{
    ios_base :: sync_with_stdio(false);
    for (int i = 2; i < 2 * VALMAX; ++ i)
        isPrime[i] = prime(i);

    cin >> N;

    for (int i = 1; i <= N; ++ i) {
        int val;
        cin >> val;

        if (val & 1)
            odds[++ oddsC] = make_pair(val, i);
        else
            evens[++ evensC] = make_pair(val, i);
    }

    for (int i = 1; i <= oddsC; ++ i)
        val[i] = odds[i].second;
    for (int i = 1; i <= evensC; ++ i)
        val[oddsC + i] = evens[i].second;

    if (oddsC != evensC) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 1; i <= oddsC; ++ i)
        for (int j = 1; j <= evensC; ++ j)
            if (isPrime[odds[i].first + evens[j].first])
                f.addEdge(i, oddsC + j, 1);

    f.setN(N + 2);
    f.setS(N + 1);
    f.setT(N + 2);

    for (int i = 1; i <= oddsC; ++ i)
        f.addEdge(N + 1, i, 2);
    for (int i = 1; i <= evensC; ++ i)
        f.addEdge(oddsC + i, N + 2, 2);

    if (f.computeFlow() != N) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 1; i <= N + 2; ++ i)
        f.vis[i] = false;

    for (int i = 1; i <= oddsC; ++ i)
        if (!f.vis[i]) {
            sol.push_back(vector <int>());
            dfs(i);
        }

    cout << sol.size() << '\n';
    for (auto v: sol) {
        cout << v.size();
        for (auto elem: v)
            cout << ' ' << elem;
        cout << '\n';
    }
    return 0;
}