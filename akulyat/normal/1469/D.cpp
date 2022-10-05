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
vector<pll> ans;
bool viv = false;

int val(pii x, pii y, bool add = false) {
	int res = (abs(x.F) + abs(y.F) - 1) / abs(y.F);
	if (add)
		ans.push_back({x.S, y.S});
	return res;
}

void solve() {
	cin >> n;
	set<pii> s;
	ans.clear();
	for (int i = 2; i <= n; i++)
		s.insert({-i, i});
	while (s.size() >= 2) {
		auto z = s.begin();
		auto y = z;
		y++;
		if (val((*z), (*y)) >= -(*y).F) {
			ll will = -val((*z), (*y), 1);
			auto p = *z;
			s.erase(p);
			p.F = will;
			s.insert(p);			
		} else {
			ll will = -val((*y), (*z), 1);
			s.erase(y);
		}
	}
	cout << ans.size() << endl;
	for (auto p : ans)
		cout << p.F << ' ' << p.S << endl;
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