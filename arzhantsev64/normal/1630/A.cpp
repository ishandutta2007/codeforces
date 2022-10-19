#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define x first
#define y second

void solve() {
	int n, k;
	cin >> n >> k;
	if (k == n - 1) {
		if (n <= 4) {
			cout << -1 << '\n';
		} else {
			int p = n - 1;
			int s = 0;
			cout << p << ' ' << p - 1 << '\n';
			s += p & (p - 1);
			cout << 1 << ' ' << p - 2 << '\n';
			s += 1 & (p - 2);
			cout << 0 << ' ' << 2 << '\n';
			s += 0 & 2;
			for (int i = 3; i < n / 2; ++i) {
				int a = i;
				int b = i ^ p;
				cout << a << ' ' << b << '\n';
				s += a & b;
			}
			// cout << "SUM " << s << endl;
		}
	} else if (k == 0) {
		int p = n - 1;
		int s = 0;
		for (int i = 0; i < n / 2; ++i) {
			int a = i;
			int b = i ^ p;
			cout << a << ' ' << b << '\n';
			s += a & b;
		}
		// cout << "SUM " << s << endl;
	} else {
		int p = n - 1;
		int s = 0;
		cout << k << ' ' << p << '\n';
		s += k & p;
		cout << 0 << ' ' << (k ^ p) << '\n';
		s += 0 & (k ^ p);
		for (int i = 1; i < n / 2; ++i) {
			int a = i;
			int b = i ^ p;
			if (a != k && b != k) {
				cout << a << ' ' << b << '\n';
				s += a & b;
			}
		}
		// cout << "SUM " << s << endl;
	}
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