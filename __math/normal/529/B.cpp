#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
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
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> void chmax(T& a, T b) { a = max(a, b); }
template<class T> void chmin(T& a, T b) { a = min(a, b); }

#pragma comment(linker,"/STACK:36777216")


int main() {
	int n; cin >> n;
	vector<Pii> v(n);
	FOR(i, n) cin >> v[i].first >> v[i].second;
	// FOR(i, n) if (v[i].first > v[i].second) swap(v[i].first, v[i].second);
	ll ans = LLONG_MAX;
	for (int h = 1; h <= 1000; h++) {
		int yoko = 0;
		ll wsum = 0;
		vector<int> diffs;
		FOR(i, n){
			int mx = max(v[i].first, v[i].second);
			int mn = min(v[i].first, v[i].second);
			if (h < mn) yoko = 1000000;
			else if (h < mx) {
				if (v[i].first == mx) {
					wsum += v[i].first;
				} else {
					yoko++;
					wsum += v[i].second;
				}
			} else {
				if (v[i].first == mx) {
					wsum += v[i].first;
					diffs.push_back(mn - mx);
				} else {
					wsum += v[i].first;
				}
			}
		}
		if (yoko > n / 2) continue;
		sort(diffs.rbegin(), diffs.rend());
		while (yoko < n / 2 && sz(diffs)) {
			wsum += diffs.back();
			diffs.pop_back();
			yoko++;
		}

		ans = min(ans, h * wsum);
	}
	cout << ans << endl;
}