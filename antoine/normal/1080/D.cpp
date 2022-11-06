#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sq(ll x) {
	return x * x;
}

ll f(const int x) {
	return x == 0 ? 0 : 1 + (f(x - 1) << 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		ll n, k;
		cin >> n >> k;

		if ((n <= 2 && k == 3) || (n <= 31 && k > f(n))) {
			cout << "NO\n";
			continue;
		}

		int lo = 1;
		int hi = 31;
		while (lo < hi) {
			const int mid = (lo + hi + 1) >> 1;
			if (f(mid) <= k)
				lo = mid;
			else
				hi = mid - 1;
		}

		assert(++hi <= 31);
		const int res = llabs(k - f(lo)) <= llabs(k - f(hi)) ? lo : hi;
		cout << "YES " << n - res << '\n';
	}
	return 0;
}