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
vector<int> v;
bool viv = false;

vector<int> f(vector<int> a, int val) {
	vector<int> res;
	for (int i = 0; i < a.size(); i++)
		if (a[i] == val)
			res.push_back(i);
	return res;
}

ll count(vector<int> a, vector<int> b) {
	if (a.size() != b.size())
		return inf;
	ll res = 0;
	for (int i = 0; i < a.size(); i++)
		res += abs(a[i] - b[i]);
	return res;
}

ll solver(int val) {
	vector<int> a;
	for (int i = 0; i < n; i++) {
		a.push_back(val);
		val ^= 1;
	}
	ll res = 0;
	res += count(f(a, 0), f(v, 0));
	res += count(f(a, 1), f(v, 1));
	return res / 2;
}

void solve() {
	cin >> n;
	v.resize(n);
	vector<int> cnt(2, 0);
	for (auto &i : v)
		cin >> i, i = i & 1, cnt[i]++;
	if (abs(cnt[0] - cnt[1]) > 1) {
		cout << "-1\n";
		return;
	}
	ll ans1 = solver(0);
	ll ans2 = solver(1);
	ll ans = min(ans1, ans2);
	if (ans >= inf)
		ans = -1;
	cout << ans << '\n';
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