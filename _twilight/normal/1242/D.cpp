#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;
ll n, k, k2, _k2;

ll I(ll id) {
	if (id == 0) {
		return _k2 = 1ll * k * (k + 1) >> 1;
	}
	ll y = I(id / k);
	ll x = id / k;
	int l = id % k;
	int offset = 0;
	ll R = x * k2 + 1ll * k * (l + 1);
	if (R >= y) {
		offset = min(R - y + 1, k);
	}
	return k2 * id - l + _k2 + offset; 
}

int main() {
	scanf("%d\n", &T);
	while (T--) {
		scanf("%lld%lld", &n, &k);
		k2 = 1ll * k * k + 1;
		ll id = (n - 1) / k2;
		ll t = I(id), ans = 0;
		ll L = id * k2 + 1;
		if (t == n) {
			ans = (id + 1) * (k + 1); 
		} else {
			ll d = n - L - (n > t);
			int l = d / k;
			ans = (id * k + l) * (k + 1) + d % k + 1;
		}
		printf("%lld\n", ans);
	} 
	return 0;
}