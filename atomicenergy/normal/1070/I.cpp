#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long ll;

template <class X>
struct dinic {
	struct edge {
		int u, v;
		X cap, flow;
		edge() {}
		edge(int u, int v, X cap): u(u), v(v), cap(cap), flow(0) {}
	};
	
	int N;
	vector<edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	
	dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
	
	void add_edge(int u, int v, X cap) {
		if (u == v) return;
		g[u].emplace_back(E.size());
		E.emplace_back(edge(u, v, cap));
		g[v].emplace_back(E.size());
		E.emplace_back(edge(v, u, 0));
	}
	
	bool bfs(int S, int T) {
		fill(d.begin(), d.end(), N + 1);
		int qf = 0, qb = 1;
		d[S] = 0;
		pt[0] = S;
		while(qf != qb){
			int u = pt[qf++];
			if(u == T) break;
			for(int k : g[u]) {
				edge &e = E[k];
				if(e.flow < e.cap && d[e.v] > d[e.u] + 1){
					d[e.v] = d[e.u] + 1;
					pt[qb++] = e.v;
				}
			}
		}
		return d[T] != N + 1;
	}
	
	X dfs(int u, int T, X flow = -1){
		if(u == T || !flow) return flow;
		for(int &i = pt[u]; i < g[u].size(); i++){
			edge &e = E[g[u][i]];
			edge &oe = E[g[u][i]^1];
			if(d[e.v] == d[e.u] + 1){
				X amt = e.cap - e.flow;
				if(flow != -1 && amt > flow) amt = flow;
				if(X pushed = dfs(e.v, T, amt)){
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	
	X flow(int S, int T) {
		X tot = 0;
		while(bfs(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while(X flow = dfs(S, T))
				tot += flow;
		}
		return tot;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, m, k;
		cin >> n >> m >> k;
		dinic<ll> d(1 + m + n + 1);
		vector<int> deg(n);
		vector<pair<int,int>> edges;
		
		for(int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			d.add_edge(0, 1+i, 1);
			d.add_edge(1+i, 1+m+u, 1);
			d.add_edge(1+i, 1+m+v, 1);
			++deg[u], ++deg[v];
			edges.emplace_back(u, v);
		}
		for(int i = 0; i < n; ++i) {
			d.add_edge(1+m+i, 1+n+m, 2*k-deg[i]);
		}
		ll flow = d.flow(0, 1+n+m);
		if(flow != m) {
			for(int i = 0; i < m; ++i) {
				cout << "0 ";
			}
			cout << "\n";
		} else {
			vector<vector<int>> G(n);
			for(auto e : d.E) {
				if(e.flow == 0 && 0 < e.u && e.u <= m) {
					int edge_ind = e.u - 1;
					int our_out = e.v - m - 1;
					G[our_out].push_back(edge_ind);
				}
			}
			int ind = 1;
			vector<int> col(m);
			for(int u = 0; u < n; ++u) {
				for(int j = 0; j < -1+(int)G[u].size(); j += 2) {
					col[G[u][j]] = col[G[u][j+1]] = ind;
					++ind;
				}
				if((int)G[u].size()%2 == 1) {
					col[G[u].back()] = ind++;
				}
			}
			for(int i = 0; i < m; ++i) {
				cout << col[i] << " ";
			}
			cout << "\n";
		}
	}

}