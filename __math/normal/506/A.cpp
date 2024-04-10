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

#pragma comment(linker,"/STACK:268435456")

const int C = 500;
int n, d;

int b[ten(4) * 3 + 10];

int memo[ten(4) * 3 + 1][C + 1];
map<int, int> mmemo[ten(4) * 3 + 1];

int dfs(int v, int len){
	if (v > ten(4) * 3) return 0;
	   if (len <= C && memo[v][len] != -1) return memo[v][len];
	else if (mmemo[v].count(len)) return mmemo[v][len];

	int mx = 0;
	if (len <= 2) {
		mx = b[ten(4) * 3 + 1] - b[v - 1];
	} else {
		mx = b[v] - b[v-1];
		int tmp = 0;
		for (int d = -1; d <= 1; d++) {
			int tt = dfs(v + len + d, len + d);
			tmp = max(tmp, tt);
		}
		mx += tmp;
	}

	if (len <= C) return memo[v][len] = mx;
	else return mmemo[v][len] = mx;
}

int main(){
	cin >> n >> d;
	FOR(i, n){
		int p; cin >> p;
		b[p]++;
	}

	FOR(i, ten(4) * 3 + 5) b[i + 1] += b[i];

	memset(memo, -1, sizeof(memo));
	int ans = dfs(d, d);
	cout << ans << endl;
}