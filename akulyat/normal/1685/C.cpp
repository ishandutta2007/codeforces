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
string s, t;
vector<pii> ans;

int val(char c) {
	return (c == '(') - (c == ')');
}

bool nice(string s) {
	int b = 0;
	for (int i = 0; i < s.size(); i++) {
		b += val(s[i]);
		if (b < 0)
			return false;
	}
	return true;
}


int T;

void work(string &s, string &t, int l, int r, int ml, int mr) {
	if (viv) {
		cout << "WORK(" << l << ' ' << r << ' ' << ml << ' ' << mr << ")" << endl;
	}

	if (l >= r)
		return;

	int sl = l;
	int sr = r;

	int bl = ml;
	while (l <= r && bl >= 0) {
		bl += val(s[l]);
		l++;
	}
	l--;
	if (l == r)
		return;

	int br = mr;
	while (br >= 0) {
		br -= val(s[r]);
		r--;
	}
	r++;

	if (viv)
		cout << "\tsee " << l << ' ' << r << endl;

	int l2 = l;
	int bbl = 0;

	int cl2 = l2;
	int cbl = 0;
	
	int r2 = r;
	int bbr = 0;

	int cr2 = r2;
	int cbr = 0;

	while (cl2 != sl) {
		cl2 -= 1;
		cbl -= val(s[cl2]);
		if (cbl > bbl)
			bbl = cbl, l2 = cl2;
	}

	while (cr2 != sr) {
		cr2 += 1;
		cbr += val(s[cr2]);
		if (cbr > bbr)
			bbr = cbr, r2 = cr2;
	}
	if (viv)
		cout << "\t\tSEE " << l << ' ' << r << ' ' << l2 << ' ' << r2 << endl;

	ans.push_back({l2, r2});
	work(t, s, (int)s.size() - 1 - (r - 1), (int)s.size() - 1 - (l + 1), 
		bbr + bbl + 1,
		bbl + bbr + 1
	);
}

void solve(int tc) {
	cin >> n;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	ans.clear();
	work(s, t, 0, s.size() - 1, 0, 0);

	for (int i = 1; i < ans.size(); i++) {
		ans[i].F = (int)s.size() - 1 - ans[i].F;
		ans[i].S = (int)s.size() - 1 - ans[i].S;
		swap(ans[i].F, ans[i].S);
	}


	if (ans.size() > 2) {
		ans.clear();
		vector<int> pr(1, 0);
		for (auto c : s)
			pr.push_back(pr.back() + val(c));
		int b = 0;
		for (int i = 0; i < s.size(); i++)
			if (pr[i + 1] > pr[b + 1])
				b = i;
		ans.push_back({0, b});
		if (b + 1 <= s.size() - 1)
			ans.push_back({b + 1, s.size() - 1});
	}


	cout << ans.size() << '\n';
	reverse(ans.begin(), ans.end());
	for (auto p : ans) {
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	int tc = 0;
	T = t;
	while (t--)
		solve(tc++);

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}