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

ll n, m;
vector<ll> v;
vector<vector<int>> e;
bool viv = false;

void bad() {
	cout << -1;
	exit(0);
}

void check(int r) {
	set<ll> hh;
	for (auto s : e[r]) {
		if (v[s] == v[r])
			bad();
		if (v[s] < v[r])
			hh.insert(v[s]);
	}
	if (hh.size() != v[r])
		bad();
}

void solve() {
	cin >> n >> m;
	e.resize(n);
	v.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (auto &i : v)
		cin >> i, i--;

	vector<pll> tos;
	for (int i = 0; i < n; i++)
		tos.push_back({v[i], i});
	sort(tos.begin(), tos.end());
	for (int i = 0; i < n; i++)
		check(i);

	for (auto i : tos)
		cout << i.S + 1 << ' ';

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