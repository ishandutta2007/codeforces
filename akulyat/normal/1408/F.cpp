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

ll n, nxt;
vector<ll> v;
vector<pll> ans;
bool viv = false;

void checker() {
	set<ll> all;
	for (auto i : v)
		all.insert(i);
	assert(all.size() <= 2);
}

void show() {
	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
	}
}

void solver() {
	nxt = n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		v[i] = i;
	for (int sz = 1; sz <= n; sz <<= 1) {
		for (int l = 0; l < n; l += 2 * sz) {
			ll r = l + 2 * sz;
			if (r <= n) {
				nxt++;
				for (int i = l, j = l + sz; j < r; i++, j++) {
					v[i] = nxt;
					v[j] = nxt;
					ans.push_back({i, j});
				}
			}
		}
	}
	map<ll, vector<ll>> all;
	for (int i = 0; i < n; i++)
		all[v[i]].push_back(i);
	ll root = v[0];

	set<pll> sz;
	for (auto p : all) {
		if (p.F != root)
			sz.insert({p.S.size(), p.F});
	}
	vector<ll> newV;
	while (sz.size()) {
		auto mini1 = *sz.begin();
		sz.erase(mini1);
		for (auto i : all[mini1.S])
			newV.push_back(i);
		if (sz.size()) {
			auto mini2 = *sz.begin();
			ll need = mini2.F;
			while (newV.size() < need) {
				newV.push_back(all[root].back());
				all[root].pop_back();
			}
		}
	}
	n = newV.size();
	for (int sz = 1; sz <= n; sz <<= 1) {
		for (int l = 0; l < n; l += 2 * sz) {
			ll r = l + 2 * sz;
			if (r <= n) {
				nxt++;
				for (int i = l, j = l + sz; j < r; i++, j++) {
					ll pli = newV[i];
					ll plj = newV[j];
					v[pli] = nxt;
					v[plj] = nxt;
					ans.push_back({pli, plj});
				}
			}
		}
	}
	checker();
	show();
}

void solve() {
	cin >> n;
	ans.clear();
	v.clear();
	solver();
	return;
	for (int i = 3; i < 100; i++) {
		n = i;
		ans.clear();
		v.clear();
		solver();
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