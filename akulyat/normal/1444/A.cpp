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


void solve() {
	ll a, b;
	cin >> a >> b;
	if (a % b) {
		cout << a << '\n';
		return;
	}
	vector<pll> div;
	for (int i = 2; i < sqrt(b) + 3; i++) {
		if (!(b % i)) {
			div.push_back({i, 0});
			while (!(b % i))
				div.back().S++, b /= i;
		}
	}
	if (b > 1)
		div.push_back({b, 1});

	ll ans = a;
	for (auto &p : div) {
		while (!(a % p.F))
			p.S--, a /= p.F;
	}
	ll mn = inf;
	for (auto p : div) {
		ll lans = 1;
		for (int i = 0; i < -p.S + 1; i++)
			lans *= p.F;
		mn = min(mn, lans);
	}
	ans /= mn;

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