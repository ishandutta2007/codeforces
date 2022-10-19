#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	int u, v;
	cin >> u >> v;
	int p;
	cin >> p;
	int ans = 1e18;
	for (int i = 0; i < n - 1; ++i) {
		int x;
		cin >> x;
		int d = abs(p - x);
		p = x;
		if (d >= 2)
			ans = min((int)0, ans);
		else if (d == 1)
			ans = min(min(u, v), ans);
		else if (d == 0)
			ans = min(v + min(u, v), ans);
	}
	cout << ans << '\n';	
}

signed main() {
	int t;
	cin >> t;
	while (t--)
		solve();
}