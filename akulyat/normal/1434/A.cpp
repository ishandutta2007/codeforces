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
vector<ll> v, a;
bool viv = false;


void solve() {
	a.resize(6);
	for (auto &i : a)
		cin >> i;
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	vector<vector<ll>> can(n);
	for (int i = 0; i < n; i++) {
		for (auto s : a) {
			can[i].push_back(v[i] - s);
		}
		can[i].push_back(inf);
		sort(can[i].rbegin(), can[i].rend());
	}
	ll mx = -inf;
	ll ans = inf;
	set<pll> s;
	for (int i = 0; i < n; i++) {
		mx = max(mx, can[i].back());
		s.insert({can[i].back(), i});
	}
	while (true) {
		auto p = *s.begin();
		int pl = p.S;
		ll mn = p.F;
		if (mn == inf) {
			cout << ans << '\n';
			exit(0);
		}
		s.erase({can[pl].back(), pl});
		ans = min(ans, mx - mn);


		can[pl].pop_back();
		s.insert({can[pl].back(), pl});
		mx = max(mx, can[pl].back());
	}
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