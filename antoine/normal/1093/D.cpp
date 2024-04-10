#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 3e5 + 9;
const int mod = 998244353;
ll p2[MaxN + 9];
vector<int> adj[MaxN + 9];
int color[MaxN + 9];

bool dfs(const int u, array<ll, 2> &cnt) {
	++cnt[color[u]];
	for (const int &v : adj[u]) {
		if (color[v] == -1) {
			color[v] = !color[u];
			if (!dfs(v, cnt))
				return false;
		} else if (color[v] == color[u])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p2[0] = 1;
	for (int i = 1; i <= MaxN; ++i)
		p2[i] = (p2[i - 1] << 1) % mod;

	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ll ans = 1;
		fill(color, color + n + 5, -1);
		for (int i = 1; i <= n; ++i)
			if (color[i] == -1) {
				array<ll, 2> cnt { 0, 0 };
				color[i] = 0;
				if (!dfs(i, cnt)) {
					ans = 0;
					break;
				}
				ans *= (p2[cnt[0]] + p2[cnt[1]]);
				ans %= mod;
			}

		cout << ans << '\n';

		for(int i = 0; i <= n; ++i)
			adj[i].clear();
	}
	return 0;
}