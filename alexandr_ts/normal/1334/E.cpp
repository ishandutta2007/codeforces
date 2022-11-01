#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>
#include <unordered_map>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;


const ll MOD = 998244353;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

unordered_map<ll, ll> min_prime, cnt_divs;

void add(ll x) {
	if (x == 1) {
		min_prime[x] = 2;
		cnt_divs[x] = 1;	
		return;
	}
	ll minp = x;
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			minp = i;
			break;	
		}	
	}
	min_prime[x] = minp;
	int cnt = 0;
	ll cur = x;
	while (cur % minp == 0) {
		cnt++;	
		cur /= minp;
	}
	cnt_divs[x] = cnt_divs[cur] * (cnt + 1);
}

void prec(ll d) {
	set<ll> divs;
	for (ll i = 1; i * i <= d; ++i) {
		if (d % i) continue;
		divs.insert(i);
		divs.insert(d / i);
	}	
	for (auto x: divs) {
		add(x);	
	}
}

ll pw(ll x, ll t) {
	if (t == 0) return 1;
	if (t % 2) return pw(x, t - 1) * x % MOD;
	ll tmp = pw(x, t / 2);
	return tmp * tmp % MOD;
}

ll bfac(ll x) {
	ll fac = 1;
	for (ll i = 1; i <= x; ++i) {
		fac = fac * i % MOD;	
	}
	return pw(fac, MOD - 2);
}


ll bfacs[N];
ll facs[N];
ll prec0() {
	facs[0] = 1;
	for (ll i = 0; i < 60; ++i) {
		bfacs[i] = bfac(i);		
		if (i) facs[i] = facs[i - 1] * i % MOD;
	}
}

ll ans(ll v, ll u) {
	if (v == u) return 1;	
	vector<int> alphas;
	ll k = u / v;
	while (k != 1) {
		ll p = min_prime[k];	
		ll alpha = 0;
		while (k % p == 0) {
			k /= p;
			alpha++;	
		}
		alphas.push_back(alpha);
	}
	ll sum = accumulate(alphas.begin(), alphas.end(), 0);
	ll fac = facs[sum];
	for (auto a: alphas) {
		fac = fac * bfacs[a] % MOD;	
	}
	return fac;
}

void solve() {
	prec0();
	ll d;
	cin >> d;
	prec(d);
	int q;
	cin >> q;
	while (q--) {
		ll v, u;
		cin >> v >> u;	
		ll g = __gcd(v, u);
		cout << ans(g, v) * ans(g, u) % MOD << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}