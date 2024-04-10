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

char out[2200][1050];

int main() {
	int n; cin >> n;
	vector<int> a(n);
	FOR(i, n) cin >> a[i];
	memset(out, ' ', sizeof(out));

	int y = 1100,x = 0;
	FOR(i, n) {
		int p = (i % 2 == 0) ? -1 : 1;
		char c = (i % 2 == 0) ? '/' : '\\';
		FOR(j, a[i]) {
			out[y][x] = c;
			y += p;
			x++;
		}
		y -= p;
	}

	x = -1;
	FOR(i, 2200) {
		FOR(j, 1050) if (out[i][j] != ' ') x = max(x,j);
	}

	FOR(i, 2200) {
		int last = -1;
		FOR(j, 1050) if (out[i][j] != ' ') last = j;
		if (last != -1) {
			out[i][x + 1] = '\0';
			puts(out[i]);
		}
	}

}