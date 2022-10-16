#include <bits/stdc++.h>

using namespace std;

struct SCC {
	int n, time, num_comps;
	vector<vector<int>> adj;
	vector<int> disc, id, stk;
	vector<vector<int>> comps;

	void init(int n_) {
		n = n_;
		time = 0;
		num_comps = 0;
		adj.assign(n, vector<int>());
		id.assign(n, -1);
		disc.assign(n, 0);
		comps.clear();
	}

	void ae(int u, int v) {
		adj[u].push_back(v);
	}

	int dfs(int src) {
		int low = disc[src] = ++time;
		stk.push_back(src);
		for (int nxt : adj[src]) 
			if (id[nxt] == -1)
				low = min(low, disc[nxt] ? : dfs(nxt));
		if (low == disc[src]) {
			for (int nxt = -1; nxt != src;)
				id[nxt = stk.back()] = num_comps, stk.pop_back();
			num_comps++;
		}
		return low;
	}
	
	void build() {
		// builds in topological order
		for (int i = 0; i < n; i++) 
			if (!disc[i])
				dfs(i);
		for (auto& x : id) 
			x = num_comps - 1 - x;
		comps.resize(num_comps);
		for (int i = 0; i < n; i++)
			comps[id[i]].push_back(i);
	}
};

void solve_case(int tc = 0) {
	int n, m;
	cin >> n >> m;
	SCC S; 
	S.init(n);
	vector<array<int, 2>> edges;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		edges.push_back({u, v});
		S.ae(u, v);
	}	
	S.build();
	int sz = S.num_comps;
	vector<vector<int>> g(sz);
	vector<vector<int>> rg(sz);
	vector<bool> big(sz);
	int root = S.id[0];
	for (int i = 0; i < sz; ++i) {
		if (S.comps[i].size() > 1) {
			big[i] = true;
		}
	}
	for (auto& e : edges) {
		int u = S.id[e[0]];
		int v = S.id[e[1]];
		if (u != v) {
			g[u].push_back(v);
			rg[v].push_back(u);
		} else { 
			if (e[0] == e[1]) {
				big[u] = true;
			}
		}
	}
	vector<int> ans(n);
	vector<int> res(sz);
	if (big[root]) {
		res[root] = -1;
	} else {
		res[root] = 1;
	}
	for (int i = root + 1; i < sz; ++i) {
		bool infinite = big[i];
		int cnt = 0;
		for (int j : rg[i]) {
			if (res[j] == 0) {
				continue;
			} else if (res[j] == 1) {
				++cnt;
			} else if (res[j] == -1) {
				infinite = true;
				++cnt;
			} else {
				cnt += res[j];
			}
		}
		if (cnt) {
			if (infinite) {
				res[i] = -1;
			} else {
				if (cnt > 1) {
					res[i] = 2;
				} else {
					res[i] = 1;
				}
			}
		}
	}
	for (int i = 0; i < sz; ++i) {
		for (int u : S.comps[i]) {
			ans[u] = res[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
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