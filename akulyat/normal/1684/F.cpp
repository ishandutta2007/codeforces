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
vector<int> v;
vector<pii> seg;

void shorter() {
	map<int, int> ch;
	int cnt = 0;
	for (auto &i : v) {
		if (!ch.count(i)) {
			ch[i] = cnt++;
		}
		i = ch[i];
	}
	if (viv) {
		cout << "v = ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
}

int solver1(int L, int R, vector<pii> pr) {
	if (pr.empty())
		return (R - L + 1);
	vector<pii> npr;
	for (auto [l, r] : pr) {
		int g1 = L - l;
		int g2 = r - R;
		g1 = max(g1, 0);
		g2 = max(g2, 0);
		if (g1 >= 0 && g2 >= 0)
			npr.push_back({g1, g2});
	}
	sort(npr.begin(), npr.end());
	if (viv) {
		cout << "npr = \n";
		for (auto p : npr)
			cout << p.F << ' ' << p.S << endl;
		cout << "----\n";
	}
	int ans1 = 0;
	int ans2 = 0;
	for (auto [l, r] : npr) {
		ans1 = max(ans1, l);
		ans2 = max(ans2, r);
	}
	int ans = min(ans1, ans2);
	if (viv) {
		cout << "ans1, ans2 = " << ans1 << ' ' << ans2 << endl;
	}


	multiset<int> lft;
	for (auto p : npr)
		lft.insert(p.S);

	for (auto p : npr) {
		int l = p.F;
		lft.erase(lft.find(p.S));
		if (lft.size()) {
			int r = *lft.rbegin();
			ans = min(ans, l + r);
		}
	}
	return (R - L + 1) + ans;
}

int dif(vector<int> vec) {
	sort(vec.begin(), vec.end());
	return vec.back() - vec[0] + 1;
}

int solver2(vector<pii> pr) {
	if (pr.empty())
		return 0;
	vector<int> l, r;
	for (auto p : pr) {
		l.push_back(p.F);
		r.push_back(p.S);
	}
	int ans1 = dif(l);
	int ans2 = dif(r);
	int ans = min(ans1, ans2);
	sort(pr.begin(), pr.end());
	if (viv) {
		cout << "pr = \n";
		for (auto p : pr)
			cout << p.F << ' ' << p.S << endl;
		cout << "----\n";
		cout << "ans1, ans2 = " << ans1 << ' ' << ans2 << '\n';
	}


	set<int> lft;
	for (auto p : pr)
		lft.insert(p.S);

	int gl_R = pr.back().F;
	while (pr.size()) {
		auto [l, r] = pr.back();
		pr.pop_back();
		lft.erase(lft.find(r));

		if (lft.size()) {
			int r = *lft.rbegin();
			if (viv)	
				cout << "\tsee " << l << ' ' << r << endl;

			int loc_l = min(l, *lft.begin());
			r = max(r, gl_R);
			ans = min(ans, r - loc_l + 1);
		}
	}
	return ans;
}


void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	seg.resize(m);
	for (auto &p : seg) {
		cin >> p.F >> p.S;
		p.F--;
		p.S--;
	}
	shorter();

	vector<vector<int>> pl(n);
	for (int i = 0; i < n; i++) {
		pl[v[i]].push_back(i);
	}

	sort(seg.begin(), seg.end());
	int nseg = 0;


	int r = 0;
	multiset<pii> cur_seg; 
	multiset<int> cur_l; 

	int L = mod;
	int R = -mod;
	vector<pii> pr;
	while (r < n) {
		if (viv) {
			cout << "WORK " << r << endl;
		}
		while (nseg < seg.size() && r >= seg[nseg].F) {
			auto s = seg[nseg];
			cur_seg.insert({s.S, s.F});
			cur_l.insert(s.F);
			nseg++;
		}
		while (cur_seg.size() && (*cur_seg.begin()).F < r) {
			auto s = *cur_seg.begin();
			cur_seg.erase(cur_seg.find(s));
			cur_l.erase(cur_l.find(s.S));
		}

		int val = v[r];
		if (cur_l.size()) {
			int l_start = *cur_l.begin();
			int l = *lower_bound(pl[val].begin(), pl[val].end(), l_start);


			int l_num = lower_bound(pl[val].begin(), pl[val].end(), l) - pl[val].begin();
			int r_num = lower_bound(pl[val].begin(), pl[val].end(), r) - pl[val].begin();

			if (l_num + 1 < r_num) {
				int l2 = pl[val][l_num + 1];
				int r2 = pl[val][r_num - 1];
				L = min(L, l2);
				R = max(R, r2);
			}
			if (l_num != r_num) {
				pr.push_back({l, r});
			}
		}

		r++;
	}
	if (L != mod) {
		for (auto [l, r] : pr) {
			L = min(L, r);
			R = max(R, l);
		}
	}

	if (viv)
		cout << "\t\t LR = " << L << ' ' << R << endl;

	int ans = 0;
	if (L != mod) {
		ans = solver1(L, R, pr);
	} else {
		ans = solver2(pr);
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