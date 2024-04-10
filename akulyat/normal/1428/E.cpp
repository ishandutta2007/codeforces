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

ll n, k;
vector<ll> v;
bool viv = false;

ll counter(ll val, ll p) {
	p++;
	if (p > val)
		return inf;
	ll mn = val / p;
	ll left = val % p;

	ll res = mn * mn * p;
	res += left * (2 * mn + 1);
	return res;
}


void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	set<pll> can;
	vector<ll> made(n, 0);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll was = counter(v[i], made[i]);
		ll will = counter(v[i], made[i] + 1);
		ans += was;
		can.insert({(will - was), i});		
		if (viv)
			cout << was << ' ' << will << endl;
	}
	k -= n;
	while (k) {
		auto p = *can.begin();
		ll pl = p.S;
		can.erase(p);
		ans -= counter(v[pl], made[pl]);
		made[pl]++;
		ans += counter(v[pl], made[pl]);
		k--;

		ll was = counter(v[pl], made[pl]);
		ll will = counter(v[pl], made[pl] + 1);
		can.insert({(will - was), pl});		
		if (viv)
			cout << '\t' << was << ' ' << will << endl;
	}
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