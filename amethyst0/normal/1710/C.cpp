#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = (int)2e5 + 10;
const int mod = 998244353;
char s[maxn];

int dp[maxn][4][4][2][8];

int mul(int a, int b) {
	return (ll)a * b % mod;
}

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int go(int pos, int a, int c, int ok, int ph) {
	if (pos == -1) {
		return ok;
	}

	if (dp[pos][a][c][ok][ph] != -1) {
		return dp[pos][a][c][ok][ph];
	}

	dp[pos][a][c][ok][ph] = 0;

	for (int ms = 0; ms < 8; ms++) {
		int x = (ms & 1) ^ ((ms >> 1) & 1);
		int y = (ms & 1) ^ ((ms >> 2) & 1);
		int z = ((ms >> 1) & 1) ^ ((ms >> 2) & 1);

		if (s[pos] == '0') {
			if (ms & 1) {
				if (!(ph & 1)) {
					continue;
				}
			}
			if (ms & 2) {
				if (!(ph & 2)) {
					continue;
				}
			}
			if (ms & 4) {
				if (!(ph & 4)) {
					continue;
				}
			}
		}

		int nph = ph;

		if (s[pos] == '1') {
			if (!(ms & 1)) {
				nph |= 1;
			}

			if (!(ms & 2)) {
				nph |= 2;
			}

			if (!(ms & 4)) {
				nph |= 4;
			}
		}

		int na = a;
		int nc = c;
		if (na == 3 && ms != 0 && ms != 7) {
			int cn = 0;
			if (x == 0) {
				cn |= 1;
			}
			if (y == 0) {
				cn |= 2;
			}
			if (z == 0) {
				cn |= 4;
			}

			if (c != 3) {
				cn &= 7 ^ (1 << c);
			}

			if (cn == 1) {
				na = 0;
			}
			else if (cn == 2) {
				na = 1;
			}
			else if (cn == 4) {
				na = 2;
			}
		}
		if (nc == 3 && ms != 0 && ms != 7) {
			int cn = 0;
			if (x == 1) {
				cn |= 1;
			}
			if (y == 1) {
				cn |= 2;
			}
			if (z == 1) {
				cn |= 4;
			}

			if (a != 3) {
				cn &= 7 ^ (1 << a);
			}

			if (cn == 1) {
				nc = 0;
			}
			else if (cn == 2) {
				nc = 1;
			}
			else if (cn == 4) {
				nc = 2;
			}
		}

		int h[3] = { x, y, z };
		int nok = ok;
		if (nc != 3) {
			pii ids = { -1, -1 };
			for (int i = 0; i < 3; i++) {
				if (i != nc) {
					if (ids.first == -1) {
						ids.first = i;
					}
					else {
						ids.second = i;
					}
				}
			}

			if (h[ids.first] + h[ids.second] > h[nc]) {
				nok = 1;
			}
		}
		dp[pos][a][c][ok][ph] = add(dp[pos][a][c][ok][ph], go(pos - 1, na, nc, nok, nph));
	}

	return dp[pos][a][c][ok][ph];
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%s", s);

	int n = strlen(s);
	reverse(s, s + n);

	cout << go(n - 1, 3, 3, 0, 0) << '\n';
}