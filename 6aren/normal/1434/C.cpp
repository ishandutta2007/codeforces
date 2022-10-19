#include<bits/stdc++.h>
using namespace std;

#define int long long

int a, b, c, d;


long long summ(int l, int r, int d) {
	if (l == 0) {
		r /= d;
		return 1LL * r * (r + 1) / 2 * d;
	}

	return summ(0, r, d) - summ(0, l - d, d);
}


long long calc(int u) {

	if (u == 1)
		return -a;

	long long res = -u * a;

	if (d < c) {
		int l = d;

		int foo = min(u - 1, c / d);

		int r = foo * d;

		long long sum = summ(l, r, d); 

		res += 1LL * b * sum;

		u -= foo;
	}

	res += 1LL * b * c * (u - 1);

	return res;

}

void solve() {

	cin >> a >> b >> c >> d;


	int lo = 1, hi = 1e7;

	while (hi - lo >= 2) {
		int u = (lo + lo + hi) / 3;
		int v = (lo + hi + hi) / 3;

		if (calc(u) > calc(v)) {
			lo = u + 1;
		} else hi = v;
	}

	if (hi == 1e7) {
		cout << -1 << '\n';
		return;
	}

	// cout << lo << ' ' << hi << endl;

	long long ans = 0;

	for (int i = lo; i <= hi; i++) {
		ans = min(ans, calc(i));
	}

	cout << -ans << '\n';

	return;

}


signed main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;

	cin >> ntest;

	while (ntest--) {
		solve();
	}

	return 0;
}