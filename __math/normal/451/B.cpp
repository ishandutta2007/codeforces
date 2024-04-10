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

template<class T> ll mod_pow(T a, T n, T mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	FOR(i, n) cin >> a[i];
	vector<int> b = a;
	sort(b.begin(), b.end());

	Pii p(-1, -1);
	FOR(i, n) {
		if (a[i] != b[i]) {
			p.first = i;
			p.second = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			break;
		}
	}

	if (p.first == -1) {
		puts("yes\n1 1");
		return 0;
	}

	for (int i = p.first; i <= p.second; i++) {
		int j = p.first + p.second - i;
		if (j <= i) break;
		swap(a[i], a[j]);
	}

	if (a == b) {
		printf("yes\n%d %d\n", p.first + 1, p.second + 1);
	} else {
		puts("no");
	}

}