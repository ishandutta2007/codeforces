#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define x first
#define y second

void solve() {
	int n;
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s += x;
	}
	if (s % n == 0)
		cout << 0 << '\n';
	else
		cout << 1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}