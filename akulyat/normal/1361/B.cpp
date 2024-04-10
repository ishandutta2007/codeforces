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

ll n, p;
vector<ll> v;
bool viv = false;

ll _pow(ll v, ll deg = mod - 2) {
	if (deg == 0)
		return 1;
	ll sq = _pow(v, deg >> 1);
	ll res = sq * sq;
	res %= mod;
	if (deg & 1)
		res *= v, res %= mod;
	return res;
}

void solve() {
	cin >> n >> p;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.rbegin(), v.rend());
	ll ans = 0, cnt = 0;
	bool hope = true;
	for (int i = 0; i < n; i++) {
		ll val = _pow(p, v[i]);
		if (cnt == 0)
			ans += val, cnt = 1;
		else {
			if (!hope)
				ans -= val;
			else {
				ll dif = v[i - 1] - v[i];
				dif = min(dif, 30ll);
				for (int i = 0; i < dif; i++)
					cnt *= p, cnt = min(cnt, n + 20);
				cnt--;
				ans -= val;
				if (cnt >= n + 10)
					hope = false;
			}
		}
	}
	ans %= mod;
	ans += mod;
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