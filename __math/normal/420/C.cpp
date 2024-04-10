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

// 1-indexed
template<class T>
class BIT {
	T bit[ten(6)];
	int n;

public:
	BIT() {}

	BIT(int N) {
		clear(N);
	}

	void clear(int N) {
		n = N;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, T x) {
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int n, p;
int x[3 * ten(5) + 10], y[3 * ten(5) + 10];
int q[3 * ten(5) + 1];

BIT<ll> bit;

int main() {
	scanf("%d%d", &n, &p);
	FOR(i, n) scanf("%d%d", x + i, y + i);
	FOR(i, n) x[i]--, y[i]--;
	FOR(i, n) if (x[i] > y[i]) swap(x[i], y[i]);
	FOR(i, n) q[x[i]]++, q[y[i]]++;

	bit.clear(n);
	FOR(i, n) bit.add(q[i] + 1, 1);

	ll ans = 0;
	FOR(i, n) {
		//i - ??
		bit.add(q[i] + 1, -1);
		int k = max(0, p - q[i]);
		ll add = (n - i - 1) - bit.sum(k);
		ans += add;
	}

	map<Pii, int> s;
	FOR(i, n) s[Pii(x[i], y[i])]++;

	for (auto kv : s) {
		int x = q[kv.first.first] + q[kv.first.second];
		if (x >= p) ans -= 1;
		if (x - kv.second >= p) ans += 1;
	}

	cout << ans << endl;

	return 0;
}