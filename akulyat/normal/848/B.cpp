#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
const ll con = 200 * kk;

ll n, w, h;
vector<vector<pair<pll, ll>>> v;
bool viv = false;


void solve() {
	cin >> n >> w >> h;
	v.resize(ml);
	for (int i = 0; i < n; i++) {
		ll lg, lp, lt, lx, ly;
		cin >> lg >> lp >> lt;
		lg--;
		lx = lp;
		ly = -lt;
		if (lg)
			swap(lx, ly);

		v[lx + ly + con].push_back({{lx, ly}, i});
	}

	vector<pll> ans(n, {-1, -1});
	for (auto &vec : v) {
		sort(vec.begin(), vec.end());
		vector<pll> a, b;
		for (auto pp : vec) {
			auto p = pp.F;
			if (p.F <= 0)
				b.push_back({w, p.S});
			else
				a.push_back({p.F, h});
		}
		for (auto i : b)
			a.push_back(i);
		for (int i = 0; i < vec.size(); i++)
			ans[vec[i].S] = a[i];
	}

	for (auto p : ans) {
		cout << p.F << ' ' << p.S << '\n';
	}
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();

	return 0;
}