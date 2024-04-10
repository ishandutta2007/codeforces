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
vector<int> ans;
bool viv = false;

void work(int b) {
	vector<pair<pll, ll>> fv;
	for (int i = 0; i < n; i++) {
		fv.push_back({v[i], i});
		if ((i >> b) & 1)
			swap(fv[i].F.F, fv[i].F.S);
	}
	sort(fv.begin(), fv.end());
	set<pll> s;
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = l + 1;
		while (r != n && fv[r].F.F == fv[l].F.F)
			r++;
		for (int j = l; j < r; j++) {
			auto z = s.lower_bound({fv[j].F.S, -1});
			if (z != s.begin()) {
				z--;
				ans[fv[j].S] = (*z).S;
			}
		}
		for (int j = l; j < r; j++) {
			s.insert({fv[j].F.S, fv[j].S});
		}
		i = r - 1;
	}
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F >> p.S;
	ans.assign(n, -2);
	for (int i = 0; i < 20; i++)
		work(i);
	for (auto &i : ans)
		i++;
	for (auto &i : ans)
		cout << i << ' ';
	cout << '\n';
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