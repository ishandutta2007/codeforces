#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

void solve() {

	int n, k;
	cin >> n >> k;

	unordered_set<int> s;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	for (int x : s)
		if (s.find(x + k) != s.end()) {
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