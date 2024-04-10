#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;

typedef long long ll;

ll g(ll k) {
	return k ? g(k - 1) * 10 + 9 : 0;
}

ll g(ll k, ll leading) {
	ll num = g(k);
	if (leading)
		while (leading <= num)
			leading *= 10;
	return leading + num;
}

ll f(ll n) {
	ll lo = 1;
	ll hi = 11;
	while (lo < hi) {
		ll mid = (lo + hi + 1) / 2;
		if ((g(mid) + 1) / 2 > n)
			hi = mid - 1;
		else
			lo = mid;
	}
	return lo;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	if (n <= 4) {
		cout << n*(n - 1) / 2;
		return 0;
	}

	ll ans = 0;
	for (int leading = 0; leading < 9; ++leading) {
		ll sum = g(f(n), leading);
		// x >= 1, x <= ub, sum - x > ub, sum - x <= n
		// x >= 1, x <= sum / 2, x >= sum - n 
		ll l = max(1ll, sum - n);
		ll r = sum / 2;
		if (l <= r)
			ans += r - l + 1;
	}
	cout << ans;
	return 0;
}