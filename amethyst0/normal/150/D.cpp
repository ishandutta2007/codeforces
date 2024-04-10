/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
 
#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
 
using namespace std;

const int maxn = 155;
const int inf = (int)1e9;
char s[maxn];
ll v[maxn];
int n;

ll dp[maxn][maxn];
ll d[maxn][maxn][maxn];

ll gof(int l, int r, int c) {
	if (d[l][r][c] != -1) {
		return d[l][r][c];
	}

	if (l > r) {
		return d[l][r][c] = v[c];
	}

	ll ans = gof(l, r - 1, 0) + v[c + 1];
	ans = max(ans, gof(l, r - 1, c) + v[1]);
	if (c != 0) {
		ans = max(ans, gof(l, r, 0) + v[c]);
	}

	for (int i = r - 1; i >= l; i--) {
		if (s[i] == s[r]) {
			ans = max(ans, gof(l, i - 1, 0) + gof(i + 1, r - 1, c + 2));
			ans = max(ans, gof(i + 1, r - 1, 2) + gof(l, i - 1, c));
		}
	}

	if (ans < -inf) {
		ans = -inf;
	}

	return d[l][r][c] = ans;
}

ll go(int l, int r) {
	if (l > r) {
		return 0;
	}

	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	ll ans = go(l, r - 1) + max(0ll, v[1]);

	for (int i = r - 1; i >= l; i--) {
		if (s[i] == s[r]) {
			ans = max(ans, go(l, i - 1) + gof(i + 1, r - 1, 2));
		}
	}

	return dp[l][r] = ans;
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];

		if (v[i] == -1) {
			v[i] = -inf;
		}
	}

	scanf("%s", s);

	memset(dp, -1, sizeof dp);
	memset(d, -1, sizeof d);

	cout << go(0, n - 1) << endl;

	return 0;
}