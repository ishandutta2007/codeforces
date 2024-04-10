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
ll a, b, c, d;
ll k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> a >> b >> c >> d;

	int kl = 0;
	int kr = c + 2;
	while (kl + 1 < kr) {
		ll km = kl + kr >> 1;
		if ((km - 1) * d <= c)
			kl = km;
		else
			kr = km;
	}
	k = kl;
	ll infty = -a + (k) * d * b - (((k) * d) - c) * b;
	if (viv) {
		// cout << "last is " << k << " with " << infty << endl;
		// cout << -a << endl;
		// cout << k << ' ' << d << ' ' << b << endl;
		// cout << k * d - c << endl;
	}

	if (infty < 0) {
		cout << -1 << '\n';
		return;
	}

	ll l = 0;
	ll r = k;
	while (r - l >= 3) {
		ll fl = (2 * l + r) / 3;
		ll fr = (l + 2 * r) / 3;
		ll vl = -fl * a + (fl * (fl - 1) / 2) * d * b;
		ll vr = -fr * a + (fr * (fr - 1) / 2) * d * b;

		if (viv)
			cout << "\t" << fl << ' ' << vl << " : " << vr << ' ' << fr << endl;

		if (vl < vr)
			 r = fr;
		else
			 l = fl;
	}

	l = max(0ll, l - 2);
	r = min(k, r + 2);
	ll ans = 0;
	for (ll k = l; k <= r; k++) {
		ll val = -k * a + (k * (k - 1) / 2) * d * b;
		val *= -1;
		ans = max(val, ans);
	}
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