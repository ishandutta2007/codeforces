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

typedef unsigned long long ull;

int n;
int a[ten(5)];
int sm[ten(5) + 1];

int main() {

	scanf("%d", &n);
	{int tmp; scanf("%d", &tmp); }
	n--;

	FOR(i, n) scanf("%d", a + i);
	FOR(i, n) sm[i + 1] = sm[i] + a[i];

	int mn = 10000 * 10000 + 1;
	const int diff_max = min(2000, n);
	for (int diff = 1; diff <= diff_max; diff++) {
		if (mn <= diff * diff) break;
		int t = fastAbs(sm[diff]);
		const int i_max = n - diff;
		for (int i = 1; i <= i_max; i++) {
			int val = sm[i + diff] - sm[i];
			val = fastAbs(val);
			t = min(t, val);
		}
		if (t > 10000) continue;
		mn = min(mn, diff * diff + t * t);
	}

	cout << mn << endl;

	return 0;
}