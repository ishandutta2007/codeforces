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

using namespace std;
typedef long long ll;

bool isPrime(int i) {
	for (int j = 2; j < i; ++j)
		if (i%j == 0)
			return false;
	return true;
}

vector<int> getPrimes(int limit) {
	vector<int> res;
	for (int i = 2; i < limit; ++i)
		if (isPrime(i))
			res.push_back(i);
	return res;
}

array<vector<int>, 2> incEx(int limit) {
	auto primes = getPrimes(limit);
	vector<int> inc = primes, ex;
	for (int i = 0; i < primes.size(); ++i)
		for (int j = 0; j < i; ++j)
			if (primes[i] * primes[j] <= limit) {
				ex.push_back(primes[i] * primes[j]);
				for (int k = 0; k < j; ++k)
					if (primes[i] * primes[j] * primes[k] <= limit)
						inc.push_back(primes[i] * primes[j] * primes[k]);
			}
	sort(inc.begin(), inc.end());
	sort(ex.begin(), ex.end());
	return{ inc, ex };
}

ll llPow(ll x, int k) {
	ll res = 1;
	for (; k; k >>= 1) {
		if (k & 1) {
			if ((double)res * x > 1e18)
				return 2e18;
			res = res * x;
		}
		if (k >> 1) {
			if (x > 1e9)
				return 2e18;
			x *= x;
		}
	}
	return res;
}

ll kthRoot(const ll x, const int k) {
	//cout << "debug " << x << ' ' << k << ' ' << lo << '\n';

	return pow((long double)x + 0.5, 1.0 / k);
	/*
	ll lo = 0;
	ll hi = min<ll>(1e9 + 1, x);
	while (lo < hi) {
		ll mid = (lo + hi + 1) >> 1;
		if (llPow(mid, k) > x)
			hi = mid - 1;
		else
			lo = mid;
	}
	return lo;
	*/
}

ll f(const ll m, const array<vector<int>, 2> &ie) {
	if (m <= 1)
		return m;
	ll res = 1;
	for (auto &&x : ie[0])
		res += max(0ll, kthRoot(m, x) - 1);
	for (auto &&x : ie[1])
		res -= max(0ll, kthRoot(m, x) - 1);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const auto ie = incEx(64);
	
	int Q;
	cin >> Q;
	while (Q--) {
		ll l, r;
		cin >> l >> r;
		cout << f(r, ie) - f(l - 1, ie) << '\n';
	}
	return 0;
}