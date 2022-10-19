#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const long long INF = 1e18;

int lvl(int x, int y) {
  if (y&1) return 2+(x&1);
  else return 1-(x&1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<pair<int, int>, pair<int, int>> to_index;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    sum += w;
    to_index[make_pair(x, y)] = make_pair(i, w);
  }
  Dinic solver(2*n+2);
  for (auto& [p, q]: to_index) {
    int x = p.first;
    int y = p.second;
    int i = q.first;
    int w = q.second;
    if (lvl(x, y) == 0) solver.addEdge(0, 2*i+1, INF);
    else if (lvl(x, y) == 3) solver.addEdge(2*i+2, 2*n+1, INF);
    solver.addEdge(2*i+1, 2*i+2, w);
    for (auto& [dx, dy]: dirs) {
      int tx = x+dx;
      int ty = y+dy;
      if (lvl(tx, ty) == lvl(x, y)+1 && to_index.count(make_pair(tx, ty))) {
        solver.addEdge(2*i+2, 2*to_index[make_pair(tx, ty)].first+1, INF);
      }
    }
  }
  cout << sum-solver.calc(0, 2*n+1) << '\n';
}