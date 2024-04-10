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

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ll lt[25],eq[25];
int n;

void mergecount(vector<int> &a,int depth) {
	ll count = 0;
	ll c2 = 0;
	int n = a.size();
	if (n > 1) {
		vector<int> b(a.begin(), a.begin() + n / 2);
		vector<int> c(a.begin() + n / 2, a.end());
		mergecount(b, depth + 1);
		mergecount(c, depth + 1);
		for (int i = 0, j = 0, k = 0; i < n; ++i) {
			if (k == c.size())       a[i] = b[j++];
			else if (j == b.size())  a[i] = c[k++];
			else if (b[j] <= c[k])   a[i] = b[j++];
			else { a[i] = c[k++]; count += n / 2 - j; }
		}
		for (int i = 0; i < sz(b); i++) {
			auto r = equal_range(c.begin(), c.end(), b[i]);
			ll v = r.second - r.first;
			c2 += v;
		}
	}
	lt[depth] += count;
	eq[depth] += c2;
	return;
}

int main() {
	scanf("%d", &n);
	vector<int> a(1 << n);
	FOR(i,1 << n) scanf("%d", &a[i]);

	mergecount(a,0);
	int m;
	scanf("%d", &m);
	FOR(i, m) {
		int q; scanf("%d", &q);
		for (int i = n - q; i <= n; i++) {
			ll t = (1LL << (n - i)) / 2;
			ll u = 1LL << i;
			ll v = (t * t * u - eq[i]);
			lt[i] = v - lt[i];
		}
		ll ans = 0;
		for (int i = 0; i <= n; i++) {
			ans += lt[i];
		}
		printf("%I64d\n", ans);
	}

	return 0;
}