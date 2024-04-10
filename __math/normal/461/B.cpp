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

int x[ten(5)];
vector<int> e[ten(5)];

Pll dfs(int p, int v) {
	Pll ret;
	if (x[v] == 0) ret.first = 1;
	else ret.second = 1;
	for (auto to : e[v]) {
		if (p == to) continue;
		Pll r = dfs(v, to);
		ll sm = (r.first + r.second) * (ret.first + ret.second) % MOD;
		ll nf = (ret.first * (r.first + r.second)) % MOD;
		ll ns = (sm - r.first * ret.first) % MOD;
		ret.first = nf;
		ret.second = ns;
	}
	return ret;
}

int main() {
	static int p[ten(5)];
	int n; scanf("%d", &n);
	FOR(i, n - 1) scanf("%d", p + i);
	FOR(i, n) scanf("%d", x + i);

	FOR(i, n  -1) {
		int c = i + 1;
		e[c].push_back(p[i]);
		e[p[i]].push_back(c);
	}

	Pll v = dfs(-1,0);
	ll ans = v.second;
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << endl;


	return 0;
}