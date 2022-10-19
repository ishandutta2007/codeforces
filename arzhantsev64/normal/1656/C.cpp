#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

void solve() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	bool has_1 = false;
	bool has_diff_1 = false;
	for (int i = 0; i < n; ++i) {
		if (v[i] == 1)
			has_1 = 1;
		if (i + 1 < n && v[i + 1] - v[i] == 1)
			has_diff_1 = 1;
	}
	if (!has_1) {
		cout << "YES\n";
		return;
	}
	if (!has_diff_1) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}