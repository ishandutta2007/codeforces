#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 1005, MMAX = 30005;
const int64_t INF = 2000000001;

struct Edge {
    int from, to, cost, pos;
    Edge() = default;
    Edge(int _from, int _to, int _cost):
        from(_from), to(_to), cost(_cost) {}

    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
    bool operator==(const Edge& o) const {
        return make_pair(from, to) == make_pair(o.from, o.to);
    }
};

class DSU {
public:
    DSU(int n):
        father(vector<int>(n, 0)) {
            for (int i = 0; i < n; ++i) {
                father[i] = i;
            }
        }
    
    int find(int x) {
        int y, p;
        for (y = x; father[y] != y; y = father[y]);
        for (; x != y; x = p) {
            p = father[x];
            father[x] = y;
        }
        return y;
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        father[y] = x;
    }
private:
    vector<int> father;
};

vector<pair<int, int>> G[NMAX];
bool used[NMAX];
bool hasT[NMAX];
int level[NMAX], minlvl[NMAX];

bool excluded[MMAX];
int ecost[MMAX];

int e2 = -1;

void dfs(int node, int prev, int t) {
    used[node] = true;
    minlvl[node] = level[node];
    for (auto& p: G[node]) {
        int to = p.first;
        int e = p.second;

        if (e == prev || excluded[e]) {
            continue;
        }

        if (used[to]) {
            minlvl[node] = min(minlvl[node], level[to]);
        } else {
            level[to] = level[node] + 1;
            dfs(to, e, t);
            if (hasT[to]) {
                hasT[node] = true;
            }
            if (minlvl[to] > level[node]) {
                if (hasT[to]) {
                    if (e2 == -1 || ecost[e] < ecost[e2]) {
                        e2 = e;
                    }
                }
            } else {
                minlvl[node] = min(minlvl[node], minlvl[to]);
            }
        }
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
    s--; t--;
    
    vector<Edge> edges(m);
    int pos = 0;

    for (Edge& e: edges) {
        cin >> e.from >> e.to >> e.cost;
        e.from--; e.to--;
        ecost[pos] = e.cost;
        e.pos = pos++;
    }

    int e1 = -1, e2 = -1;
    int totalCost = INF;
    DSU f(n);
    vector<Edge> rEdges;
    for (const Edge& e: edges) {
        if (f.find(e.from) != f.find(e.to)) {
            rEdges.push_back(e);
            f.unite(e.from, e.to);
            assert(f.find(e.from) == f.find(e.to));
        }
    }

    for (const Edge& e: edges) {
        G[e.from].push_back(make_pair(e.to, e.pos));
        G[e.to].push_back(make_pair(e.from, e.pos));
    }

    if (f.find(s) != f.find(t)) {
        totalCost = 0;
    }

    for (const Edge& e: rEdges) {
        excluded[e.pos] = true;
        memset(used, 0, sizeof used);
        memset(level, 0,sizeof level);
        memset(hasT, 0, sizeof hasT);
        hasT[t] = true;
        ::e2 = -1;
        dfs(s, -1, t);
        excluded[e.pos] = false;

        if (hasT[s] && ::e2 == -1) {
            continue;
        }
        int c2 = ::e2 == -1 ? 0: ecost[::e2];
        if (e.cost + c2 < totalCost) {
            totalCost = e.cost + c2;
            e1 = e.pos;
            e2 = ::e2;
        }
    }

    if (totalCost == INF) {
        cout << "-1\n";
    } else {
        cout << totalCost << '\n';
        int sz = (e1 != -1) + (e2 != -1);
        cout << sz << '\n';
        if (e1 != -1) {
            cout << e1 + 1 << ' ';
        }
        if (e2 != -1) {
            cout << e2 + 1 << ' ';
        }
        cout << '\n';
    }
}