#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;
int c[MxN + 9][3];
vector<int> adj[MxN + 9];
int pos[MxN + 9];

void dfs(const int u) {
	if (adj[u].size() > 1) {
		cout << -1;
		exit(0);
	}
	for (const int v : adj[u]) {
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		pos[v] = (pos[u] + 1) % 3;
		dfs(v);
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	for (int j = 0; j < 3; ++j)
		for (int i = 1; i <= n; ++i)
			cin >> c[i][j];

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 1; i <= n; ++i)
		if (adj[i].size() == 1) {
			dfs(i);
			break;
		}

	ll ans = (ll) 1e18;

	{
		vector<int> perm { 0, 1, 2 };
		do {
			ll res = 0;
			for (int i = 1; i <= n; ++i)
				res += c[i][perm[pos[i]]];
			ans = min(ans, res);
		} while (next_permutation(perm.begin(), perm.end()));
	}
	cout << ans << '\n';

	{
		vector<int> perm { 0, 1, 2 };
		do {
			ll res = 0;
			for (int i = 1; i <= n; ++i)
				res += c[i][perm[pos[i]]];
			if (res == ans) {
				for (int i = 1; i <= n; ++i)
					cout << perm[pos[i]] + 1 << ' ';
				return 0;
			}
		} while (next_permutation(perm.begin(), perm.end()));
	}
	return 0;
}