#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f() {

	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	for (ll&x : a)
		cin >> x;

	for (int i = 0; i + 1 < n; ++i) {
		const ll l = max(0LL, a[i + 1] - k);
		if (a[i] >= l)
			m += a[i] - l;
		else {
			m -= l - a[i];
			if (m < 0)
				return false;
		}
	}
	return true;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		cout << (f() ? "YES" : "NO") << '\n';
	}

	return 0;
}