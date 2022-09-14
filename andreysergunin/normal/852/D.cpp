#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int vmax = 610;
const int inf = 1e9;

class MF {
public:
    MF(int vsize, int s, int t) : vsize(vsize), s(s), t(t) {
        g.resize(vsize);
    }

    void addEdge(int u, int v, int c) {
        g[u].pb(sz(edges));
        edges.pb({u, v, c, 0});
        g[v].pb(sz(edges));
        edges.pb({v, u, 0, 0});
    }

    int dinic() {
        int ans = 0;
        while (bfs()) {
            int x;
            while ((x = dfs(s, 1))) {
                ans += x;
            }
        }
        return ans;
    }
private:
    struct edge {
        int from, to;
        int cap, flow;
    };
    vector<edge> edges;
    vector<vector<int> > g;
    int vsize;
    int s, t;
    vector<int> level, ptr;

    bool bfs() {
        level.assign(vsize, inf);
        ptr.assign(vsize, 0);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int e : g[v]) {
                if (edges[e].cap > edges[e].flow && level[edges[e].to] == inf) {
                    level[edges[e].to] = level[v] + 1;
                    q.push(edges[e].to);
                }
            }
        }
        return level[t] != inf;
    }

    int dfs(int v, int flow) {
        if (v == t) {
            return flow;
        }
        for (int i = ptr[v]; i < sz(g[v]); ++i) {
            int e = g[v][i];
            if (edges[e].cap > edges[e].flow && level[edges[e].to] == level[v] + 1) {
                int k = dfs(edges[e].to, min(flow, edges[e].cap - edges[e].flow));
                if (k) {
                    edges[e].flow += k;
                    edges[e ^ 1].flow -= k;
                    return k;
                }
            }
            ++ptr[v];
        }
        return 0;
    }
};

int dist[vmax][vmax];

struct edge {
	int from;
	int to;
	int cost;
	bool operator<(const edge& other) const {
		return cost < other.cost;
	}
};

vector<vector<int> > g;
vector<char> used;
vector<int> mt;
int n, v;

bool dfs(int u) {
	if (used[u]) {
		return false;
	}
	used[u] = true;
	for (int to : g[u]) {
		if (mt[to] == -1 || dfs(mt[to])) {
			mt[to] = u;
			return true;
		}
	}
	return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int e, req;
	cin >> v >> e >> n >> req;
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			dist[i][j] = inf;
		}
		dist[i][i] = 0;
	}

	vector<int> start(n);
	for (int i = 0; i < n; ++i) {
		cin >> start[i];
		--start[i];
	}

	while (e--) {
		int a, b, cost;
		cin >> a >> b >> cost;
		--a, --b;
		dist[a][b] = min(dist[a][b], cost);
		dist[b][a] = min(dist[b][a], cost);
	}

	for (int k = 0; k < v; ++k) {
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	vector<edge> edges;
	vector<vector<int> > people(v);
	for (int i = 0; i < n; ++i) {
		people[start[i]].pb(i);
	}

	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			if (dist[i][j] != inf) {
				for (int x : people[i]) {
					edges.pb({x, j, dist[i][j]});
				}
			}
		}
	}
	sort(all(edges));
	/*g.resize(n);
	mt.assign(v, -1);
	used.assign(n, false);

	int curr = 0;
	for (edge& e : edges) {
		g[e.from].pb(e.to);
		used[e.from] = false;
		if (dfs(e.from)) {
			++curr;
			used.assign(n, false);
		}
		if (curr >= req) {
			cout << e.cost << "\n";
			return 0;
		}
	}
	cout << "-1\n";*/

    int lf = 1, rg = sz(edges) - 1;
    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        int vsize = n + v + 2;
        MF maxflow(vsize, vsize - 2, vsize - 1);
        for (int i = 0; i <= md; ++i) {
            maxflow.addEdge(edges[i].from, edges[i].to + n, 1);
        }
        for (int i = 0; i < n; ++i) {
            maxflow.addEdge(vsize - 2, i, 1);
        }
        for (int i = 0; i < v; ++i) {
            maxflow.addEdge(i + n, vsize - 1, 1);
        }
        if (maxflow.dinic() >= req) {
            rg = md;
        } else {
            lf = md;
        }
    }

    int md = rg;
    int vsize = n + v + 2;
    MF maxflow(vsize, vsize - 2, vsize - 1);
    for (int i = 0; i <= md; ++i) {
        maxflow.addEdge(edges[i].from, edges[i].to + n, 1);
    }
    for (int i = 0; i < n; ++i) {
        maxflow.addEdge(vsize - 2, i, 1);
    }
    for (int i = 0; i < v; ++i) {
        maxflow.addEdge(i + n, vsize - 1, 1);
    }
    if (maxflow.dinic() >= req) {
        cout << edges[md].cost << "\n";
    } else {
        cout << "-1\n";
    }

}