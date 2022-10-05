#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n, m, sz;
bool viv = false;
bool need = true;
vector<vector<int>> w, c, e, re;
vector<vector<bool>> black;
vector<pii> d;
map<char, int> ww; 

void DFS2(int v, int c1, int c2) {
	if (viv)
		cout << "2 " << v << endl;
	d[v] = {c1, c2};
	for (auto s : re[v])
		if (d[s].S == -1)
			DFS2(s, c1, c2 + 1);
}

void DFS1(int v, int c) {
	if (viv)
		cout << "1 " << v << endl;
	d[v] = {c, -1};
	for (auto s : e[v]) {
		if (d[s].F == -1)
			DFS1(s, c);		
		else {
			if (need)
				need = false, DFS2(s, c, 0);
		}
	}
}

void solve() {
	ww['U'] = 0;
	ww['R'] = 1;
	ww['D'] = 2;
	ww['L'] = 3;
	cin >> n >> m;
	w.clear();
	c.clear();

	c.resize(n);
	for (auto &l: c) {
		string s;
		cin >> s;
		for (auto i : s)
			l.push_back(i - '0');
	}
	w.resize(n);
	for (auto &l: w) {
		string s;
		cin >> s;
		for (auto i : s)
			l.push_back(ww[i]);
	}
	if (viv)
		cout << "OK" << endl;

	sz = n * m;
	e.clear();
	e.resize(sz);
	re.clear();
	re.resize(sz);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = i * m + j;
			int u = i * m + j;
			if (w[i][j] == 0)
				u -= m;
			if (w[i][j] == 2)
				u += m;
			if (w[i][j] == 3)
				u -= 1;
			if (w[i][j] == 1)
				u += 1;
			if (viv)	 {
				cout << "Edge " << v << ' ' << u << endl;
			}

			e[v].push_back(u);
			re[u].push_back(v);
		}
	}
	if (viv)
		cout << "OK" << endl;
	d.clear();
	d.resize(sz, {-1, -1});
	int col = 0;
	for (int i = 0; i < sz; i++)
		if (d[i].F == -1) {
			need = true;
			DFS1(i, col);
			col++;
		}
	if (viv) {
		for (auto p : d)
			cout << p.F << ' ' << p.S << "; ";
		cout << endl;
	}
	vector<int> mx;
	mx.resize(col);
	for (int i = 0; i < sz; i++) {
		if (d[i].S == 0)
			mx[d[i].F] = max(mx[d[i].F], d[e[i][0]].S + 1);
	}
	black.clear();
	black.resize(col);
	for (int i = 0; i < col; i++)
		black[i].resize(mx[i], false);
	if (viv) {
		cout << "fat" << endl;
		for (auto i : mx)
			cout << i << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = i * m + j;
			if (c[i][j] == 0)
				black[d[v].F][d[v].S % mx[d[v].F]] = true; 
		}
	}
	if (viv)
		cout << "fat" << endl;
	int ans1 = 0, ans2 = 0;
	for (auto l : black) {
		for (auto i : l)  {
			ans1++;
			ans2 += (i == true);
		}
	}
	cout << ans1 << ' ' << ans2 << '\n';	
	if (viv)
		cout << endl;
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}