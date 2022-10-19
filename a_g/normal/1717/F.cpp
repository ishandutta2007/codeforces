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

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> s(n), a(n);
  for (int& x: s) cin >> x;
  for (int& x: a) cin >> x;
  Dinic solver(m+n+3);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[u-1]++, a[v-1]++;
    solver.addEdge(i+1, m+u, 1);
    solver.addEdge(i+1, m+v, 1);
    solver.addEdge(0, i+1, 1);
  }

  int used = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 0) {
      solver.addEdge(m+i+1, m+n+1, INF);
    }
    else {
      if (a[i]&1 || a[i] < 0) {
        cout << "NO\n";
        return 0;
      }
      solver.addEdge(m+i+1, m+n+2, a[i]/2);
      used += a[i]/2;
    }
  }
  if (used > m) {
    cout << "NO\n";
    return 0;
  }
  solver.addEdge(m+n+1, m+n+2, m-used);
  if (solver.calc(0, m+n+2) < m) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 1; i <= m; i++) {
    int x, y;
    for (Dinic::Edge& e: solver.adj[i]) {
      if (e.to == 0) continue;
      if (e.flow()) y = e.to-m;
      else x = e.to-m;
    }
    cout << x << ' ' << y << '\n';
  }
}