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

const int MX = 110;
ll sm[MX][MX][MX];

int main() {
	int n, k, d; cin >> n >> k >> d;
	sm[0][0][0] = 1;
	ll ans = 0;
	FOR(a, MX - 1) {
		FOR(b, MX) {
			for (int c = 0; c <= k; c++) {
				if (!sm[a][b][c]) continue;
				for(int x = 1; x <= k; x++){
					if (b + x > n) break;
					int nx_max = max(x, c);
					(sm[a + 1][b + x][nx_max] += sm[a][b][c]) %= MOD;
				}
			}
		}
	}

	FOR(i, MX){
		for (int x = d; x <= k; x++) {
			ans += sm[i][n][x];
		}
	}
	cout << ans % MOD << endl;

	return 0;
}