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
template<class T> void chmax(T& a, T b) { a = max(a, b); }
template<class T> void chmin(T& a, T b) { a = min(a, b); }

#pragma comment(linker,"/STACK:36777216")

ll dp[1001][100];

int solve(int n, int k,int m){
	dp[0][0] = 1;
	int base = 1;
	FOR(i, n){
		for (int j = 0; j < 10; j++) {
			if (i == n - 1 && j == 0) continue;
			int add = base * j % k;
			FOR(l, k){
				// from dp[i][l];
				int md = (add + l) % k;
				if (md == 0) {
					dp[i + 1][0] = 1;
				} else {
					(dp[i + 1][md] += dp[i][l]) %= m;
				}
			}
		}
		base = base * 10 % k;
	}
	ll ans1 = 0;
	for (int i = 1; i < k; i++) ans1 += dp[n][i];
	ll ans2 = 9;
	FOR(i, n - 1) ans2 = ans2 * 10 % m;
	cout << ((ans2 - ans1) % m + m) % m << endl;

	return 0;
}

int main(){
	int n, k, m; cin >> n >> k >> m;


	solve(n, k, m);
}