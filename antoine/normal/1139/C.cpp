#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

const int mod = (int)1e9 + 7;
ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	DSU dsu(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, x;
		cin >> u >> v >> x;
		--u, --v;
		if (!x)
			dsu.merge(u, v);
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i != dsu.find(i))
			continue;
		const ll x = dsu.rank[i];
		ans += modPow(x, k);
		ans %= mod;
	}
	ans = modPow(n, k) - ans;
	cout << (ans % mod + mod) % mod;
	return 0;
}