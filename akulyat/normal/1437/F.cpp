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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
vector<ll> f, of;
bool viv = false;

ll bpow(ll val, ll st = mod - 2) {
	if (st == 0)
		return 1;
	ll res = bpow(val, st >> 1);
	res = res * res, res %= mod;
	if (st & 1)
		res *= val, res %= mod;
	return res;
}

void prepare() {
	f.resize(1, 1);
	for (int i = 1; i <= n; i++)
		f.push_back(f.back() * i), f.back() %= mod;
	for (auto i : f)
		of.push_back(bpow(i));
}

ll C(ll n, ll k) {
	if (k < 0 || k > n)
		return 0;
	return (f[n] * of[n - k]) % mod;
}

void solve() {
	cin >> n;
	prepare();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	vector<vector<ll>> dp, pref;
	dp.resize(n + 1, vector<ll>(n + 1, 0));
	pref.resize(n + 1, vector<ll>(n + 1, 0));
	pref[0][0] = dp[0][0] = 1;
	int cant = 0;
	for (int i = 0; i < n; i++) {
		while (v[cant] * 2 <= v[i])
			cant++;
		ll value = 0;
		for (int will = 0; will <= n; will++) {
			if (cant + 2 - will > 0 || true) {
				value *= (cant + 2 - will);
				// value *= bpow(cant + 2 - will);
				value %= mod;
			} else {
				value *= 0;
			}

			int was = will - 1;
			if (was + 1) {
				value += pref[cant][was] * C(cant - was, will - was - 1);
				value %= mod;
			}
			dp[i + 1][will] = value;

			pref[i + 1][will] = pref[i][will] + dp[i + 1][will];
			pref[i + 1][will] %= mod;
			if (viv)
				cout << i << ' ' << will << ' ' << dp[i + 1][will] << endl;
		}
	}
	cout << dp.back().back() << '\n';
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