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

const int maxn = 500;

bool used[maxn][maxn], dp[maxn][maxn][30][3][3];
int v[maxn];
int n;

int go(int x, int y, int pos, int dx, int dy) {
	if (dx != 0) {
		dx /= abs(dx);
	}

	if (dy != 0) {
		dy /= abs(dy);
	}

	if (dp[x][y][pos][dx + 1][dy + 1]) {
		return 0;
	}

	dp[x][y][pos][dx + 1][dy + 1] = true;

	if (pos == n) {
		return 0;
	}

	int ans = 0;

	for (int i = 0; i < v[pos]; i++) {
		x += dx;
		y += dy;

		if (!used[x][y]) {
			used[x][y] = true;
			ans++;
		}
	}

	return ans + go(x, y, pos + 1, dx + dy, dy - dx) + go(x, y, pos + 1, dx - dy, dx + dy);
}

int main() {
	cin >> n;
	//n = 30;

	int x = 200;
	int y = 200;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		//v[i] = 5;
	}

	cout << go(x, y, 0, 0, 1) << endl;

	return 0;
}