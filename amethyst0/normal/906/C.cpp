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

const int maxn = 22;

int dp[1 << maxn];
int to[1 << maxn];
int ed[maxn];

int main() {
	int n, m;

	cin >> n >> m;

	if (m == n * (n - 1) / 2) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < m; i++) {
		int x, y;

		cin >> x >> y;

		x--;
		y--;

		ed[x] |= 1 << y;
		ed[y] |= 1 << x;
	}

	dp[(1 << n) - 1] = 0;

	for (int ms = (1 << n) - 2; ms > 0; ms--) {
		dp[ms] = (int)1e9;
		for (int i = 0; i < n; i++) {
			if ((ms >> i) & 1) {
				if (dp[ms] > dp[ms | ed[i]] + 1) {
					dp[ms] = dp[ms | ed[i]] + 1;
					to[ms] = i;
				}
			}
		}
	}

	int best = 0;

	for (int i = 1; i < n; i++) {
		if (dp[1 << best] > dp[1 << i]) {
			best = i;
		}
	}

	cout << dp[1 << best] << endl;

	int now = (1 << best);

	while (now != (1 << n) - 1) {
		cout << to[now] + 1 << ' ';
		now |= ed[to[now]];
	}

	return 0;
}