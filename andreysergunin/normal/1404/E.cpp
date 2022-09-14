#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

const int INF = 2e9;

class Network {
public: 
    Network(): n(0) {};

    Network(int n) : n(n) {
        head.assign(n, -1);
        last.assign(n, -1);
    }

    void addOneEdge(int u, int v, int cap) {    
        if (last[u] == -1) {
            head[u] = sz(edges);
        } else {
            lnk[last[u]] = sz(edges);
        }
        last[u] = sz(edges);

        lnk.push_back(-1);
        edges.push_back(Edge{u, v, cap, 0});
    }

    void addEdge(int u, int v, int cap) {
        addOneEdge(u, v, cap);
        addOneEdge(v, u, 0); // change if undirected
    }

    int maxFlow(int source, int target) {
        int ans = 0;
        vector<int> dist(n);
        vector<int> ptr;
        
        while (bfs(source, target, dist)) {
            int flow = 0;
            ptr = head;
            while ((flow = dfs(source, target, dist, ptr, INF)) > 0) {
                ans += flow;
            }
        }
        return ans;
    }

    void printFlow() {
        for (int i = 0; i < sz(edges); i += 2) {
            if (edges[i].flow >= 0) {
                cout << edges[i].from + 1 << " " << edges[i].to + 1 << " " << edges[i].flow << "\n";
            } else {
                cout << edges[i].to + 1 << " " << edges[i].from + 1 << " " << -edges[i].flow << "\n";
            }
        }
    }

private:
    bool bfs(int source, int target, vector<int> &dist) {
        queue<int> q;
        dist.assign(sz(dist), -1);
        dist[source] = 0;
        q.push(source);
        while (!q.empty()) {
            int v = q.front();
            for (int e = head[v]; e != -1; e = lnk[e]) {
                if (dist[edges[e].to] == -1 && edges[e].cap > edges[e].flow) {
                    q.push(edges[e].to);
                    dist[edges[e].to] = dist[v] + 1;
                }
            }
            q.pop();
        }

        return (dist[target] >= 0);
    }

    int dfs(int v, int target, vector<int> &dist, vector<int> &ptr, int maxFlow) {
        if (v == target) {
            return maxFlow;
        }
        for (int e = ptr[v]; e != -1; e = lnk[e]) {
            if (dist[v] + 1 == dist[edges[e].to] && edges[e].cap - edges[e].flow > 0) {
                int curFlow = min(maxFlow, edges[e].cap - edges[e].flow);
                int flow = dfs(edges[e].to, target, dist, ptr, curFlow);
                if (flow > 0) {
                    edges[e].flow += flow;
                    edges[e ^ 1].flow -= flow;
                    return flow;
                }
            }
            ptr[v] = lnk[ptr[v]];
        }
        return 0;
    }

    struct Edge {
        int from;
        int to;
        int cap;
        int flow;
    };

    const int INF = INT_MAX;
    int n;
    vector<Edge> edges;
    vector<int> lnk;
    vector<int> head;
    vector<int> last;
};


void solve() {

    int n, m;
    cin >> n >> m;
    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<vector<int>> h(n, vector<int>(m, -1));
    vector<vector<int>> v(n, vector<int>(m, -1));

    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (s[i][j] == '#' && s[i][j + 1] == '#') {
                h[i][j] = k++;
            }
        }
    }
    int l = k;

    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#' && s[i + 1][j] == '#') {
                v[i][j] = k++;
            }
        }
    }

    Network net(k + 2);
    int source = k;
    int target = k + 1;

    for (int i = 0; i < l; ++i) {
        net.addEdge(source, i, 1);
    }
    for (int i = l; i < k; ++i) {
        net.addEdge(i, target, 1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (h[i][j] != -1) {
                if (v[i][j] != -1) {
                    net.addEdge(h[i][j], v[i][j], INF);
                    // net.addEdge(v[i][j], h[i][j], INF);
                }
                if (i > 0 && v[i - 1][j] != -1) {
                    net.addEdge(h[i][j], v[i - 1][j], INF);
                    // net.addEdge(v[i - 1][j], h[i][j], INF);
                }
                if (j + 1 < m && v[i][j + 1] != -1) {
                    net.addEdge(h[i][j], v[i][j + 1], INF);
                }
                if (i > 0 && j + 1 < m && v[i - 1][j + 1] != -1) {
                    net.addEdge(h[i][j], v[i - 1][j + 1], INF);
                }
             }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#') {
                ++res;
            }
        }
    }

    res -= (k - net.maxFlow(source, target));

    cout << res << endl;
}