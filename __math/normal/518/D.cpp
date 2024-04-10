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

double memo[2001][2001];

int main(){
	int n, t; double p;
	cin >> n >> p >> t;
	memo[0][0] = 1;
	FOR(i, t){
		FOR(j, 2001){
			if (memo[i][j] == 0) continue;
			if (j < n) {
				memo[i + 1][j + 1] += memo[i][j] * p;
				memo[i + 1][j] += memo[i][j] * (1 - p);
			} else {
				memo[i + 1][j] += memo[i][j];
			}
		}
	}

	double ans = 0;
	FOR(i, n + 1){
		ans += memo[t][i] * i;
	}

	printf("%.10lf\n", ans);
}