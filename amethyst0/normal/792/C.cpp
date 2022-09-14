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
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = (int)2e5 + 10;
char s[maxn];
int n;
int dp[maxn][3][2];
int lnk[maxn][3][2];

int go(int pos, int o, int f) {
	if (dp[pos][o][f] != -1) {
		return dp[pos][o][f];
	}

	if (pos == n) {
		if (o == 0 && f == 1) {
			dp[pos][o][f] = 0;
		} else {
			dp[pos][o][f] = (int)1e9;
		}

		return dp[pos][o][f];
	}

	dp[pos][o][f] = 1 + go(pos + 1, o, f);
	lnk[pos][o][f] = 0;

	if ((f != 0 || (f == 0 && s[pos] != '0')) && dp[pos][o][f] > go(pos + 1, (o * 10 + s[pos] - '0') % 3, 1)) {
		dp[pos][o][f] = go(pos + 1, (o * 10 + s[pos] - '0') % 3, 1);
		lnk[pos][o][f] = 1;
	}

	return dp[pos][o][f];
}

void make(int pos, int o, int f) {
	if (pos == n) {
		return;
	}

	if (lnk[pos][o][f] == 1) {
		printf("%c", s[pos]);
		make(pos + 1, (o * 10 + s[pos] - '0') % 3, 1);
	} else {
		make(pos + 1, o, f);
	}
}

int main() {
	scanf("%s", s);

	n = strlen(s);

	memset(dp, -1, sizeof dp);

	if (go(0, 0, 0) != (int)1e9) {
		make(0, 0, 0);
	} else {
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				cout << s[i];
				return 0;
			}
		}

		cout << -1 << endl;
	}

	return 0;
}