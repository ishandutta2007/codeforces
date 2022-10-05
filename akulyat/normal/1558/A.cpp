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

ll a, b;
set<ll> ans;
bool viv = false;

void work(int pa, int pb, int a, int b) {
	if (a > b) {
		work(pb, pa, b, a);
		return;	
	}
	ll res = a + pa;
	ans.insert(res);
	for (int i = 0; i < a; i++) {
		res -= 2;
		ans.insert(res);		
	}
}

void solve() {
	cin >> a >> b;
	int n = a + b;
	int s = n / 2;
	ans.clear();
	work(s, n - s, a, b);
	work(n - s, s, a, b);

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
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