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

//  : MODvZtB

int popcount(ll x) {
	x = (x & 0x5555555555555555ULL) + ((x & 0xAAAAAAAAAAAAAAAAULL) >> 1);
	x = (x & 0x3333333333333333ULL) + ((x & 0xCCCCCCCCCCCCCCCCULL) >> 2);
	x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x & 0xF0F0F0F0F0F0F0F0ULL) >> 4);
	return (int)(x * 0x0101010101010101ULL >> 56);
}

typedef unsigned long long ull;

int m, n; ll t; ll mo;
ll a[1048576];
int bb[100];
ll b[1048576];

ll mul(ll a, ll b) {
	return ((a*b - ll(((long double)a) / mo*b + 1e-3)*mo) + mo) % mo;
}

template<class T> ull mod_pow(T a, T n) {
	ull ret = 1;
	ull p = a;
	while (n) {
		if (n & 1) ret = mul(ret, p);
		p = mul(p, p);
		n >>= 1;
	}
	return ret;
}

void fwt(ll* v, int size) {
	if (size == 1) return;
	int s2 = size / 2;
	fwt(v, s2);
	fwt(v + s2, s2);
	FOR(i, s2) {
		ll A = v[i];
		ll B = v[i + s2];
		v[i] = (A + B) % mo;
		v[i + s2] = (A - B) % mo;
	}
}

int main() {
	cin >> m >> t >> mo;
	n = 1 << m;
	mo *= n;
	for (int i = 0; i<n; i++)scanf("%I64d", &a[i]);
	for (int i = 0; i <= m; i++)scanf("%d", &bb[i]);
	for (int i = 0; i<m; i++)
	for (int i = 0; i<n; i++)b[i] = bb[popcount(i)];
	fwt(a, n);
	fwt(b,n);
	for (int i = 0; i<n; i++)a[i] = mul(a[i], mod_pow(b[i], t));
	fwt(a, n);
	for (int i = 0; i<n; i++)printf("%I64d\n", ((a[i] + mo) % mo) >> m);
	return 0;
}