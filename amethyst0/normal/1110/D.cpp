#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = (int)1e6 + 10;

int cnt[maxn];

int dp[maxn][5][3];

const int inf = (int)1e9;

int go(int pos, int x, int y) {
	if (dp[pos][x][y] != -1) {
		return dp[pos][x][y];
	}

	if (pos == maxn - 1) {
		if (x == 0 && y == 0) {
			return dp[pos][x][y] = 0;
		}

		return dp[pos][x][y] = -inf;
	}

	if (cnt[pos] < x) {
		return dp[pos][x][y] = -inf;
	}

	int ans = -inf;

	for (int i = 0; i <= min(2, cnt[pos] - x); i++) {
		ans = max(ans, go(pos + 1, y + i, i) + (cnt[pos] - x - i) / 3 + i);
	}

	return dp[pos][x][y] = ans;
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);
		cnt[x]++;
	}

	memset(dp, -1, sizeof dp);

	cout << go(0, 0, 0) << endl;

	//system("pause");

	return 0;
}