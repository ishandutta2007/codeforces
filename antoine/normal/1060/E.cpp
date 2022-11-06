#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> adj[(int) 2e5];
int sz[(int) 2e5];
array<ll, 2> cnt[(int) 2e5];
ll ans = 0;

/*
3
1 2
1 3

 */
void dfs(const int u, const int parent) {
	sz[u] = 1;

	for (const int &v : adj[u])
		if (v != parent) {
			dfs(v, u);
			sz[u] += sz[v];

			ans += 2 * cnt[v][1] * ll(n - cnt[v][1] - cnt[v][0]);
			ans += 2 * cnt[v][0]; // from u

			cnt[u][0] += cnt[v][1];
			cnt[u][1] += cnt[v][0];
		}

	for (const int &v : adj[u])
		if (v != parent) {
			ans += cnt[v][0] * (cnt[u][0] - cnt[v][1]);
			ans += cnt[v][1] * (cnt[u][1] - cnt[v][0]);
			ans += cnt[v][0] * (cnt[u][1] - cnt[v][0]);
		}

	cnt[u][0]++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, -1);

	assert(ans % 2 == 0);
	cout << (ans / 2) << '\n';
	return 0;
}