#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<VL> cap, flow, cost;
	vi seen;
	VL dist, pi;
	vector<pii> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  MCMF solver(n+3);
  const int s = n+2;
  const int t = n+1;
  solver.addEdge(s, 0, n, 0);
  solver.addEdge(0, t, n, 0);
  for (int i = 1; i <= n; i++) {
    solver.addEdge(0, i, 1, 0);
    solver.addEdge(i, t, 1, 0);
  }
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    solver.addEdge(u, v, INF, a[v]-a[u]);
    edges[i] = make_pair(u, v);
  }

  solver.setpi(s);
  solver.maxflow(s, t);

  vector<int> d(n+2, -1e9);

  // Bellman-Ford
  for (int v = 1; v <= n; v++) {
    if (!solver.flow[0][v]) d[v] = 0;
  }

  for (int iters = 0; iters <= n; iters++) {
    for (auto& [u, v]: edges) {
      d[v] = max(d[v], d[u]+a[u]-a[v]);
      if (solver.flow[u][v]) d[u] = max(d[u], d[v]+a[v]-a[u]);
    }
    for (int v = 1; v <= n; v++) {
      if (solver.flow[v][t]) d[v] = max(d[v], d[t]);
      else d[t] = max(d[t], d[v]);
    }
  }
  for (int v = 1; v <= n; v++) {
    cout << a[v]+d[v] << " \n"[v==n];
  }
}