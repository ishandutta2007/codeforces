#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }

const int C = 19;
ll FR[C];

void init() {
	FR[0] = 1;
	for (int i = 1; i < C; i++) FR[i] = FR[i-1] * i;
}

vector<vector<ll>> f(vector<int> a) {
	vector<Pll> pv, nt;
	pv.push_back(Pll(0,0));
	for (auto x : a) {
		nt = pv;
		for (auto y : pv) {
			if (x < C) {
				if (y.first + FR[x] < ll(ten(8)) * ten(8)) {
					nt.push_back(Pll(y.first + FR[x], y.second + 1));
				}
			}
			nt.push_back(Pll(y.first + x, y.second));
		}
		swap(pv, nt);
	}

	vector<vector<ll>> ret(sz(a) + 1);
	for (auto kv : pv) {
		ret[(int)kv.second].push_back(kv.first);
	}
	FOR(i, sz(a) + 1) {
		sort(ret[i].begin(), ret[i].end());
	}
	return ret;
}

int main() {
	init();
	int n, k; cin >> n >> k;
	ll S; cin >> S;
	vector<int> a(n);
	FOR(i, n) cin >> a[i];

	vector<int> b(a.begin(), a.begin() + n / 2);
	vector<int> c(a.begin() + n / 2, a.end());

	auto l = f(b);
	auto r = f(c);
	
	ll ans = 0;
	FOR(lk, sz(l)) {
		int rk_max = k - lk;
		FOR(rk,rk_max + 1) {
			if (rk >= 0 && rk < sz(r)) {
				for (auto x : l[lk]) {
					auto eqr = equal_range(r[rk].begin(), r[rk].end(), S - x);
					ans += eqr.second - eqr.first;
				}
			}
		}
	}

	cout << ans << endl;

}