#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to;
    long long c, f;

    Edge(int _to, long long _c): to(_to), c(_c), f(0) {}
};

const int MAXN = 55, MAXM = 505, MAXC = 1000 * 1000 + 5,
    INT_INF = 1000 * 1000 * 1000 + 5;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
int pos[MAXN], d[MAXN];
pair<pair<int, int>, int> ee[MAXM];
vector<Edge> e;
vector<int> g[MAXN];

void addEdge(int v, int u, long long c) {
    g[v].push_back(e.size());
    e.push_back(Edge(u, c));
    g[u].push_back(e.size());
    e.push_back(Edge(v, 0));
}

bool bfs(int s, int t, int n) {
    for(int i = 0; i < n; i++)
        d[i] = INT_INF;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty() && d[t] >= INT_INF) {
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = e[g[v][i]].to;
            long long cf = e[g[v][i]].c - e[g[v][i]].f;
            if(cf && d[u] >= INT_INF) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return d[t] < INT_INF;
}

long long dfs(int v, int t, long long mincf) {
    if(!mincf || v == t)
        return mincf;
    for(; pos[v] < (int)g[v].size(); pos[v]++) {
        int id = g[v][pos[v]], u = e[id].to;
        long long cf = e[id].c - e[id].f;
        if(d[u] == d[v] + 1) {
            long long f = dfs(u, t, min(mincf, cf));
            if(f) {
                e[id].f += f;
                e[id ^ 1].f -= f;
                return f;
            }
        }
    }
    return 0;
}

bool solve(int n, int m, int x, long double y) {
    e.clear();
    for(int i = 0; i < n; i++)
        g[i].clear();
    for(int i = 0; i < m; i++)
        addEdge(ee[i].first.first, ee[i].first.second,
                (long long)(ee[i].second / y));
    long long flow = 0;
    while(bfs(0, n - 1, n)) {
        for(int i = 0; i < n; i++)
            pos[i] = 0;
        while(long long f = dfs(0, n - 1, INF))
            flow += f;
    }
    return flow >= x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++) {
        cin >> ee[i].first.first >> ee[i].first.second >> ee[i].second;
        ee[i].first.first--;
        ee[i].first.second--;
    }
    long double l = 0, r = MAXC;
    for(int it = 0; it < 100; it++) {
        long double mm = (l + r) / 2;
        if(solve(n, m, x, mm))
            l = mm;
        else
            r = mm;
    }
    cout << l * x << '\n';
    return 0;
}