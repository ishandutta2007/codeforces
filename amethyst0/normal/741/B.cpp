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
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e3 + 10;
int b[maxn];
int v[maxn];
int p[maxn];

int get_parent(int x) {
	if (x == p[x]) {
		return x;
	}

	return p[x] = get_parent(p[x]);
}

vector <int> f[maxn];
int n;

int dp[maxn][maxn];

int go(int pos, int w) {
	if (dp[pos][w] != -1) {
		return dp[pos][w];
	}

	if (pos == n + 1) {
		dp[pos][w] = 0;
		return 0;
	}

	int ans = go(pos + 1, w);

	int sumw = 0;
	int sumb = 0;

	for (int i = 0; i < (int)f[pos].size(); i++) {
		int x = f[pos][i];

		if (v[x] <= w) {
			ans = max(ans, go(pos + 1, w - v[x]) + b[x]);
		}

		sumw += v[x];
		sumb += b[x];
	}

	if (sumw <= w) {
		ans = max(ans, go(pos + 1, w - sumw) + sumb);
	}

	return dp[pos][w] = ans;
}

int main() {
	int m, w;

	cin >> n >> m >> w;

	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		x = get_parent(x);
		y = get_parent(y);

		p[x] = y;
	}

	for (int i = 1; i <= n; i++) {
		int x = get_parent(i);

		f[x].push_back(i);
	}

	memset(dp, -1, sizeof dp);

	cout << go(1, w) << endl;

	return 0;
}