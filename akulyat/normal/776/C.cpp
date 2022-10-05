#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

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

ll n, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	set<ll> s;
	if (abs(k) == 1) {
		s.insert(k);
		s.insert(1);
	} else {
		ll val = 1;
		while (abs(val) < inf / 10) {
			s.insert(val);
			val *= k;
		}
	}



	map<ll, ll> have;
	ll now = 0;

	have[now]++;
	ll ans = 0;

	for (auto i : v) {
		now += i;
		have[now]++;
		for (auto i : s) {
			ll need = now - i;
			ans += have[need];
		}
	}

	cout << ans << '\n';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}