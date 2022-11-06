#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 998244353;

ll iPow(ll x, int n) {
	assert(n >= 2);
	ll res = 1;
	while (n--)
		res *= x;
	return res;
}

ll nthRoot(ll x, int n) {
	assert(n >= 2);
	ll r = pow(x, 1.0 / n);
	assert(r >= 0);
	while (iPow(r, n) < x)
		++r;
	while (iPow(r, n) > x)
		--r;
	return iPow(r, n) == x ? r : 1;
}

void filterPrimes(set<ll> &s) {
	for (auto it = s.begin(); it != s.end();) {
		if (*it == 1)
			it = s.erase(it);
		else {
			bool found = false;
			for (auto &&x : s) {
				if (x >= *it)
					break;
				if (*it % x == 0 && x != 1) {
					found = true;
					break;
				}
			}
			if (found)
				it = s.erase(it);
			else
				++it;
		}
	}
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	set<ll> s = { 1 };
	vector<ll> a(n);

	for (int i = 0; i < a.size(); ++i) {
		cin >> a[i];
		s.insert(a[i]);
		for (int n = 4; n >= 2; --n) {
			const ll r = nthRoot(a[i], n);
			s.insert(r);
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			const ll g = gcd(a[i], a[j]);
			s.insert(g);
			s.insert(a[i] / g);
			s.insert(a[j] / g);
		}

	filterPrimes(s);
	for(auto &&x : a)
		s.erase(x);

	map<ll, ll> occ;

	for (auto &&x : a) {
		bool ok = false;
		for (auto &&d : s)
			while (x % d == 0) {
				x /= d;
				++occ[d];
				ok = true;
			}
		if (ok) {
			if (x != 1)
				cerr << x << endl;
			assert(x == 1);
		} else {
			++occ[-2 * x];
			++occ[-2 * x - 1];
		}
	}

	ll ans = 1;
	for (auto &&x : occ) {
		// cerr << x.first << ' ' << x.second << '\n';
		ans *= x.second + 1;
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}