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
vector<int> v;

vector<int> sg(ml, 0);
void prepare() {
	sg[2] = 1;
	// sg[3] = 1;
	// sg[4] = 1;

	for (int i = 3; i < 100; i++) {
		set<int> vals;
		for (int p = 0; p <= i - 2; p++) {
			vals.insert(sg[p] ^ sg[i - p - 2]);
		}
		while (vals.count(sg[i]))
			sg[i]++;
	}
	for (int i = 100; i < sg.size(); i++)
		sg[i] = sg[i - 34];

	// for (int i = 0; i < 10; i++) {
	// 	cout << "sg[" << i << "] = " << sg[i] << endl;
	// }
}


void solve() {
	cin >> n;
	string s;
	cin >> s;

	int com = 0;
	vector<string> sub;
	string str = s.substr(0, 1);
	for (int i = 1; i < n; i++) {
		if (s[i] == str.back()) {
			sub.push_back(str);
			str = s.substr(i, 1);
		} else {
			str += s[i];
		}
	}
	sub.push_back(str);

	int a = 0, b = 0;
	vector<int> vec;
	for (auto ss : sub) {
		if (ss.size() & 1) {
			if (ss[0] == 'R')
				a++;
			else
				b++;
		}
		vec.push_back(ss.size());
	}

	if (a != b) {
		cout << (a > b ? "Alice" : "Bob") << '\n';
		return;
	}

	int res = 0;
	for (auto i : vec)
		res ^= sg[i];
	cout << (res != 0 ? "Alice" : "Bob") << '\n';

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	prepare();
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}