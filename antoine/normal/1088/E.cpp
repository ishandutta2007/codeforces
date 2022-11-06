#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Fract {
	ll a = 0, b = 1;
};

const int MaxN = (int) 3e5 + 9;
ll a[MaxN + 9];
vector<int> adj[MaxN + 9];
ll ans1 = -(1LL << 30), ans2 = 1;

ll dfs1(const int u, const int p) {
	ll res = a[u];
	for (const int &v : adj[u])
		if (v != p)
			res += dfs1(v, u);

	ans1 = max(ans1, res);
	return max(0LL, res);
}

ll dfs2(const int u, const int p) {
	ll res = a[u];
	for (const int &v : adj[u])
		if (v != p)
			res += dfs2(v, u);

	if (res == ans1) {
		++ans2;
		return 0;
	}
	return max(0LL, res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (any_of(a + 1, a + 1 + n, [](const int &x) {
		return x > 0;
	})) {
		dfs1(1, -1);
		ans2 = 0;
		dfs2(1, -1);
		ans1 *= ans2;
	} else {
		cerr << "spe case\n";
		sort(a + 1, a + 1 + n);
		reverse(a + 1, a + 1 + n);
		partial_sum(a, a + 1 + n, a);

		for (int i = 1; i <= n; ++i) {
			if (a[i] - a[i - 1] == a[1]) {
				tie(ans1, ans2) = pair<ll, ll>{a[i], i};
			}
		}
	}

	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}