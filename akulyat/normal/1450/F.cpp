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
	ll l = 0;
	vector<pll> seg;
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i - 1]) {
			seg.push_back({l, i - 1});
			l = i;
		}
	}
	seg.push_back({l, n - 1});
	if (viv) {
		cout << "SEG\n";
		for (auto p : seg)
			cout << "\t" << p.F << ' ' << p.S << '\n';
		cout << endl;
	}
	map<ll, ll> mp;
	for (auto p : seg) {
		mp[v[p.F]]++;
		mp[v[p.S]]++;
	}
	ll mx = 0;
	for (auto pr : mp)
		mx = max(mx, pr.S);
	ll who = 0;
	for (auto pr : mp)
		if (pr.S == mx)
			who = pr.F;
	if (viv)
		cout << " who " << who << ' ' << mx << endl;
	ll need = mx - (2 * seg.size() - mx) - 2;
	ll ans = seg.size() - 1;
	for (auto p : seg) {
		for (int i = p.F + 1; i <= p.S; i++) {
			if (v[i] != who && v[i - 1] != who && need > 0) {
				need -= 2;
				ans++;
			}
		}
	}
	if (need > 0)
		cout << "-1\n";
	else
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