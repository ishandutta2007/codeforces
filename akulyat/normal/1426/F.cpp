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
string s;
bool viv = false;

int _pow(ll v, ll st) {
	if (st < 0)
		return 0;
	if (st == 0)
		return 1;
	ll sq = _pow(v, st / 2);
	ll res = sq * sq;
	res %= mod;
	if (st & 1)
		res *= v;
	res %= mod;
	return res;
}

void solve() {
	cin >> n;
	cin >> s;
	k = 0;
	for (auto i : s)
		k += (i == '?');

	ll q, a, b;
	q = a = b = 0;
	ll aq, qb, ab, qq;
	aq = qb = ab = qq = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll left = k;
		if (s[i] == '?')
			left--;
		if (s[i] == '?' || s[i] == 'c') {
			ans += qq * _pow(3, left - 2);
			ans += aq * _pow(3, left - 1);
			ans += qb * _pow(3, left - 1);
			ans += ab * _pow(3, left);
			ans %= mod;
			// cout << ans << '\n';
		}

		if (s[i] == 'a')
			a += 1;
		if (s[i] == 'b') {
			ab += a;
			qb += q;
			ab %= mod;
			qb %= mod;
			b += 1;
		}
		if (s[i] == '?') {
			aq += a;
			qq += q;
			aq %= mod;
			qq %= mod;
			q += 1;
		}
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