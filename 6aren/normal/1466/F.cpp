#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

#define int int32_t

int p[N];

int root(int x) {
	return (p[x] == x ? x : p[x] = root(p[x]));
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;

	// cout << (sizeof p) << endl;

	for (int i = 0; i <= m; i++) {
		p[i] = i;
	}

	int cnt = 0;

	vector<int> res;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int u, v;
		if (k == 2) {
			cin >> u >> v;
		} else {
			u = 0;
			cin >> v;
		}
		u = root(u);
		v = root(v);
		if (u != v) {
			cnt++;
			res.push_back(i);
			p[u] = v;
		}
	}

	const int MOD = 1000000007;

	int ans = 1;
	for (int i = 1; i <= cnt; i++) {
		ans = (ans << 1) % MOD;
	}

	cout << ans << ' ' << cnt << '\n';
	for (int e : res) cout << e << ' ';
	cout << '\n';

	return 0;
}