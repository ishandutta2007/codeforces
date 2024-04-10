#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const long long INF = 1ll << 60;

struct Dinic {
	struct Edge {
		int v, id;
		long long f;
		Edge(int _v, long long _f, int _id) : v(_v), id(_id), f(_f) {}
	};
	
	vector <vector <Edge>> adj;
	vector <int> level;
	int n, s, t;
	
	Dinic (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
		adj.resize(n);
		level.resize(n);
	}
	
	void add_edge(int u, int v, long long f) {
		adj[u].push_back(Edge(v, f, adj[v].size()));
		adj[v].push_back(Edge(u, 0, adj[u].size() - 1));
	}
	
	bool bfs() {
		for (int i = 0; i < n; ++i) level[i] = -1;
		queue <int> q;
		q.push(s);
		level[s] = 0;
		while (q.size()) {
			int v = q.front(); q.pop();
			for (Edge e : adj[v]) {
				if (e.f > 0 and level[e.v] == -1) {
					level[e.v] = level[v] + 1;
					q.push(e.v);
				}
			}
		}
		return level[t] != -1;
	}
	
	long long dfs(int v, long long minf) {
		if (v == t) return minf;
		long long ans = 0;
		for (Edge &e : adj[v]) {
			if (e.f > 0 and level[e.v] == level[v] + 1) {
				long long nxtf = dfs(e.v, min(minf, e.f));
				ans += nxtf;
				minf -= nxtf;
				e.f -= nxtf;
				adj[e.v][e.id].f += nxtf;
				if (minf == 0) return ans;
			}
		}
		if (!ans) level[v] = -1;
		return ans;
	}
	
	long long runFlow() {
		long long ans = 0;
		while (bfs()) {
			ans += dfs(s, INF);
		}
		return ans;
	}
};

int main () {
    vector <int> l, r;
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }
    pii x[m], y[m];
    fop (i,0,m) {
        cin >> x[i].X >> y[i].X >> x[i].Y >> y[i].Y;
        l.pb(x[i].X);
        l.pb(x[i].Y);
        r.pb(y[i].X);
        r.pb(y[i].Y);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    l.resize(unique(l.begin(), l.end()) - l.begin());
    r.resize(unique(r.begin(), r.end()) - r.begin());
    int all = l.size() * 2 + r.size() * 2;
    int s = all - 2, t = all - 1;
    Dinic solver(all, s, t);
    fop (i,0,l.size()) solver.add_edge(s, i * 2, 1);
    fop (i,0,l.size() - 1) solver.add_edge(s, i * 2 + 1, l[i+1] - l[i] - 1);
    fop (i,0,r.size()) solver.add_edge(l.size() * 2 - 1 + i * 2, t, 1);
    fop (i,0,r.size() - 1) solver.add_edge(l.size() * 2 + i * 2, t, r[i+1] - r[i] - 1);
    fop (i,0,m) {
        int a1 = lower_bound(l.begin(), l.end(), x[i].X) - l.begin();
        int a2 = lower_bound(l.begin(), l.end(), x[i].Y) - l.begin();
        int b1 = lower_bound(r.begin(), r.end(), y[i].X) - r.begin();
        int b2 = lower_bound(r.begin(), r.end(), y[i].Y) - r.begin();
        fop (a, a1 * 2, a2 * 2 + 1) {
            fop (b, b1 * 2, b2 * 2 + 1) {
                solver.add_edge(a, l.size() * 2 - 1 + b, INF);
            }
        }
    }
    cout << solver.runFlow() << endl;
}