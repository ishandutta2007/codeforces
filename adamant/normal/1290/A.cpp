#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	m--;
	k = min(m, k);
	int ans = 0;
	for(int i = 0; i <= k; i++) {
		int cur = 1e12;
		for(int j = i; j <= m - (k - i); j++) {
			cur = min(cur, max(a[j], a[n - (m - j) - 1]));
		}
		ans = max(ans, cur);
	}
	cout << ans << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}