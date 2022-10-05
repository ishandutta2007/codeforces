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
vector<vector<ll>> e;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	set<pll> s;
	map<pll, ll> mp;
	for (int i = 0; i < n; i++)
		s.insert({v[i], i});
	int cnt = 0;
	for (auto i : s)
		mp[i] = cnt, cnt++;
	for (int i = 0; i < n; i++)
		v[i] = mp[{v[i], i}];

	vector<ll> pl(n, -1);
	for (int i = 0; i < n; i++)
		pl[v[i]] = i;

	vector<pll> ans;
	for (int i = 0; i < n; i++) {
		while (v[i] != i) {
			ll j = pl[v[i] - 1];
			ans.push_back({i, j});
			swap(v[i], v[j]);
			pl[v[i]] = i;
			pl[v[j]] = j;
		}
	}
	cout << ans.size() << '\n';
	for (auto p : ans)
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
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