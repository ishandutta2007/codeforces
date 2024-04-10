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
	T bit[ten(6) + 10];
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

BIT<int> bit(ten(6));

int n;
int a[ten(6) + 1];

vector<int> f() {
	
	vector<int> v(n),ret;
	FOR(i, n) {
		v[a[i]]++;
		ret.push_back(v[a[i]]);
	};
	return ret;
}

int main() {
	scanf("%d", &n);
	FOR(i, n) scanf("%d", a + i);

	vector<int> com;
	FOR(i, n) com.push_back(a[i]);
	sort(com.begin(), com.end());
	com.erase(unique(com.begin(), com.end()), com.end());
	FOR(i, n) a[i] = lower_bound(com.begin(), com.end(), a[i]) - com.begin();

	vector<int> l = f();
	reverse(a, a + n);
	vector<int> r = f();
	reverse(r.begin(), r.end());

	ll ans = 0;
	for (int j = 1; j < n; j++) {
		bit.add(l[j - 1] + 1, 1);
		int add = j - bit.sum(r[j] + 1);
		ans += add;
	}

	cout << ans << endl;

	return 0;
}