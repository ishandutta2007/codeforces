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
//#include <unordered_map>
//#include <random>
//#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e3 + 10;

bool x[maxn], y[maxn];
int n;

ld dp[maxn][maxn];
bool used[maxn][maxn];

ld go(int a, int b) {
	if (used[a][b]) {
		return dp[a][b];
	}

	if (a == 0 && b == 0) {
		dp[a][b] = 0;
		return 0;
	}

	used[a][b] = true;

	ld ver = 1 - 1.0 / n / n * (n - a) * (n - b);

	dp[a][b] = 1 / ver;

	if (a != 0 && b != 0)
		dp[a][b] += (go(a - 1, b - 1)) / n / n * a * b / ver;
	if (a != 0)
		dp[a][b] += (go(a - 1, b)) / n / n * a * (n - b) / ver;
	if (b != 0)
		dp[a][b] += (go(a, b - 1)) / n / n * (n - a) * b / ver;

	return dp[a][b];
}

int main() {
	cin >> n;

	int m;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		x[a] = true;
		y[b] = true;
	}

	int a = 0, b = 0;

	for (int i = 1; i <= n; i++) {
		if (!x[i]) {
			a++;
		}

		if (!y[i]) {
			b++;
		}
	}

	printf("%.10lf\n", go(a, b));

	return 0;
}