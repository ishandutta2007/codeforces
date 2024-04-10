#include <bits/stdc++.h>

using namespace std;

struct SCC {
	int n; 
	std::vector<std::vector<int>> g, rg, scc_graph, comps;
	std::vector<int> id, ord, roots, topo_ord;
	std::vector<bool> vis;

	void init(int n_) {
		n = n_;
		g.assign(n, std::vector<int>());
		rg.assign(n, std::vector<int>());
		scc_graph.assign(n, std::vector<int>());
		comps.assign(n, std::vector<int>());
		vis.assign(n, false);
		id.assign(n, -1);
		ord.clear();
		roots.clear();     
		topo_ord.clear();  
	}

	void ae(int u, int v) {
		g[u].push_back(v);
		rg[v].push_back(u);
	}

	void dfs_order(int u) {
		vis[u] = true;
		for (auto& v : g[u]) {
			if (vis[v]) 
				continue;
			dfs_order(v);
		}
		ord.push_back(u);
	}

	void dfs_color(int u, int c) {
		id[u] = c;
		for (int& v : rg[u]) 
			if (id[v] == -1) 
				dfs_color(v, c);
	}

	void topological_sort() {
		std::vector<int> in(n);
		std::list<int> todo;
		for (int i = 0; i < n; ++i) 
			for (auto& j : scc_graph[i])
				++in[j];
		for (int i = 0; i < n; ++i)
			if (!in[i] && id[i] == i)
				todo.push_back(i);
		while (!todo.empty()) {
			int u = todo.front();
			todo.pop_front();
			topo_ord.push_back(u);
			for (auto& v : scc_graph[u]) 
				if (!(--in[v])) 
					todo.push_back(v);
		}
	}

	void build_scc_graph() {
		for (int i = 0; i < n; ++i) {
			comps[id[i]].push_back(i);
			for (auto& j : g[i]) {
				if (id[i] == id[j]) 
					continue;
				scc_graph[id[i]].push_back(id[j]);
			}
		}
		topological_sort();
	}

	void gen() {
		for (int i = 0; i < n; ++i) {
			if (!vis[i])
				dfs_order(i);
		}
		reverse(ord.begin(), ord.end());
		for (auto& x : ord) 
			if (id[x] == -1) 
				dfs_color(x, x), roots.push_back(x);
	}
};

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	vector<int> p(n), q(n);
	iota(p.begin(), p.end(), 0);
	iota(q.begin(), q.end(), 0);
	sort(p.begin(), p.end(), [&](int i, int j) {
		return a[i] > a[j];
	});
	sort(q.begin(), q.end(), [&](int i, int j) {
		return b[i] > b[j];
	});
	SCC scc;
	scc.init(n);
	for (int i = 0; i < n - 1; ++i) {
		scc.ae(p[i], p[i + 1]);
		scc.ae(q[i], q[i + 1]);
	}
	scc.gen();
	scc.build_scc_graph();
	vector<int> in(n);
	for (int i = 0; i < n; ++i) {
		for (int j : scc.scc_graph[scc.id[i]]) {
			++in[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (in[scc.id[i]] == 0) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}