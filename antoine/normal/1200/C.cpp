#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, q;

ll f(ll t, ll x) {
	assert(t == 1 || t == 2);
	return (x - 1) / ((t == 1 ? n : m) / __gcd(n, m));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m >> q;
	while (q--) {
		ll t1, x1, t2, x2;
		cin >> t1 >> x1 >> t2 >> x2;
		cout << (f(t1, x1) == f(t2, x2) ? "YES" : "NO") << '\n';
	}
	return 0;
}