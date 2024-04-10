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

ll n, ans;
vector<ll> v;
vector<int> cnt;
bool viv = false;

void work(ll val) {
	for (int i = 0; i < 60; i++) {
		cnt[i] += (val & 1);
		val >>= 1;
	}
}

void work2(ll val) {
	ll fval = val;
	ll cf = 0;
	for (int i = 0; i < 60; i++) { 
		ll add = (1ll << i);
		add %= mod;
		if (val & 1) 
			add *= n;
		else
			add *= cnt[i];
		add %= mod;
		cf += add;
		val >>= 1;
	}
	cf %= mod;

	ll res = 0;
	val = fval;
	for (int i = 0; i < 60; i++) {
		ll add = 1;
		add *= (1ll << i);
		add %= mod;
		add *= cnt[i];
		add %= mod;
		add *= cf;
		add %= mod;
		if (val & 1)
			res += add;
		val >>= 1;
	}
	res %= mod;
	ans += res;
}

void solve() {
	cin >> n;
	ans = 0;
	v.resize(n);
	cnt.assign(60, 0);
	for (auto &i : v)
		cin >> i;
	for (auto i : v)
		work(i);
	for (auto i : v)
		work2(i);
	ans %= mod;
	cout << ans << '\n';	
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}