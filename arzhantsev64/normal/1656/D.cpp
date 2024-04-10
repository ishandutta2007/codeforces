#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

#define int long long

using namespace std;

int check(int n) {
	if (n == 1) {
		return -1;
	}
	if (n % 2 == 1) {
		return 2;
	}
	int m = 2 * n;
	int p = 1;
	while (m % 2 == 0) {
		p *= 2;
		m /= 2;
	}
	if (m == 1) {
		return -1;
	}

	return min(m, p);
}

void solve() {

	int n;
	cin >> n;

	if (n == 1) {
		cout << "-1\n";
		return;
	}
	if (n % 2 == 1) {
		cout << "2\n";
		return;
	}
	int m = 2 * n;
	int p = 1;
	while (m % 2 == 0) {
		p *= 2;
		m /= 2;
	}
	if (m == 1) {
		cout << "-1\n";
		return;
	}

	cout << min(m, p) << '\n';
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