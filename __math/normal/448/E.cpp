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

vector<ll> divisors(ll x) {
	vector<ll> ret;
	ret.push_back(1);
	for (int i = 2; ll(i) * i <= x; i++) {
		if (x % i != 0) continue;
		int cnt = 0;
		while (x % i == 0) x /= i, cnt++;
		int s = sz(ret);
		ll val = i;
		FOR(j, cnt) {
			FOR(k, s) {
				ret.push_back(ret[k] * val);
			}
			val *= i;
		}
	}
	if (x != 1) {
		int s = sz(ret);
		FOR(i, s) ret.push_back(ret[i] * x);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

vector<vector<int> > v;
vector<int> anses;

void f(int x, int k) {
	if (sz(anses) >= ten(5)) return;
	if (k == 0 || x == 0) {
		anses.push_back(x);
		return;
	}
	for (auto i : v[x]) {
		if (sz(anses) >= ten(5)) return;
		f(i, k - 1);
	}
}

int main() {
	ll x, k; cin >> x >> k;
	if (x == 1) {
		puts("1");
		return 0;
	}
	k = min<ll>(k, ten(5));

	auto dv = divisors(x);
	for (ll a : dv) {
		v.emplace_back();
		FOR(i,sz(dv)){
			if (a % dv[i] == 0) v.back().push_back(i);
		}
	}

	f(sz(dv) - 1, (int)k);
	FOR(i, sz(anses)) printf("%I64d%c",dv[anses[i]],i==sz(anses)-1?'\n':' ');

}