#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = 55;
int dp[maxn][maxn][maxn][maxn];
char c[maxn][maxn];

int r[maxn][maxn];
int d[maxn][maxn];

int go(int lx, int rx, int ly, int ry) {
	if (lx > rx || ly > ry) {
		return 0;
	}

	if (dp[lx][rx][ly][ry] != -1) {
		return dp[lx][rx][ly][ry];
	}

	if (lx == rx && ly == ry) {
		if (c[lx][ly] == '#') {
			return dp[lx][rx][ly][ry] = 1;
		}
		else {
			return dp[lx][rx][ly][ry] = 0;
		}
	}

	int ans = max(ry - ly + 1, rx - lx + 1);

	if (rx - lx > ry - ly) {
		for (int i = lx; i <= rx; i++) {
			if (r[i][ly] > ry) {
				ans = min(ans, go(lx, i - 1, ly, ry) + go(i + 1, rx, ly, ry));
			}
		}
	}
	else {
		for (int i = ly; i <= ry; i++) {
			if (d[lx][i] > rx) {
				ans = min(ans, go(lx, rx, ly, i - 1) + go(lx, rx, i + 1, ry));
			}
		}
	}

	return dp[lx][rx][ly][ry] = ans;
}

int main() {
	memset(dp, -1, sizeof dp);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (c[i][j] == '#') {
				r[i][j] = j;
				d[i][j] = i;
			}
			else {
				if (i == n - 1) {
					d[i][j] = n;
				}
				else {
					d[i][j] = d[i + 1][j];
				}

				if (j == n - 1) {
					r[i][j] = n;
				}
				else {
					r[i][j] = r[i][j + 1];
				}
			}
		}
	}

	memset(dp, -1, sizeof dp);

	cout << go(0, n - 1, 0, n - 1) << endl;

	//system("pause");
}