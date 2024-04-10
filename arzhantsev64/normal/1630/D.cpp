#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define x first
#define y second

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int d;
	cin >> d;
	for (int i = 0; i < m - 1; ++i) {
		int x;
		cin >> x;
		d = __gcd(d, x);
	}
	vector<int> minn(d, 1e18);
	for (int i = 0; i < n; ++i)
		minn[i % d] = min(minn[i % d], abs(a[i]));
	vector<int> have(d);
	for (int i = 0; i < n; ++i)
		if (a[i] < 0)
			have[i % d] ^= 1;
	int s = 0;
	for (int i = 0; i < n; ++i)
		s += abs(a[i]);

	int s1 = 0;
	for (int i = 0; i < d; ++i)
		if (have[i])
			s1 += abs(minn[i]);

	int s2 = 0;
	for (int i = 0; i < d; ++i)
		if (have[i] == 0)
			s2 += abs(minn[i]);

	cout << s - 2 * min(s1, s2) << '\n';
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