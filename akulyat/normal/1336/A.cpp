#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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


ll n, ans, k;
vector<ll> v, d, p, sz, kids;
vector<vector<int>> e;
vector<bool> need;
set<pll> lst;
bool viv = false;

void DFS(ll v, ll c) {
	d[v] = c;
	sz[v] = 1;
	for (auto s : e[v]) {
		if (d[s] == -1) {
			DFS(s, c + 1), p[s] = v;
			sz[v] += sz[s];
			kids[v]++;
		}
	}
}

void DFS2(ll v, ll c) {
	if (viv)
		cout << v << ' ' << c << '\n';
	d[v] = c;
	if (!need[v])
		c++;
	else
		ans += c;
	for (auto s : e[v]) {
		if (d[s] == -1)
			DFS2(s, c);
	}
}

void check(ll v) {
	if (kids[v] == 0)
		lst.insert({-d[v] + sz[v] - 1, v});
}

void solve() {
	cin >> n;
	cin >> k;
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	d.resize(n, -1);
	p.resize(n, 0);
	kids.resize(n, 0);
	sz.resize(n, 0);
	DFS(0, 0);
	if (viv) {
		for (auto i : d)
			cout << i << ' ';
		cout << endl;
		for (auto i : p)
			cout << i << ' ';
		cout << endl;
		for (auto i : sz)
			cout << i << ' ';
		cout << endl;
	}
	need.resize(n, false);
	for (int i = 0; i < n; i++) 
		check(i);

	for (int i = 0; i < k; i++) {
		auto pr = *lst.begin();
		if (viv)
			cout << "Add " << pr.S << " with " << pr.F << '\n';
		lst.erase(lst.begin());
		need[pr.S] = true;
		kids[p[pr.S]]--;
		check(p[pr.S]);
	}


	d.clear();
	d.resize(n, -1);
	DFS2(0, 0);
	cout << ans << '\n';
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