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


const int X = ten(5) + ten(2) + 1;
const int Y = ten(2) + 2;
int n, m;
int a[X];
int dp[X][Y];
int c[X][Y];

void init() {
	c[0][0] = 1;
	FOR(i, X - 1) {
		FOR(j, Y - 1) {
			if (j != 0) c[i + 1][j] = c[i][j-1];
			c[i + 1][j] += c[i][j];
			if (c[i + 1][j] >= MOD) c[i + 1][j] -= MOD;
		}
	}
}


int main(){
	init();
	scanf("%d%d", &n, &m);
	FOR(i, n) scanf("%d", a + i);

	FOR(i, m) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		l--;
		FOR(i, k + 1) {
			if (l < i) break;
			int tmp = c[l][i] * ((i % 2 == 0) ? 1 : -1);
			(dp[l][k - i] += tmp) %= MOD;
			(dp[r][k - i] -= tmp) %= MOD;
		}
	}

	ll cur_coef[101] = {};
	for (int i = 0; i < n; i++) {
		ll cur = a[i];
		FOR(k, 101) {
			cur_coef[k] += dp[i][k];
			if (cur_coef[k] >= MOD) cur_coef[k] -= MOD;
			else if (cur_coef[k] < 0) cur_coef[k] += MOD;
			cur = (cur + cur_coef[k] * c[i+k][k]) % MOD;
		}
		printf("%I64d%c",(cur + MOD) % MOD,i==n-1?'\n':' ');
	}

	return 0;
}