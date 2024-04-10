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

int n;
vector<vector<int>> e;
vector<int> d, sz;
set<pii> er;
vector<pii> v_er, v_in;
bool viv = false;

int lst;
vector<int> lf;

void DFS(int v, int c = 0) {
	d[v] = c;
	for (auto u : e[v])
		if (d[u] == -1)
			DFS(u, c + 1);

	vector<int> bad;
	int p = -1;
	for (auto u : e[v])
		if (d[u] < d[v])
			p = u;
	if (p != -1 && sz[v] - bad.size() > 2)
		bad.push_back(p);
	for (auto u : e[v])
		if (d[u] > d[v] && sz[v] - bad.size() > 2 && er.find({v, u}) == er.end())
			bad.push_back(u);
	for (auto u : bad) {
		v_er.push_back({v, u});
		er.insert({u, v});
		er.insert({v, u});
		sz[v]--;
		sz[u]--;
	}
}

void DFS2(int v, int c = 0) {
	d[v] = c;
	for (auto u : e[v])
		if (er.find({v, u}) == er.end() && d[u] == -1) {
			DFS2(u, c);
		}
	for (int i = 0; i < 2 - sz[v]; i++)
		lf.push_back(v);
}

void solve() {
	cin >> n;
	e.assign(n, {});
	er.clear();
	v_er.clear();
	v_in.clear();
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	d.assign(n, -1);
	sz.clear();
	for (int i = 0; i < n; i++)
		sz.push_back(e[i].size());
	DFS(0);

	d.assign(n, -1);
	lst = -1;
	int num = 0;
	for (int i = 0; i < n; i++)	{
		if (d[i] == -1) {
			lf.clear();
			DFS2(i, num);
			if (lf.size() != 2) {
				cout << "Leaves out" << endl;
				cout << lf.size() << ": ";
				for (auto i : lf)
					cout << i << ' ';
				cout << endl;
				cout << "d = ";
				for (auto i : d)
					cout << i << ' ';
				cout << '\n';
				cout << "sz = ";
				for (auto i : sz)
					cout << i << ' ';
				cout << '\n';
				exit(1);
			}
			if (lst != -1) {
				v_in.push_back({lst, lf[0]});
			}
			lst = lf[1];
			num++;
		}
	}

	if (v_er.size() != v_in.size()) {
		cout << "BAD" << endl;
		exit(0);
	}
	cout << v_er.size() << '\n';
	for (int i = 0; i < v_er.size(); i++) {
		cout << v_er[i].F + 1 << ' ' << v_er[i].S + 1 << ' ';
		cout << v_in[i].F + 1 << ' ' << v_in[i].S + 1 << ' ';
		cout << '\n';
	}
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