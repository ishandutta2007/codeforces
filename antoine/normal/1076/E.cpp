#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 3e5 + 9;

struct FT {
	vector<ll> v;
	FT(int n) :
			v(vector<ll>(n + 1, 0)) {
	}
	void update(int i, const int a) {
		for (++i; i < (int) v.size(); i += i & -i)
			v[i] += a;
	}
	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < (int )v.size() - 1);
		ll sum = 0;
		for (++i; i; i -= i & -i)
			sum += v[i];
		return sum;
	}
} ft(MaxN + 9);

vector<int> adj[MaxN + 9];
vector<pair<int, int>> updates[MaxN + 9];
ll ans[MaxN + 9];

void dfs(const int u, const int parent, const int depth) {
	for (auto &&up : updates[u]) {
		ft.update(depth, up.second);
		ft.update(depth + up.first + 1, -up.second);
	}

	ans[u] = ft.query(depth);

	for (const int &v : adj[u])
		if (v != parent)
			dfs(v, u, depth + 1);

	for (auto &&up : updates[u]) {
		ft.update(depth, -up.second);
		ft.update(depth + up.first + 1, up.second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int v, d, x;
		cin >> v >> d >> x;
		updates[v].emplace_back(d, x);
	}

	dfs(1, -1, 0);

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}