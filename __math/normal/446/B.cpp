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

int a[1000][1000];

vector<ll> f(priority_queue<ll> pq,int k,int p) {
	vector<ll> v;
	v.push_back(0);
	FOR(i, k) {
		ll val = pq.top();
		pq.pop();
		v.push_back(v.back() + val);
		pq.push(val - p);
	}
	return v;
}

int main() {
	int n, m, k, p; scanf("%d%d%d%d", &n, &m, &k, &p);
	FOR(i, n) FOR(j, m) scanf("%d", a[i] + j);

	priority_queue<ll> row, col;
	ll row_m = 0, col_m = 0;

	FOR(i, n) {
		ll sm = 0;
		FOR(j, m) sm += a[i][j];
		row.push(sm);
	}

	FOR(j, m) {
		ll sm = 0;
		FOR(i, n) sm += a[i][j];
		col.push(sm);
	}

	vector<ll> r, l;
	r = f(row, k, p*m);
	l = f(col, k, p*n);

	ll ans = LLONG_MIN;
	FOR(i, k + 1) {
		int j = k - i;
		ll x = ll(i) * j;
		x *= p;
		ll tmp = r[i] + l[j] - x;
		ans = max(ans, tmp);
	}

	cout << ans << endl;
}