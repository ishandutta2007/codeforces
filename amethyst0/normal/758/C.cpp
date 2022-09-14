/*AMETHYSTS*/
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 1000;
ll g[maxn];
int xx[maxn][maxn];

int main() {
	int n, m, x, y;
	ll k;

	cin >> n >> m >> k >> x >> y;

	int pr = 2 * (n - 1);

	if (n == 1) {
		pr = 1;
	}

	ll f = k / m;

	for (int i = 0; i < pr; i++) {
		ll z = f / pr;

		if (i < f % pr) {
			z++;
		}

		if (i < n) {
			g[i] += z;
		} else {
			g[2 * n - i - 2] += z;
		}
	}

	int pos = f % pr;

	for (int i = 0; i < k % m; i++) {
		if (pos < n) {
			xx[pos][i]++;
		} else {
			xx[2 * n - pos - 2][i]++;
		}
	}

	ll maxx = 0;
	ll minx = xx[0][0] + g[0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxx = max(maxx, xx[i][j] + g[i]);
			minx = min(minx, xx[i][j] + g[i]);
		}
	}

	x--;
	y--;

	cout << maxx << ' ' << minx << ' ' << xx[x][y] + g[x];

	return 0;
}