#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int N = 1'010'001;
using Bs = bitset<N>;

vector<int> a[N];
int sz[N];
int n;

void dfs(int v, int p = -1) {
	sz[v] = 1;
	for (int x : a[v]) {
		if (x != p) {
			dfs(x, v);
			sz[v] += sz[x];
		}
	}
}

vector<long long> dp[N];

long long dfs_down(int v, int p = -1) {
	long long res = 1;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p) {
			continue;
		}
		dp[v][i] = dfs_down(a[v][i], v);
		res += dp[v][i] + sz[a[v][i]];
	}
	return res;
}

void dfs_up(int v, int p, long long from_up) {
	long long sum = from_up;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p) {
			dp[v][i] = from_up;
		} else {
			sum += dp[v][i];
		}
	}
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] != p) {
			dfs_up(a[v][i], v, sum - dp[v][i] + n - sz[a[v][i]]);
		}
	}
}

void solve() {
	n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = i + 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0, -1);

	int root = 0;
	while (true) {
		int nx = -1;
		for (int v : a[root]) {
			if (sz[v] > sz[root]) {
				continue;
			}
			if (sz[v] > n / 2) {
				nx = v;
			}
		}
		if (nx == -1) {
			break;
		} else {
			root = nx;
		}
	}
	dfs(root, -1);

	for (int i = 0; i < n; ++i) {
		dp[i].resize(a[i].size());
	}
	dfs_down(root, -1);
	dfs_up(root, -1, 0);

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < (int)a[i].size(); ++j) {
	// 		cerr << i + 1 << " -> " << a[i][j] + 1 << ": " << dp[i][j] << "\n";
	// 	}
	// }

	long long ans = 0;
	// for (int i = 0; i < n; ++i) {
	// 	if (i != root) {
	// 		long long cur = 0;
	// 		for (int j = 0; j < (int)a[i].size(); ++j) {
	// 			cur += dp[i][j];
	// 		}
	// 		cur += 1ll * sz[i] * (n - sz[i] + 1);
	// 		ans = max(ans, cur);
	// 	}
	// }

	vector<int> cnt(n);
	for (int x : a[root]) {
		cnt[sz[x]] += 1;
	}
	Bs b = {};
	b[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (!cnt[i]) {
			continue;
		}
		int tmp = (cnt[i] - 1) / 2;
		cnt[i] -= tmp * 2;
		if (tmp) {
			cnt[2 * i] += tmp;
		}
		for (int j = 0; j < cnt[i]; ++j) {
			b |= b << i;
		}
	}
	int opt = (n - 1) / 2;
	while (!b[opt]) {
		--opt;
	}
	{
		long long cur = 0;
		for (int i = 0; i < (int)a[root].size(); ++i) {
			cur += dp[root][i];
		}
		cur += 1ll * (opt + 1) * (n - opt);
		ans = max(ans, cur);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}