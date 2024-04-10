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
#include <random>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = (int)2e3 + 10;

int dp[2][10][10][10][9][2];
int it;

int n;
int a[maxn], b[maxn];

int pos;

inline int go(int x, int y, int z, int w, int tp) {
	if (dp[it][x][y][z][w][tp] != -1) {
		return dp[it][x][y][z][w][tp];
	}

	if (pos == n && x == 9 && y == 9 && z == 9) {
		return dp[it][x][y][z][w][tp] = 0;
	}

	int cn = 0;
	int nx = x;
	int ny = y;
	int nz = z;

	if (x == w) {
		nx = 9;
		cn++;
	}

	if (y == w) {
		ny = 9;
		cn++;
	}

	if (z == w) {
		nz = 9;
		cn++;
	}

	if (cn != 0) {
		int ans = min(go(nx, ny, nz, w, 0), go(nx, ny, nz, w, 1));

		return dp[it][x][y][z][w][tp] = ans;
	}

	int nw = w + (tp == 1 ? 1 : -1);

	int ans = (int)1e9;

	if (0 <= nw && nw <= 8) {
		ans = go(x, y, z, nw, tp) + 1;
	}

	nx = x;
	ny = y;
	nz = z;

	if (pos != n && w == a[pos] && x == 9) {
		nx = b[pos];
	}

	if (pos != n && w == a[pos] && y == 9 && x != 9) {
		ny = b[pos];
	}

	if (pos != n && w == a[pos] && z == 9 && x != 9 && y != 9) {
		nz = b[pos];
	}

	if (nx != x || ny != y || nz != z) {
		ans = min(ans, min(dp[it ^ 1][nx][ny][nz][w][0], dp[it ^ 1][nx][ny][nz][w][1]));
	}
	else if (pos != n && w == a[pos]) {
		ans = min(ans, min(dp[it ^ 1][b[pos]][y][z][x][0], dp[it ^ 1][b[pos]][y][z][x][1]) + abs(w - x));
		ans = min(ans, min(dp[it ^ 1][x][b[pos]][z][y][0], dp[it ^ 1][x][b[pos]][z][y][1]) + abs(w - y));
		ans = min(ans, min(dp[it ^ 1][x][y][b[pos]][z][0], dp[it ^ 1][x][y][b[pos]][z][1]) + abs(w - z));
		ans = min(ans, min(dp[it ^ 1][x][y][z][b[pos]][0], dp[it ^ 1][x][y][z][b[pos]][1]) + abs(w - b[pos]));
	}

	return dp[it][x][y][z][w][tp] = ans;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
	}

	it = 0;

	for (pos = n; pos >= 0; pos--) {
		memset(dp[it], -1, sizeof dp[it]);

		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					for (int w = 0; w <= 8; w++) {
						for (int tp = 0; tp < 2; tp++) {
							go(i, j, k, w, tp);
						}
					}
				}
			}
		}

		it ^= 1;
	}

	cout << dp[it ^ 1][9][9][9][0][1] + 2 * n << endl;

	//system("pause");
}