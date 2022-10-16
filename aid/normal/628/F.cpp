#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, c, f;

    Edge(int _to, int _c): to(_to), c(_c), f(0) {}
};

const int MAXN = 20 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
pair<int, int> qq[MAXN];
int pos[MAXN], d[MAXN];
vector<int> g[MAXN];
vector<Edge> e;

void addEdge(int v, int u, int c) {
    g[v].push_back(e.size());
    e.push_back(Edge(u, c));
    g[u].push_back(e.size());
    e.push_back(Edge(v, 0));
}

bool bfs(int s, int t, int n) {
    for(int i = 0; i < n; i++)
        d[i] = INF;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty() && d[t] >= INF) {
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = e[g[v][i]].to, cf = e[g[v][i]].c - e[g[v][i]].f;
            if(cf && d[u] >= INF) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return d[t] < INF;
}

int dfs(int v, int t, int mincf) {
    if(v == t)
        return mincf;
    for(; pos[v] < (int)g[v].size(); pos[v]++) {
        int id = g[v][pos[v]], u = e[id].to, cf = e[id].c - e[id].f;
        if(d[u] == d[v] + 1 && cf) {
            int f = dfs(u, t, min(mincf, cf));
            if(f) {
                e[id].f += f;
                e[id ^ 1].f -= f;
                return f;
            }
        }
    }
    return 0;
}

int getCnt(int x, int r) {
    if(x < r)
        return 0;
    return (x - r) / 5 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, b, q;
    cin >> n >> b >> q;
    for(int i = 0; i < q; i++)
        cin >> qq[i].first >> qq[i].second;
    qq[q] = make_pair(b, n);
    q++;
    sort(qq, qq + q);
    q = unique(qq, qq + q) - qq;
    for(int i = 0; i + 1 < q; i++)
        if(qq[i].first == qq[i + 1].first) {
            cout << "unfair\n";
            return 0;
        }
    for(int i = q - 1; i > 0; i--)
        qq[i].second -= qq[i - 1].second;
    for(int i = 0; i < q; i++)
        if(qq[i].second < 0) {
            cout << "unfair\n";
            return 0;
        }
    int s = q + 5, t = s + 1;
    for(int i = 0; i < q; i++)
        addEdge(s, i, qq[i].second);
    for(int i = 0; i < q; i++)
        for(int j = 0; j < 5; j++) {
            int cap = getCnt(qq[i].first, j) -
                getCnt((i? qq[i - 1].first : 0), j);
            addEdge(i, q + j, cap);
        }
    for(int i = 0; i < 5; i++)
        addEdge(q + i, t, n / 5);
    int flow = 0, sz = t + 1;
    while(bfs(s, t, sz)) {
        for(int i = 0; i < sz; i++)
            pos[i] = 0;
        while(int f = dfs(s, t, INF))
            flow += f;
    }
    if(flow == n)
        cout << "fair\n";
    else
        cout << "unfair\n";
    return 0;
}