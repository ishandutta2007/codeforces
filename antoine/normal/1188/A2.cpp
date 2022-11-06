#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 1009;
vector<pair<int, ll>> adj[MxN + 9];

struct Res {
	vector<array<ll, 3>> v;
	void insert(ll x, ll y, ll z) {
		v.push_back(array<ll, 3> { x, y, -z });
	}
	~Res() {
		if (v.empty())
			return;
		cout << v.size() << '\n';
		for (auto e : v) {
			for (int x : e)
				cout << x << ' ';
			cout << '\n';
		}
	}
} res;

int dfs2(const int u, const int parent) {
	for (auto e : adj[u])
		if (e.first != parent)
			return dfs2(e.first, u);
	assert(adj[u].size() == 1);
	return u;
}
int dfs(const int u, const ll weight, int z = -1) {
	if (adj[u].empty())
		return u;
	assert(weight % 2 == 0);
	assert(adj[u].size() >= 2);

	vector<int> leaves;
	if (z == -1) {
		for (auto e : adj[u])
			leaves.push_back(dfs2(e.first, u));
		z = leaves.back();
		rotate(leaves.begin(), leaves.begin() + 1, leaves.end());
		reverse(leaves.begin(), leaves.end());
	}

	for (auto &&e : adj[u]) {
		int &v = e.first;
		const ll w = e.second;
		adj[v].erase(find(adj[v].begin(), adj[v].end(), pair<int, ll> { u, w }));
		v = dfs(v, w, leaves.size() ? leaves.back() : z);
		if (leaves.size())
			leaves.pop_back();
	}
	while (adj[u].size() > 2) {
		const ll w = adj[u].back().second;
		res.insert(adj[u].front().first, adj[u].back().first, -w);
		adj[u].front().second -= w;
		adj[u].pop_back();
	}
	assert(adj[u].size() == 2);
	const ll d = (weight - (adj[u][0].second - adj[u][1].second)) / 2;

	res.insert(adj[u][0].first, z, d);
	res.insert(adj[u][1].first, z, -d);
	adj[u][0].second += d;
	adj[u][1].second -= d;
	res.insert(adj[u][0].first, adj[u][1].first, -adj[u][1].second);
	adj[u][0].second -= adj[u][1].second;
	adj[u][1].second -= adj[u][1].second;
	assert(adj[u][0].second == weight);
	assert(adj[u][1].second == 0);
	return adj[u][0].first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back( { v, w });
		adj[v].push_back( { u, w });
	}

	int root = -1;

	for (int i = 1; i <= n; ++i)
		if (adj[i].size() == 2) {
			cout << "NO";
			return 0;
		} else if (adj[i].size() >= 3)
			root = i;

	cout << "YES\n";

	assert((n == 2) == (root == -1));
	if (root == -1) {
		res.insert(1, 2, -adj[1][0].second);
		return 0;
	}

	dfs(root, 0);
	return 0;
}