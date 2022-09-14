/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 5010;
int dp[maxn][maxn];
char s[maxn];
char t[maxn];

int lens;
int lent;

const int mod = (int)1e9 + 7;

int go(int p1, int p2) {
	if (dp[p1][p2] != -1) {
		return dp[p1][p2];
	}

	if (p2 == lent) {
		return dp[p1][p2] = 1;
	}

	if (p1 == lens) {
		return dp[p1][p2] = 1;
	}

	int ans = go(p1, p2 + 1);

	if (s[p1] == t[p2]) {
		ans += go(p1 + 1, p2 + 1);
	}

	if (ans >= mod) {
		ans -= mod;
	}

	return dp[p1][p2] = ans;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> s >> t;

	lens = strlen(s);
	lent = strlen(t);

	int ans = 0;

	for (int i = 0; i < lens; i++) {
		ans += go(i, 0);
		if (ans >= mod) {
			ans -= mod;
		}
	}

	ans -= lens;

	if (ans < 0) {
		ans += mod;
	}

	cout << ans << endl;

	return 0;
}