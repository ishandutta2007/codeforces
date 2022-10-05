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
vector<pll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F >> p.S;

	ll s4 = 0;
	ll s24 = 0;
	for (int i = 0; i < n; i++) {
		int tw = 0;
		for (int j = 0; j < n; j++) {
			ll dx = v[j].F - v[i].F;
			ll dy = v[j].S - v[i].S;
			dx = abs(dx);
			dy = abs(dy);
			ll g = __gcd(dx, dy);
			// cout << dx << ' ' << dy << ' ' << g << endl;
			if (g % 4 == 2)
				tw++;
		}
		int fr = n - 1 - tw;

		// cout << "have: " << tw << ' ' << fr << endl;
		s4 += fr * (fr - 1) / 2;
		s24 += tw * fr;
	}	
	s24 /= 2;
	s4 /= 3;
	ll ans = s4 + s24;	
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