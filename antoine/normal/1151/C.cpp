#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

ll sum(ll x) {
	assert(x >= 1);
	x %= mod;
	return x * (x + 1) / 2;
}

ll sumEven(ll x) {
	assert(x >= 2 && x % 2 == 0);
	return 2 * sum(x / 2);
}

ll sumOdd(ll x) {
	assert(x >= 1 && x % 2 == 1);
	ll cnt = (x + 1) / 2;
	return sumEven(x + 1) - cnt;
}

ll sumEven(ll l, ll r) {
	return sumEven(r) - (l == 2 ? 0 : sumEven(l - 2));
}
ll sumOdd(ll l, ll r) {
	return sumOdd(r) - (l == 1 ? 0 : sumOdd(l - 2));
}

ll f(const ll n) {
	bool odd = true;
	ll sz = 1;
	ll start = 1;

	ll currOdd = 1;
	ll currEven = 2;

	ll res = 0;
	while (start <= n) {
		sz = min(sz, n - start + 1);

		if (odd) {
			res += sumOdd(currOdd, currOdd + 2 * (sz - 1));
			currOdd += 2 * sz;
		} else {
			res += sumEven(currEven, currEven + 2 * (sz - 1));
			currEven += 2 * sz;
		}

		odd = !odd;
		start += sz;
		sz <<= 1;
		res %= mod;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll l, r;
	cin >> l >> r;

	ll res = f(r) - (l - 1 ? f(l - 1) : 0);
	cout << (res % mod + mod) % mod;
	return 0;
}