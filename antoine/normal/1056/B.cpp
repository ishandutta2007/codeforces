#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sq(ll x) {
	return x * x;
}

ll occ[1009];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m;
	cin >> n >> m;

	for (ll i = 0; i < min(n, m); ++i) {
		const ll x = sq(i + 1) % m;
		occ[x] += (n / m) + (i < n % m);
	}

	ll ans = 0;

	for (ll i = 0; i < m; ++i)
		if ((i + i) % m == 0)
			ans += occ[i] + occ[i] * (occ[i] - 1);

	for (ll i = 0; i < m; ++i)
		for (ll j = i + 1; j < m; ++j)
			if ((i + j) % m == 0)
				ans += occ[i] * occ[j] * 2LL;

	cout << ans << endl;
	return 0;
}