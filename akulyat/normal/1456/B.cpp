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
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	vector<ll> p;
	p.push_back(0);
	for (auto i : v)
		p.push_back(p.back() ^ i);
	int c = 32 * 4;

	ll ans = mod;
	for (int i = 0; i < n - 1; i++) {
		ll v1 = 0;
		vector<pll> lv;
		for (int j = i; j >= max(i - c, 0); j--) {
			v1 ^= v[j];
			lv.push_back({v1, i - j});
		}
		if (viv) {
			for (auto p : lv)
				cout << p.F << ' ' << p.S << "; ";
			cout << '\n';
		}

		lv.push_back({inf, mod});
		sort(lv.begin(), lv.end());
		for (int i = lv.size() - 2; i >= 0; i--)
			lv[i].S = min(lv[i].S, lv[i + 1].S);

		ll v2 = 0;
		for (int j = i + 1; j < min(i + c, (int)n); j++) {
			ll d = j - (i + 1);
			v2 ^= v[j];
			auto z = (*upper_bound(lv.begin(), lv.end(), (pll){v2, mod})).S;
			if (viv)
				cout << '\t' << v2 << ": " << d << ' ' << z << '\n';
			ans = min(ans, d + z);
		}
	}
	if (ans >= mod) 
		ans = -1;
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