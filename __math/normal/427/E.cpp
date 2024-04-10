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
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int a[ten(6)];
ll b[ten(6) + 1], c[ten(6) + 1];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, n) scanf("%d", a + i);

	for (int i = 0; i*m < n; i++) {
		b[i + 1] = a[i*m] + b[i];
	}
	reverse(a, a + n);
	int xx = 0;
	for (int i = 0; i*m < n; i++,xx++) {
		c[i + 1] = a[i*m] + c[i];
	}
	reverse(a, a + n);
	 
	ll min_dist = 1LL << 60;
	for (int d = 0; d < n; d++) {
		int left_id = (d + m - 1) / m;
		ll left = a[d] * ll(left_id) - b[left_id];
		int right_id = (n - 1 - d + m - 1) / m;
		ll right = c[right_id] - a[d] * ll(right_id);

		ll cost = left + right;
		min_dist = min(min_dist, cost);
	}

	cout << min_dist * 2 << endl;

	return 0;
}