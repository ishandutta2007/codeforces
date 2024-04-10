#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, m, a, b;
bool viv = false;
string s;


void solve() {
	set<pair<pll, pll>> was; 
	map<char, pll> add;
	add['N'] = {1, 0};
	add['S'] = {-1, 0};
	add['W'] = {0, 1};
	add['E'] = {0, -1};
	pll now = {0, 0};
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < s.size(); i++) {
		pll will = now;
		will.F += add[s[i]].F;
		will.S += add[s[i]].S;
		if (was.count({now, will}))
			ans++;
		else
			ans += 5;
		was.insert({now, will});
		was.insert({will, now});
		now = will;
	}
	cout << ans << '\n';
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}