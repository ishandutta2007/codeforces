#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = (int) 1e9 + 7;
const int MxN = (int) 1e5 + 9;
vector<int> adj[MxN + 9];
ll val[MxN + 9], ans = 0;

void dfs(const int u, const int parent, vector<pair<ll, int>> v) {
	v.push_back( { val[u], 1 });
	for (auto &&e : v) {
		e.first = __gcd(e.first, val[u]);
		(ans += e.first * e.second) %= mod;
		// cerr << u << ' ' << e.first << '\n';
	}
	auto i = v.begin();
	for (auto j = v.begin() + 1; j != v.end(); ++j)
		if (i->first == j->first)
			i->second += j->second;
		else
			*++i = move(*j);
	v.erase(i + 1, v.end());

	for (const int x : adj[u])
		if (x != parent)
			dfs(x, u, v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> val[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1, { });
	cout << ans;
	return 0;
}