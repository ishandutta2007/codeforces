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

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
vector<int> a, o, v;
bool viv = false;


int do_a(int a, int b) {
	a %= n;
	b %= n;
	a++, b++;
	cout << "and " << a << ' ' << b << endl;
	int res;
	cin >> res;
	return res;
}

int do_o(int a, int b) {
	a %= n;
	b %= n;
	a++, b++;
	cout << "or " << a << ' ' << b << endl;
	int res;
	cin >> res;
	return res;
}

map<vector<int>, vector<int>> mp;
void start() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int u = 0; u < 2; u++) {
				vector<int> vec;
				vec.push_back(i & j);
				vec.push_back(j & u);
				vec.push_back(u & i);
				vec.push_back(i | j);
				vec.push_back(j | u);
				vec.push_back(u | i);

				vector<int> res = {i, j, u};
				mp[vec] = res;
				if (viv) {
					cout << "they ";
					for (auto i : res)
						cout << i << ' ';
					cout << "give ";
					for (auto i : vec)
						cout << i << ' ';
					cout << endl;
				}
			}

}

vector<int> get_6() {
	vector<int> s;
	for (auto &i : a)
		s.push_back(i & 1), i >>= 1;
	for (auto &i : o)
		s.push_back(i & 1), i >>= 1;
	return s;
}

void getter() {
	start();
	v.resize(3);
	for (int i = 0; i < 30; i++) {
		auto b = get_6();
		if (viv) {
			cout << "b = ";
			for (auto i : b)
				cout << i << ' ';
			cout << endl;
		}
		assert(mp.find(b) != mp.end());		
		auto vals = mp[b];		
		for (int j = 0; j < 3; j++)
			v[j] |= (vals[j] << i);
	}
}

int get(int a, int o) {
	int val = v[0];
	int res = 0;
	for (int i = 0; i < 30; i++) {
		int v1 = val & 1;

		int lres = 0;
		if (a & 1 || (v1 == 0 && (o & 1)))
			lres = 1;
		a >>= 1;
		o >>= 1;
		val >>= 1;

		res |= lres << i;
	}
	return res;
}

void solve() {
	cin >> n >> k;
	k--;

	a.push_back(do_a(0, 1));
	a.push_back(do_a(1, 2));
	a.push_back(do_a(2, 0));
	o.push_back(do_o(0, 1));
	o.push_back(do_o(1, 2));
	o.push_back(do_o(2, 0));
	getter();
	for (int i = 3; i < n; i++) {
		v.push_back(get(do_a(0, i), do_o(0, i)));
	}

	sort(v.begin(), v.end());
	cout << "finish " << v[k] << endl;

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

    // #ifdef DEBUG
        // cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    // #endif
}