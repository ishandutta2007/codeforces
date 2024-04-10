#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 1e5 + 9;
vector<int> adj[MaxN + 9];
int sz[MaxN + 9];
bool dead[MaxN + 9];

int OneCentroid(const int root) {
	function<void(int, int)> get_sz = [&](int u, int prev) {
		sz[u] = 1;
		for (const int &v : adj[u]) if (v != prev && !dead[v]) {
			get_sz(v, u);
			sz[u] += sz[v];
		}
	};
	get_sz(root, -1);
	function<int(int, int)> dfs = [&](int u, int prev) {
		for (const int &v : adj[u]) if (v != prev && !dead[v]) {
			if (sz[v] > sz[root] / 2) {
				return dfs(v, u);
			}
		}
		return u;
	};
	return dfs(root, -1);
}

void dfs(const int u, const int parent, const int depth, vector<int> &occ) {
	if (depth >= (int) occ.size())
		occ.resize(depth + 1, 0);
	++occ[depth];
	for (const int &v : adj[u])
		if (v != parent && !dead[v])
			dfs(v, u, depth + 1, occ);
}

ll f(const int M, vector<int> &occ) {
	static int ps[MaxN + 9];
	partial_sum(occ.begin(), occ.end(), ps);

	ll res = 0;
	for (int i = min(M, (int) occ.size() - 1); i >= 0; --i) {
		res += (ll) occ[i] * ps[min(M - i, (int) occ.size() - 1)];
		if(i + i <= M)
			res -= occ[i];
	}
	assert(!(res & 1));
	return res >> 1;
}

ll calc(const int M, const int c) {
	ll res = 0;
	vector<int> occ;
	for (const int &v : adj[c])
		if (!dead[v]) {
			vector<int> temp;
			dfs(v, c, 1, temp);
			res -= f(M, temp);

			if (temp.size() > occ.size())
				occ.resize(temp.size(), 0);
			for (int i = 0; i < (int) temp.size(); ++i)
				occ[i] += temp[i];
		}

	res += accumulate(occ.begin(), occ.begin() + min(M + 1, (int) occ.size()),
			0);
	res += f(M, occ);
	return res;
}

ll CentroidDecomposition(const int M /* spe */) {
	ll ans = 0; // spe
	function<void(int)> rec = [&](int start) {
		const int c = OneCentroid(start);
		ans += calc(M, c); // spe

		dead[c] = true;
		for (auto u : adj[c]) if (!dead[u]) rec(u);

		/*
		 compute something with the centroid
		 */
		dead[c] = false;
	};
	rec(adj[0].empty() /* root: 0 or 1 */);
	return ans; // spe
}

ll f(const int M) {
	if (M <= 0)
		return 0LL;
	memset(sz, 0, sizeof sz);
	memset(dead, 0, sizeof dead);
	return CentroidDecomposition(M);
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	int n, K;
	cin >> n >> K;
	fill(adj, adj + n + 1, vector<int>());

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	const ll res = f(K) - f(K - 1);
	cout << res << '\n';
	return 0;
}