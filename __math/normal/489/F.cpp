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
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n, m, mod;

inline void add_(int& to, int val){
	to += val;
	if (to >= mod) to -= mod;
}

int dp[2][501][501];

int main(){
	cin >> n >> m >> mod;

	vector<string> vs(m);
	FOR(i, m) cin >> vs[i];

	int X[500] = {} ;
	FOR(i, m) FOR(j, n){
		if (vs[i][j] == '1') X[j]++;
	}
	int r = 0, p = 0;
	FOR(i, n) if (X[i] == 0) r++; else if (X[i] == 1) p++;
	dp[0][r][p] = 1;

	auto cur = dp[0];
	auto nxt = dp[1];

	const int rem = n - m;
	FOR(i, rem){
		memset(nxt, 0, sizeof(dp[0]));
		FOR(two_rem, 501) FOR(one_rem, 501){
			if (cur[two_rem][one_rem]) {
				ll v = cur[two_rem][one_rem];
				if (two_rem >= 2) {
					add_(nxt[two_rem - 2][one_rem + 2], v * two_rem * (two_rem - 1) / 2 % mod);
				}
				if (two_rem >= 1 && one_rem >= 1) {
					add_(nxt[two_rem - 1][one_rem], v * two_rem * one_rem % mod);
				}
				if (one_rem >= 2) {
					add_(nxt[two_rem][one_rem - 2], v * one_rem * (one_rem - 1) / 2 % mod);
				}
			}
		}
		swap(cur, nxt);
	}

	ll ans = cur[0][0];
	cout << ans << endl;
}