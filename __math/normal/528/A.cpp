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

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

void query(map<int, ll>& m, int* P, int idx, int& mx) {
	auto it = m.upper_bound(idx);
	--it;
	auto vl = *it;
	int first_len = idx - vl.first;
	m[vl.first] = first_len;
	m[idx] = vl.second - first_len;

	P[vl.second]--;
	P[first_len]++;
	P[vl.second - first_len]++;

	while (P[mx] == 0) mx--;
}

int main() {
	int w, h, n; scanf("%d%d%d", &w, &h, &n);
	map<int, ll> mw, mh;
	static int W[ten(5) * 2 + 10], H[ten(5) * 2 + 10];
	mw[0] = w; mh[0] = h;
	W[w]++; H[h]++;

	int wmax = w, hmax = h;
	FOR(i, n) {
		char c[2]; int x; scanf("%s%d", c, &x);
		if (c[0] == 'H') {
			query(mh, H, x, hmax);
		} else {
			query(mw, W, x, wmax);
		}

		ll ans = ll(wmax) * hmax;
		printf("%I64d\n", ans);
	}
}