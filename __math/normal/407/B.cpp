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

int n, p[ten(3) + 10];
ll memo[ten(3) + 10];

ll dfs(int id) {
	if (memo[id] != -1) return memo[id];
	ll cur = 2;
	int x = p[id];
	while (x != id) {
		cur = (cur + dfs(x)) % MOD;
		x++;
	}
	return memo[id] = cur;
}

int main() {
	cin >> n;
	FOR(i, n) cin >> p[i];
	FOR(i, n) p[i]--;
	memset(memo, -1, sizeof(memo));

	ll ans = 0;
	FOR(i, n) {
		ans = (ans + dfs(i)) % MOD;
	}
	cout << ans % MOD << endl;

	return 0;
}