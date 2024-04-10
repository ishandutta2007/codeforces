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

ll factorial[1010];
const int NCK = 1010;

ll nck[NCK + 1][NCK + 1];
void calc_nck() {
	FOR(i, NCK) {
		nck[i][0] = nck[i][i] = 1;
		for (int j = 1; j <= i; j++) {
			nck[i + 1][j] = (nck[i][j - 1] + nck[i][j]) % MOD;
		}
	}
}

ll memo[1000][100];


void init() {
	memset(memo, -1, sizeof(memo));
	factorial[0] = 1;
	for (int i = 1; i < 1010; i++) {
		factorial[i] = factorial[i - 1] * i % MOD;
	}
	calc_nck();
}

ll dfs(int x, int k) {
	if (memo[x][k] != -1) return memo[x][k];
	if (k == 1) return memo[x][k] = 1;
	ll val = 0;
	for (int beta = 0; beta * k <= x; beta++) {
		val += dfs(x - beta * k, k - 1);
	}
	return memo[x][k] = val % MOD;
}

ll g(int x,int k) {
	return dfs(x, k);
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int min_n = k + k * (k - 1) / 2;
		if (n < min_n) {
			puts("0");
			continue;
		}
		ll ans = 0;
		for (int x = k * (k - 1) / 2; x + k <= n; x++) {
			int p = n - x;
			ll a = nck[p][k] * factorial[k] % MOD;
			a = a * g(x - k * (k - 1) / 2, k) % MOD;
			ans = (ans + a) % MOD;
		}
		cout << ans % MOD << endl;
	}

	return 0;
}