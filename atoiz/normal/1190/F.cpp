/*input
88076 150094635296999121 9448115283898894


*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 500001;
const int CUT_OFF = 30 * 1000 * 1000;
bitset<CUT_OFF> flag;

mt19937_64 rng(chrono::system_clock().now().time_since_epoch().count());

ll bmul(ll a, ll b, ll mod)
{
    ll ans = a * b - (ll)((long double) a * b / mod + 0.5) * mod;
	return (ans < 0 ? ans + mod : ans);
}

ll bpow(ll a, ll b, ll mod)
{
	ll ans = 1;
	for (; b; a = bmul(a, a, mod), b >>= 1) {
		if (b & 1) {
			ans = bmul(ans, a, mod);
		}
	}
	return ans;	
}

bool is_prime(ll p)
{
	if (p == 1) return 0;
	if (p == 2) return 1;
	if (!(p & 1)) return 0;
	int e = __builtin_ctz(p - 1);
	ll q = (p - 1) >> e;
	for (int trial = 0; trial < 50; ++trial) {
		ll x = bpow(rng() % (p - 1) + 1, q, p);
		for (int i = 0; i < e; ++i) {
			ll y = bmul(x, x, p);
			if (y == 1 && (x != 1 && x != p - 1)) return 0;
			x = y;
		}
		if (x != 1) return 0;
	}
	return 1;
}

ll find_factor(ll n)
{
	static auto f = [&](ll x) { return (x = bmul(x, x, n) + n - 1) >= n ? x - n : x; };
	ll x = rng() % n, y = f(x);
	while (__gcd(abs(x - y), n) == 1) {
		x = f(x);
		y = f(f(y));
	}
	return __gcd(abs(x - y), n);
}

vector<ll> all_find_pfactors(ll n)
{
	vector<ll> factors;
	static int MAX_CBRT = 1000007;
	for (ll x = 2; x < MAX_CBRT; ++x) {
		if (n % x == 0) {
			factors.push_back(x);
			while (n % x == 0) n /= x;
		}
	}
	if (n == 1);
	else if (is_prime(n)) {
		factors.push_back(n);
	} else {
		ll x; 
		do { x = find_factor(n); } while (x == n);
		if (x > n / x) x = n / x;
		factors.push_back(x);
		factors.push_back(n / x);
	}
	return factors;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, e = 0;
	ll m, p, q;

	cin >> n >> m >> p;

	// p = q^e
	for (q = 2; q * q * q <= m; ++q) if (m % q == 0) {
		for (ll x = m; x > 1; x /= q, ++e);
		break;
	}
	if (!e) { // => e <= 2
		q = sqrt(m);
		if (q * q == m) {
			e = 2;
		} else {
			q = m, e = 1;
		}
	}

	ll phi_m = m - m / q;

	if (p % q == 0) { // => any x > 1 coprime with m would work
		if (phi_m - 1 < n) return cout << -1 << endl, 0;
		int cnt = 0;
		for (ll x = 2; cnt < n; ++x) {
			if (x % q) {
				cout << x << ' ';
				++cnt;
			}
		}
		assert(cnt == n);
		return 0;
	}

	if (m < CUT_OFF) { // brute force
		for (ll x = 1; !flag[x]; flag[x] = 1, x = x * p % m);
		for (ll x = 0; x < m; x += q) flag[x] = 1;
		if (m - (int) flag.count() < n) return cout << -1 << endl, 0;
		int cnt = 0;
		for (ll x = 2; cnt < n; ++x) {
			if (!flag[x]) {
				cout << x << ' ';
				++cnt;
			}
		}
		assert(cnt == n);
		return 0;
	}

	if (q == 2) { 
		// only if m = 2^e with e > 2 then m has no primitive roots => special case
		// m > n * 8 >= 8 => m has no primitive roots => at least m / 2 plausible values
		for (ll x = 1; !flag[x]; flag[x] = 1, x = x * p % 8);
		int cnt = 0;
		for (ll x = 3; cnt < n; x += 2) {
			if (!flag[x & 7]) {
				cout << x << ' ';
				++cnt;
			}
		}
		assert(cnt == n);

		return 0;
	}

	/* now, m has phi(phi(m)) primitive_roots
	since m >= CUT_OFF, chances are that there are >= n primitive roots
	so if p is not a primitive root, any primitive root would work
	=> iterate to find n primitive roots:
	find first primitive root a, then a^b is another primitive root with (b, phi(m)) = 1
	*/
	vector<ll> pfactors = all_find_pfactors(phi_m);
	function<bool(ll)> is_primitive_root = [&](ll x) {
		for (ll pr : pfactors) {
			if (bpow(x, phi_m / pr, m) == 1) return 0;
		}
		return 1;
	};

	if (is_primitive_root(p)) return cout << -1 << endl, 0;

	ll a = 2;
	while (!is_primitive_root(a)) ++a;

	int cnt = 0;
	for (ll b = 1, x = a; cnt < n; ++b, x = bmul(x, a, m)) {
		if (__gcd(b, phi_m) == 1) {
			cout << x << ' ';
			++cnt;
		}
	}
	assert(cnt == n);

	return 0;
}