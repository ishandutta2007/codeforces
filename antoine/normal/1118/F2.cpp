#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

ll modInv(const ll x) {
	return modPow(x, mod - 2);
}

const int MxN = (int) 3e5 + 9;
int color[MxN + 9];
int depth[MxN + 9];
vector<int> parent[MxN + 9];
vector<int> adj[MxN + 9];
ll dp[MxN + 9][2];

struct DSU {
	vector<int> parent;

	DSU(int n) {
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
		if (depth[u] > depth[v])
			swap(u, v);
		parent[v] = u;
		return true;
	}
} dsu(MxN + 9);

void dfsPrec(const int u, const int p) {
	for (auto &&v : adj[u])
		if (v != p) {
			depth[v] = depth[u] + 1;
			parent[v] = {u};
			for (int i = 0; i < (int) parent[parent[v][i]].size(); ++i)
				parent[v].push_back(parent[parent[v][i]][i]);
			dfsPrec(v, u);
		}
}

int lca(int u, int v) {
	int diff = depth[u] - depth[v];
	if (diff < 0) {
		swap(u, v);
		diff = -diff;
	}
	for (int i = 0; diff; ++i)
		if (diff & (1 << i)) {
			diff ^= 1 << i;
			u = parent[u][i];
		}

	if (u == v)
		return u;

	for (int i = (int) parent[u].size() - 1; i >= 0; --i)
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
			i = min(i, (int) parent[u].size());
		}

	return parent[u][0];
}

ll dfs(const int u, const bool b, const int parent) {
	if (dp[u][b] != -1)
		return dp[u][b];

	ll &ans = dp[u][b] = 0;

	if (color[u] && !b)
		return ans = 0;

	ll p = 1;

	for (const int &v : adj[u])
		if (v != parent) {
			p *= dfs(v, false, u) + dfs(v, true, u);
			p %= mod;
		}

	if ((color[u] && b) || (!color[u] && !b))
		return ans = p;

	for (const int &v : adj[u])
		if (v != parent) {
			ans += p * modInv(dfs(v, false, u) + dfs(v, true, u)) % mod * dfs(v, true, u) % mod;
			ans %= mod;
		}
	return ans;
}

void mergePath(int x, int u) {
	for (;;) {
		x = dsu.find(x);
		u = dsu.find(u);
		if (x == u)
			break;
		assert(depth[x] < depth[u]);
		dsu.merge(u, parent[u][0]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> color[i];

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfsPrec(1, -1);

	{
		vector<vector<int>> groups(k + 1);
		for (int i = 1; i <= n; ++i)
			if (color[i])
				groups[color[i]].push_back(i);

		for (vector<int> &v : groups) {
			for (int i = 0; i + 1 < (int) v.size(); ++i) {
				const int x = lca(v[i], v[i + 1]);
				mergePath(x, v[i]);
				mergePath(x, v[i + 1]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (color[i]) {
			const int x = dsu.find(i);
			if (!color[x])
				color[x] = color[i];
			else if (color[x] != color[i]) {
				cout << 0;
				cerr << "A";
				return 0;
			}
		}
	}

	{
		vector<set<int>> newAdj(n + 1);

		for (int i = 1; i <= n; ++i)
			for (int v : adj[i]) {
				int u = dsu.find(i);
				v = dsu.find(v);
				if (u == v)
					continue;
				newAdj[u].insert(v);
				newAdj[v].insert(u);
			}

		for (int i = 1; i <= n; ++i)
			adj[i] = vector<int>(newAdj[i].begin(), newAdj[i].end());
	}

	int root = 0;
	for (int i = 1; i <= n; ++i)
		if (!adj[i].empty()) {
			root = i;
			break;
		}
	if (!root) {
		cout << 1;
		cerr << "B";
	}

	memset(dp, -1, sizeof dp);
	ll ans = dfs(root, true, -1);
	cout << ((ans % mod) + mod) % mod;
	return 0;
}