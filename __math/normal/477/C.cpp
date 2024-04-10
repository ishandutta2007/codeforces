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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

int dp[2001][2001];

int main() {

	string s, p; cin >> s >> p;
	vector<int> v;
	FOR(i, sz(s)) {
		int r = i, pid = 0;
		for (; r < sz(s) && pid < sz(p); r++) {
			if (s[r] == p[pid]) pid++;
		}
		if (pid != sz(p)) r = -1;
		v.push_back(r);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	FOR(i, sz(s)) {
		FOR(j, sz(s)) {
			if (dp[i][j] == -1) continue;
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (v[i] != -1) {
				int rem = v[i] - i - sz(p);
				dp[v[i]][j + rem] = max(dp[v[i]][j + rem], dp[i][j] + 1);
			}
		}
	}

	int mx = 0;
	FOR(i, sz(s) + 1) mx = max(mx, dp[sz(s)][i]);
	int cur = 0;
	FOR(i, sz(s) + 1) {
		int val = dp[sz(s)][i];
		cur = max(val, cur);
		if (cur * sz(p) > sz(s) - i) cur--;
		printf("%d%c",cur,i==sz(s) ? '\n':' ');
	}

	return 0;
}