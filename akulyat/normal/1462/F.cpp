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

vector<ll> l, r;

void solve() {
	cin >> n;
	v.resize(n);
	l.clear();
	r.clear();
	for (auto &p : v) {
		cin >> p.F >> p.S;
		l.push_back(p.F);
		r.push_back(p.S);
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	ll ans = n;
	for (auto p : v) {
		int br = lower_bound(l.begin(), l.end(), p.S + 1) - l.begin();
		br = n - br;

		int bl = lower_bound(r.begin(), r.end(), p.F) - r.begin();

		ll lans = bl + br;
		ans = min(ans, lans);

		if (viv) {
			cout << "\t" << bl << ' ' << br << endl;
			cout << "\t\t" << lans << '\n';
		}
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