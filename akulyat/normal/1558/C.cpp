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

ll n;
vector<ll> v;
vector<ll> ans;
bool viv = false;

void dd_pl(int pl) {
	if (!(pl & 1)) {
		cout << pl << " is even " << endl;
		exit(1);
	}
	ans.push_back(pl);
	reverse(v.begin(), v.begin() + pl);
}

void print();

void dd_val(int val) {
	int pl = 0;
	while (v[pl] != val && pl < n)
		pl++;
	if (pl == n) {
		print();
		cout << "BAD " << val << endl;
		exit(1);
	}
	dd_pl(pl + 1);
}

void print() {
	for (auto i : v)
		cout << i << ' ';
	cout << endl;	
}

void get(int val) {
	int pl = 0;
	while (v[pl] != val && pl < n)
		pl++;
	if (pl == n) {
		print();
		cout << "BAD2 " << val << endl;
		exit(1);
	}

	dd_pl(pl);
	dd_pl(pl + 2);
	dd_pl(3);
}

void pans() {
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
}

void solve() {
	ans.clear();
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	for (int i = 0; i < n; i++)
		if (abs(v[i] - i) & 1) {
			cout << "-1\n";
			return;
		}


	dd_val(0);
	dd_pl(n);

	for (int i = 0; i < n / 2; i++) {
		int val = 0;
	}
	for (int i = n - 2; i >= 3; i -= 2) {
		ll val = v[i];
		val++;
		dd_val(val);
		dd_pl(i);
	}
	dd_pl(n);

	// print();


	for (int i = n - 2; i >= 1; i -= 2) {
		get(i);
	}

	// print();

	pans();
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}