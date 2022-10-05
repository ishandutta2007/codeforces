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

ll n, d, m;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> d >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	vector<ll> bad, good, p;
	for (auto i : v)
		if (i > m)
			bad.push_back(i);
		else
			good.push_back(i);
	sort(bad.rbegin(), bad.rend());
	sort(good.begin(), good.end());

	p.push_back(0);
	for (auto i : good)
		p.push_back(p.back() + i);

	ll sum = 0;
	ll ans = 0;
	for (int use = 0; use <= bad.size(); use++) {
		if (use)
			sum += bad[use - 1];
		ll need = 0;
		need = d * (use - 1);
		need -= ((int)bad.size() - use);
		need = max(need, 0ll);
		if (need <= good.size()) {
			ll lans = sum;
			lans += (p[good.size()] - p[need]);
			ans = max(ans, lans);
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