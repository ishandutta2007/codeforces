// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) {
		cin >> i;
	}

	mt19937 gen(time(NULL));
	ll ans = LLONG_MAX;
	while (clock() < 2 * CLOCKS_PER_SEC) {
		int i = gen() % n;
		vector<ll> divs;
		for (ll x = max(2LL, a[i] - 1); x <= a[i] + 1; x++) {
			ll m = x;
			for (ll d = 2; d * d <= x; d++) {
				if (m % d == 0) {
					divs.push_back(d);
				}
				while (m % d == 0) {
					m /= d;
				}
			}
			if (m > 1) {
				divs.push_back(m);
			}
		}
	
		for (ll g : divs) {
			ll sum = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] < g) {
					sum += g - a[i];
				} else {
					sum += min(a[i] % g, g - a[i] % g);
				}
			}
			ans = min(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}