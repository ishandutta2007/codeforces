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
int n;
vector<int> v, ans;

void read() {
	cin >> n;
	v.resize(n);	
	for (auto &i : v)
		cin >> i, i--;
	ans.resize(n);	
	for (auto &i : ans)
		cin >> i, i--;
}

vector<int> get_res() {
	map<int, int> cnt;
	vector<vector<pii>> c(n);
	for (int i = 0; i < n; i++) {
		c[cnt[v[i]]].push_back({v[i], i});
		cnt[v[i]]++;
	}	

	vector<int> res(n);
	for (auto c : c) {
		if (c.size()) {
			sort(c.begin(), c.end());
			for (int i = 0; i < c.size(); i++) {
				res[c[i].S] = v[c[(i + 1) % c.size()].S];
			}
		}
	}
	return res;
}

vector<bool> used;
vector<vector<int>> e;
void work(vector<int> &path, int &ans) {
	if (viv) {
		cout << "work: ";
		for (auto i : path)
			cout << i << ' ';
		cout << "| " << ans;
		cout << endl;
	}
	int v = path.back();
	if (used[v]) {
		if (viv)
			cout << "\tDEL" << endl;
		path.pop_back();
		while (path.back() != v) {
			used[path.back()] = false;
			path.pop_back();
		}
		used[path.back()] = false;
		path.pop_back();
		ans--;

		if (path.empty())
			return;
		path.push_back(v);
	}
	used[v] = true;
	assert(e[v].size());
	int u = e[v].back();
	e[v].pop_back();
	path.push_back(u);
	work(path, ans);
}

int get_ans(vector<int> pans) {
	for (int i = 0; i < n; i++) 
		e[i].clear();
	for (int i = 0; i < n; i++) {
		e[v[i]].push_back(pans[i]);
	}

	for (int i = 0; i < n; i++) {
		shuffle(e[i].begin(), e[i].end(), rng);
	}

	if (viv) {
		cout << "edges:\n";
		for (int i = 0; i < n; i++) {
			cout << i << ": ";
			for (auto u : e[i])	
				cout << u << ' ';
			cout << endl;
		}
	}

	used.assign(n, false);
	int res = n;
	for (int i = 0; i < n; i++) {
		while (e[i].size()) {
			vector<int> path = {i};
			int len = 0;
			work(path, res);
		}
	}
	if (viv)
		cout << "DONE " << res << endl;
	return res;
}

void solve() {
	read();

	// n = 100 * kk;
	// v.resize(n);
	// for (int i = 0; i < n; i++)
	// 	v[i] = rnd(n);

	auto res = get_res();
	// ans = res;
	if (viv) {
		cout << "res: ";
		for (auto i : res)
			cout << i << ' ';
		cout << endl;
		cout << "ans: ";
		for (auto i : ans)
			cout << i << ' ';
		cout << endl;
	}

	e.resize(n);
	int best = get_ans(res);
	for (int i = 0; i < 22; i++) {
		int ans_best = get_ans(ans);

		if (ans_best != best) {
			cout << "WA\n";
			return;

		}
	}

	cout << "AC\n";
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