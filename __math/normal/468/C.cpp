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
const int MOD = 1000000009; // check!!!
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

#include <unordered_map>

typedef unsigned long long ull;

ull f(ull n) {
	ull ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

ull nsum(ull n) {
	vector<int> v;
	while (n) {
		v.push_back(n % 10);
		n /= 10;
	}

	ull p = 1;
	ull last = 0;
	ull low_val = 0;
	FOR(i, sz(v)) {
		ull cur = 45LL * i * p / 10 * v[i];
		cur += last;
		cur += v[i] * (v[i] - 1) / 2 * p;
		cur += v[i] * (low_val + 1);

		low_val = low_val + v[i] * p;
		last = cur;
		p *= 10;
	}

	return last;
}

ull near(ull n) {
	ull l = 0, r = ten(9) * ll(ten(7) * 2);
	while (r - l != 1) {
		ll md = (l + r) / 2;
		ull val = nsum(md);
		if (val >= n) r = md;
		else l = md;
	}
	return r;
}

int main() {

	ull a; cin >> a;
	ull r = near(a);
	ull l = 1;
	ull val = nsum(r);

	while (val != a) {
		while (val > a) {
			val -= f(l++);
		}
		while (val < a) {
			val += f(++r);
		}
	}
	//cout << nsum(r) - nsum(l - 1) << endl;

	cout << l << " " << r << endl;

	return 0;
}