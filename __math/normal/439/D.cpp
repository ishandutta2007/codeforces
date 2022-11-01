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

ll a_sm[ten(5) + 1], b_sm[ten(5) + 1];

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	FOR(i, n) cin >> a[i];
	FOR(i, m) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	FOR(i, n) a_sm[i + 1] = a_sm[i] + a[i];
	FOR(i, m) b_sm[i + 1] = b_sm[i] + b[i];

	vector<ll> ab;
	FOR(i, n) ab.push_back(a[i]);
	FOR(i, m) ab.push_back(b[i]);
	sort(ab.begin(), ab.end());
	ab.erase(unique(ab.begin(), ab.end()), ab.end());

	int ac = 0, bc = 0;
	ll ans = ll(INF)* ll(INF);
	FOR(i, sz(ab)) {
		ll tmp = 0;
		while (ac < sz(a) && a[ac] < ab[i]) ac++;
		while (bc < sz(b) && b[bc] < ab[i]) bc++;

		ll add1 = ac * ab[i] - a_sm[ac];
		ll add2 = b_sm[m] - b_sm[bc] - (m - bc) * ab[i];
		ans = min(ans, add1 + add2);
	}

	cout << ans << endl;

}