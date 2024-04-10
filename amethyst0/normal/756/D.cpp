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

const int maxn = 5010;
char s[maxn];
int dp[maxn][maxn];
int lnk[maxn][26];
int n;
const int mod = (int)1e9 + 7;

int go(int pos, int x) {
	if (dp[pos][x] != -1) {
		return dp[pos][x];
	}

	if (pos == n) {
		return dp[pos][x] = 1;
	}

	dp[pos][x] = go(pos + 1, x);

	for (int i = 0; i < 26; i++) {
		if (i != s[x] - 'a' && lnk[x][i] != n) {
			dp[pos][x] += go(pos + 1, lnk[x][i]);
			if (dp[pos][x] >= mod) {
				dp[pos][x] -= mod;
			}
		}
	}

	return dp[pos][x];
}

int now[maxn];

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	/*
	for (int i = 0; i < n; i++) {
		s[i] = 'a' + i % 26;
	}
	*/
	for (int i = 0; i < 26; i++) {
		lnk[n][i] = n;
	}

	for (int i = 0; i < n; i++) {
		dp[n][i] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			lnk[i][j] = lnk[i + 1][j];
		}
		
		int c = s[i] - 'a';

		int f = lnk[i][c];

		if (f != n) {
			for (int j = 0; j < n; j++) {
				now[j] -= dp[j + 1][f];
				if (now[j] < 0) {
					now[j] += mod;
				}
			}
		}

		lnk[i][c] = i;

		for (int j = n - 1; j >= 0; j--) {
			dp[j][i] = now[j] + dp[j + 1][i];
			if (dp[j][i] >= mod) {
				dp[j][i] -= mod;
			}
		}

		for (int j = 0; j < n; j++) {
			now[j] += dp[j + 1][i];
			if (now[j] >= mod) {
				now[j] -= mod;
			}
		}
	}

	cout << dp[0][0] << endl;

	//memset(dp, -1, sizeof dp);

	//cout << go(0, 0) << endl;

	return 0;
}