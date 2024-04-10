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

    void addEdge(int from, int to, int cap) {
        edges[m ++] = Edge(from, to, 0, cap);
        edges[m ++] = Edge(to, from, 0, 0);

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }

    inline int computeFlow() {
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

const int NMAX = 105 + 5;
MaxFLow <NMAX, NMAX * NMAX> f;

struct Obj {
    int p, c, l;
    bool bad;
    friend bool operator<(const Obj &a, const Obj &b) {
        return a.l < b.l;
    }
} objs[NMAX];

const int VALMAX = 400000 + 5;

int n;
vector <int> primes;
int low[VALMAX];

void sieve() {
    for (int i = 2; i < VALMAX; ++ i) {
        if (!low[i]) {
            primes.push_back(i);
            low[i] = i;
        }
        for (int j = 0; j < primes.size() && primes[j] <= low[i] && primes[j] * i < VALMAX; ++ j)
            low[primes[j] * i] = primes[j];
    }
}

int works(int cnt) {
    for (int i = 1; i <= cnt; ++ i)
        objs[i].bad = false;

    int best = -1;
    int who = -1;
    for (int i = 1; i <= cnt; ++ i)
        if (objs[i].c == 1) {
            if (objs[i].p > best) {
                best = objs[i].p;
                who = i;
            }
            objs[i].bad = true;
        }
    if (who > -1)
        objs[who].bad = false;

    int sum = 0;
    for (int i = 1; i <= cnt; ++ i)
        if (!objs[i].bad)
            sum += objs[i].p;

    f.clear();
    f.setN(NMAX);
    f.setS(101);
    f.setT(102);

    for (int i = 1; i <= cnt; ++ i)
        if (!objs[i].bad && objs[i].c % 2 == 0)
            for (int j = 1; j <= cnt; ++ j)
                if (i != j && !objs[j].bad && objs[j].c % 2 == 1)
                    if (low[objs[j].c + objs[i].c] == objs[j].c + objs[i].c)
                        f.addEdge(j, i, 1E9);

    //Edges to odds
    for (int i = 1; i <= cnt; ++ i)
        if (!objs[i].bad && objs[i].c % 2 == 1)
            f.addEdge(f.getS(), i, objs[i].p);

    //Edges to evens
    for (int i = 1; i <= cnt; ++ i)
        if (!objs[i].bad && objs[i].c % 2 == 0)
            f.addEdge(i, f.getT(), objs[i].p);

    int ans = sum - f.computeFlow();
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    sieve();

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; ++ i)
        cin >> objs[i].p >> objs[i].c >> objs[i].l;
    sort(objs + 1, objs + N + 1);

    int st = 1;
    int dr = N;
    int ans = N + 1;

    while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (works(mid) >= K) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    if (ans == N + 1)
        cout << "-1\n";
    else
        cout << objs[ans].l << '\n';

    /*int n, m;
    cin >> n >> m;

    f.setN(n);
    f.setS(1);
    f.setT(n);

    int a, b, c;
    while (m --) {
        cin >> a >> b >> c;
        f.addEdge(a, b, c);
    }

    cout << f.computeFlow() << '\n';*/
    return 0;
}