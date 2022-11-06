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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;


const ll mod = 998244353;
struct Eq {
	ll a = 0, b = 0, c = 0;

	void add(ll o0, ll x0) {
		o0 %= mod;
		x0 %= mod;
		// (x - x0)^2 + o0
		// (x^2 - 2*x*x0 + x0^2) + o0
		a += 1;
		b += -2 * x0;
		c += (x0 * x0) % mod + o0;
		// cerr << "abc: " << a << ' ' << b << ' ' << c << endl;
		// cerr << "abc: " << a << ' ' << b << ' ' << c << endl;
		a %= mod, b %= mod, c %= mod;
	}

	ll eval(ll x) const {
		ll res = a*x % mod * x % mod + b*x % mod + c;
		return res % mod;
	}
};


ll modPow(ll n, ll k) {
	// cerr << "n, k: " << n << ' ' << k << endl;
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1) res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

ll modInv(ll x) {
	return modPow(x, mod - 2);
}

int main() {

	// cout << 5 * modInv(2) << endl;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<ll, pair<int, int>>> v;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ll x;
			cin >> x;
			v.push_back({ x, {i, j} });
		}
	}

	Eq eq1, eq2;

	sort(v.rbegin(), v.rend());
	vector<ll> dp(v.size());

	for (int i = dp.size() - 1, j = dp.size() - 1; i >= 0; --i) {
		for (; v[i].first != v[j].first; --j) {
			eq1.add(dp[j], v[j].second.first);
			eq2.add(0, v[j].second.second);
		}
		// cerr << "temp: " << eq1.eval(v[i].second.first) + eq2.eval(v[i].second.second) << endl;
		// cerr << "xxx: " << eq1.eval(v[i].second.first) + eq2.eval(v[i].second.second) * modInv(2) % mod << endl;
		// cerr << "xxx: " << 5 * modInv(2) % mod << endl;
		dp[i] = (eq1.eval(v[i].second.first) + eq2.eval(v[i].second.second)) % mod *modInv(dp.size() - (j + 1));
		dp[i] %= mod;
	}

	int r, c;
	cin >> r >> c;
	--r, --c;
	const int i = find_if(v.begin(), v.end(), [&](const pair<ll, pair<int, int>> &p) {
		return p.second == make_pair(r, c);
	}) - v.begin();

	assert(i != v.size());
	const ll res = (dp[i] % mod + mod) % mod;
	cout << res << '\n';

	return 0;
}