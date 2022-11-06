#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};

bool dfs(const int u, const vector<vector<int>> &adj, vector<int> &color) {
	assert(color[u] != -1);
	for (int v : adj[u]) {
		if (color[v] == -1) {
			color[v] = !color[u];
			if (!dfs(v, adj, color))
				return false;
		} else if (color[v] == color[u])
			return false;
	}
	return true;
}

ll f(const vector<pair<int, int>> eqConstr, const vector<pair<int, int>> ineqConstr, const vector<pair<int, int>> valConstr) {
	vector<int> vars;
	for (const pair<int, int> &p : eqConstr) {
		vars.push_back(p.first);
		vars.push_back(p.second);
	}
	for (const pair<int, int> &p : ineqConstr) {
		vars.push_back(p.first);
		vars.push_back(p.second);
	}
	for (const pair<int, int> &p : valConstr)
		vars.push_back(p.first);


	sort(vars.begin(), vars.end());
	vars.erase(unique(vars.begin(), vars.end()), vars.end());

	if (vars.empty())
		return 1;
	assert(vars[0] >= 0);

	const int maxN = vars.back() + 1;

	DSU dsu(maxN);
	for (const pair<int, int> &p : eqConstr)
		dsu.merge(p.first, p.second);

	vector<vector<int>> adj(maxN);
	for (pair<int, int> p : ineqConstr) {
		p.first = dsu.find(p.first);
		p.second = dsu.find(p.second);
		adj[p.first].push_back(p.second);
		adj[p.second].push_back(p.first);
	}

	vector<int> color(maxN, -1);

	for (pair<int, int> p : valConstr) {
		p.first = dsu.find(p.first);
		if (color[p.first] == -1) {
			color[p.first] = p.second;
			if (!dfs(p.first, adj, color))
				return 0;
		} else if (color[p.first] != p.second)
			return 0;
	}

	ll ans = 1;
	for (int x : vars) {
		x = dsu.find(x);
		if (color[x] == -1) {
			color[x] = 0;
			if (!dfs(x, adj, color))
				return 0;
			(ans *= 2) %= mod;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	const int n = (int) s.size();
	const int offset = 1000;

	ll ans = 0;
	for (int k = 1; k < n; ++k) {

		vector<pair<int, int>> eqConstr, ineqConstr, valConstr;
		for (int i = 0; i < n - k; ++i)
			valConstr.emplace_back(offset + i, 0);
		valConstr.emplace_back(0, 1);
		valConstr.emplace_back(offset + n - k, 1);

		for (int i = 0, j = n - 1; i <= j; ++i, --j)
			eqConstr.emplace_back(i, j);
		for (int i = offset + n - k, j = offset + n - 1; i <= j; ++i, --j)
			eqConstr.emplace_back(i, j);

		for (int i = 0; i < n; ++i)
			if (s[i] != '?')
				(s[i] == '0' ? eqConstr : ineqConstr).emplace_back(i, offset + i);

		const ll inc = f(eqConstr, ineqConstr, valConstr);
		(ans += inc) %= mod;
		cerr << inc << endl;

	}
	cout << ans;
	return 0;
}