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


ll n;
bool viv = false;
vector<ll> q, d;
vector<vector<ll>> e, path, ans;

void DFS(int v, int c) {
	d[v] = c;
	for (auto s : e[v])
		if (d[s] == -1)
			DFS(s, c + 1);
	q.push_back(v);
}

void work(ll v) {
	if (viv)
		cout << "IN " << v << endl;
	int kids = 0;
	path[1][v] = 1;
	for (auto s : e[v])
		if (d[s] > d[v]) {
			kids++;
		}		
	for (auto s : e[v])
		if (d[s] > d[v]) {
			path[1][v] = max(path[1][v], path[0][s] + 1);
		}		
	for (auto s : e[v]) 
		if (d[s] > d[v]) {
			path[0][v] = max(path[0][v], max(path[0][s], path[1][s]) + kids - 1);
		}


	set<pll> se, sf;

	for (auto s : e[v])
		if (d[s] > d[v])
			se.insert({-path[0][s], s});
	for (auto s : e[v])
		if (d[s] > d[v])
			sf.insert({-max(path[1][s], path[0][s]), s});


	se.insert({0, -1});
	se.insert({0, -2});
	sf.insert({0, -1});
	sf.insert({0, -2});

	if (viv) {
		for (auto p : se) {
			cout << p.F << ' ' << p.S << "; ";
		}
		cout << endl;
		for (auto p : sf) {
			cout << p.F << ' ' << p.S << "; ";
		}
		cout << endl;
	}

	ans[0][v] = max(kids - 2, 0);
	ans[0][v] -= (*sf.begin()).F;
	sf.erase(sf.begin());
	ans[0][v] -= (*sf.begin()).F;
	sf.erase(sf.begin());
	ans[0][v] += (v != 0);

	ans[1][v] = 1;
	ans[1][v] -= (*se.begin()).F;
	se.erase(se.begin());
	ans[1][v] -= (*se.begin()).F;
	se.erase(se.begin());

	if (viv) {
		cout << v << ' ' << path[0][v] << ' ' << path[1][v] << '\n';
		cout << v << ' ' << ans[0][v] << ' ' << ans[1][v] << '\n';
		cout << endl;
	}
}

void solve() {
	cin >> n;
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	d.resize(n, -1);
	DFS(0, 0);
	path.resize(2);
	for (auto &l : path)
		l.resize(n);
	ans.resize(2);
	for (auto &l : ans)
		l.resize(n);


	for (auto v : q)
		work(v);

	ll res = 0;
	for (auto l : ans)
		for (auto i : l)
			res = max(res, i);
	for (auto l : path)
		for (auto i : l)
			res = max(res, i);

	cout << res;
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