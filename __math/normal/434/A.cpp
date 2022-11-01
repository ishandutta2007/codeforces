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

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

inline int fastMin(int x, int y) { return x > y ? y : x; }
inline int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
inline int fastAbs(int x) { return ((x >> (32 - 1))&(x ^ (-x))) ^ x; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n, m;
int a[ten(5)];
vector<int> v[ten(5) + 1];

int main() {
	cin >> n >> m;
	FOR(i, m) cin >> a[i];
	ll base = 0;
	FOR(i, m - 1) base += abs(a[i + 1] - a[i]);
	FOR(i, m - 1) {
		if (a[i] == a[i + 1]) continue;
		v[a[i]].push_back(a[i + 1]);
		v[a[i + 1]].push_back(a[i]);
	}
	ll max_diff = 0;
	for (int i = 1; i <= n; i++) {
		if (sz(v[i]) == 0) continue;
		sort(v[i].begin(), v[i].end());
		int val = v[i][sz(v[i]) / 2];
		int j = 0;
		ll diff = 0;
		for (int j = 0; j < sz(v[i]); j++) {
			int nw_d = abs(v[i][j] - val);
			int pre_d = abs(v[i][j] - i);
			diff += pre_d - nw_d;
		}
		max_diff = max(max_diff, diff);
	}

	cout << base - max_diff << endl;
}