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

int g[5][5];
const int n = 5;

int main() {
	FOR(i, n) FOR(j, n) cin >> g[i][j];
	int a[] = { 0, 1, 2, 3, 4 };
	Pii p[] = { Pii(0, 1), Pii(2, 3), Pii(1, 2), Pii(3, 4), Pii(2, 3), Pii(3, 4) };
	int ans = 0;
	do {
		int cur = 0;
		FOR(i, 6) {
			cur += g[a[p[i].first]][a[p[i].second]] + g[a[p[i].second]][a[p[i].first]];
		}
		ans = max(ans, cur);
	}
	while (next_permutation(a, a + 5));
	cout << ans << endl;
	return 0;
}