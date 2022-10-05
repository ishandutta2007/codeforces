// #include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n, m;
vector<vector<int>> e;
vector<int> p, d;
string ans;
unordered_map<ll, int> pl;
vector<pii> ed;

ll get_pair(int u, int v) {
	return (ll)u * ml + v;
}

void DFS(int v, int dp = 0) {
	d[v] = dp;
	for (auto u : e[v]) {
		if (d[u] == -1) {
			ans[pl[get_pair(u, v)]] = '1';
			p[u] = v;
			DFS(u, dp + 1);
		}
	}
}

void change(int u, int v) {
	if (d[u] > d[v])
		swap(u, v);
	int pv = p[v];
	assert(pv != v);	
	assert(pv != u);	

	int num_to_1 = pl[get_pair(u, v)];
	int num_to_0 = pl[get_pair(pv, v)];
	ans[num_to_0] = '0';
	ans[num_to_1] = '1';
}

void solve() {
	cin >> n >> m;
	e.assign(n, {});
	pl.clear();
	ed.clear();
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
		pl[get_pair(a, b)] = i;
		pl[get_pair(b, a)] = i;
		ed.push_back({a, b});
	}
	ans.assign(m, '0');
	d.assign(n, -1);
	p.assign(n, 0);
	DFS(0);

	if (m == n + 2) {
		set<int> rd;
		for (int i = 0; i < ed.size(); i++)
			if (ans[i] == '0') {
				rd.insert(ed[i].F);
				rd.insert(ed[i].S);
			}
		vector<int> vrd;
		for (auto i : rd)
			vrd.push_back(i);
		if (rd.size() == 3) {
			// cout << "NICE " << vrd[0] << ' ' << vrd[1] << ' ' << ans << '\n';
			change(vrd[0], vrd[1]);
		}
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}