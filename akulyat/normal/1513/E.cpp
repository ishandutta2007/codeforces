#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;

ll f(int n) {
	ll res = 1;
	for (int i = 1; i <= n; i++)
		res *= i, res %= mod;
	return res;
}

ll bpow(ll val, ll mod, ll st = -1) {
	if (st == -1)
		st = mod - 2;
	if (st == 0)
		return 1;
	ll res = bpow(val, mod, st >> 1);
	res = res * res, res %= mod;
	if (st & 1)
		res *= val, res %= mod;
	return res;
}

ll C(int n, int k) {
	ll res = 1;
	ll f1 = f(n);
	res *= f1, res %= mod;

	ll f2 = f(k);
	f2 = bpow(f2, mod);
	res *= f2, res %= mod;

	ll f3 = f(n - k);
	f3 = bpow(f3, mod);
	res *= f3, res %= mod;

	return res;
}

void solve() {
	cin >> n;
	v.resize(n);
	ll sum = 0;
	for (auto &i : v)
		cin >> i, sum += i;
	if (sum % n) {
		cout << "0\n";
		return;
	}

	ll mid = sum / n;

	int b = 0, s = 0;
	for (auto i : v)
		b += (i > mid), s += (i < mid);

	if (min(b, s) <= 1) {
		ll ans = f(n);
		map<int, int> mp;
		for (auto i : v)
			mp[i]++;
		for (auto pr : mp) {
			ll cf = pr.S;
			cf = f(cf);
			cf = bpow(cf, mod);
			ans *= cf;
			ans %= mod;
		}
		cout << ans << '\n';
		return;
	}

	ll ans = C(n, b + s);
	ans *= f(b);
	ans %= mod;
	ans *= f(s);
	ans %= mod;
	ans *= f(n - b - s);
	ans %= mod;

	map<int, int> mp;
	for (auto i : v)
		mp[i]++;
	for (auto pr : mp) {
		ll cf = pr.S;
		cf = f(cf);
		cf = bpow(cf, mod);
		ans *= cf;
		ans %= mod;
	}


	ans *= 2;
	ans %= mod;
	cout << ans << '\n';	
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}