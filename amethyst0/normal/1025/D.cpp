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
typedef long double ld;
#define mp make_pair

const int maxn = 710;
int dp[maxn][maxn][2];
int n;
int a[maxn];

int gcd(int x, int y) {
	return (y == 0 ? x : gcd(y, x % y));
}

bool can[maxn][maxn];

bool good(int l, int r, int tp) {
	if (l > r) {
		return true;
	}

	return dp[l][r][tp];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (gcd(a[i], a[j]) != 1) {
				can[i][j] = true;
			}
		}
	}

	for (int d = 1; d <= n; d++) {
		for (int l = 0; l <= n - d; l++) {
			for (int tp = 0; tp < 2; tp++) {
				int pos = l + d;
				if (tp == 0) {
					pos = l - 1;
				}
				if (pos == -1 || pos == n) {
					continue;
				}

				for (int m = l; m < l + d; m++) {
					if (can[pos][m] && good(l, m - 1, 1) && good(m + 1, l + d - 1, 0)) {
						dp[l][l + d - 1][tp] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (good(0, i - 1, 1) && good(i + 1, n - 1, 0)) {
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");
	//system("pause");
}