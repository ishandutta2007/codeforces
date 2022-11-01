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
template<class T> void chmax(T& a, const T b) {
	a = max(a, b);
}


//Rsy
// 1-indexed
template<class T> class BIT {
	static const int n = ten(6);
	T bit[n + 1];
public:
	BIT() {}
	T sum(int i) {
		T s = 0;
		while (i > 0) { chmax(s,bit[i]); i -= i & -i; }
		return s;
	}
	void add(int i, T x) {
		while (i <= n) { chmax(bit[i], x); i += i & -i; }
	}
};

int x[ten(5) * 2], w[ten(5) * 2];

BIT<int> bit;

int main() {
	int n; scanf("%d", &n);
	FOR(i, n) scanf("%d%d", x + i, w + i);
	vector<tuple<int,int,int> > v;
	FOR(i, n) {
		v.emplace_back(x[i], x[i] - w[i], x[i] + w[i]);
	}
	sort(v.begin(), v.end());
	vector<int> com;
	FOR(i, n) {
		int a, b, c;
		tie(a, b, c) = v[i];
		com.push_back(a);
		com.push_back(b);
		com.push_back(c);
	}
	sort(com.begin(), com.end());
	com.erase(unique(com.begin(), com.end()), com.end());

	FOR(i, n) {
		int a, b, c;
		tie(a, b, c) = v[i];
		a = lower_bound(com.begin(), com.end(), a) - com.begin();
		b = lower_bound(com.begin(), com.end(), b) - com.begin();
		c = lower_bound(com.begin(), com.end(), c) - com.begin();
		v[i] = make_tuple(a, b, c);
	}

	FOR(i, n) {
		int b, c; tie(ignore, b, c) = v[i];
		int nt = bit.sum(b) + 1;
		bit.add(c, nt);
	}

	int ans = bit.sum(sz(com));
	cout << ans << endl;
}