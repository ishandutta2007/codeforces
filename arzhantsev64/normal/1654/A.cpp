#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	int maxx1 = -1;
	int maxx2 = -1;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (v[i] > maxx1) {
			maxx2 = maxx1;
			maxx1 = v[i];
		} else if (v[i] > maxx2) {
			maxx2 = v[i];
		}
	}
	cout << maxx1 + maxx2 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}