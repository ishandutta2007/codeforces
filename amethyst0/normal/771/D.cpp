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
#define ld double
#define pii pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = 75;

int n;
string s;

int dp[maxn][maxn][maxn][maxn][2];
int lnk[maxn + 1][3][maxn + 1];
int t[maxn + 1];

void change(int pos, int x) {
	for ( ; pos < maxn; pos |= pos + 1) {
		t[pos] += x;
	}
}

int go(int pos) {
	int ans = 0;
	for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += t[pos];
	}

	return ans;
}

set <int> q;

int typ(char c) {
	if (c == 'V') {
		return 0;
	}

	if (c == 'K') {
		return 1;
	}

	return 2;
}

int getdp(int pos, int a, int b, int c, int d) {
	if (pos == n) {
		return 0;
	}

    if (dp[pos][a][b][c][d] != -1) {
		return dp[pos][a][b][c][d];
	}

	if (!q.empty() && (*q.begin()) == pos) {
		q.erase(q.begin());

		int g = typ(s[pos]);
		change(pos, -1);

		if (g == 0) {
			a--;
		} else if (g == 1) {
			b--;
		} else {
			c--;
		}

		int ans = getdp(pos + 1, a, b, c, d);

		change(pos, 1);
		q.insert(pos);

		if (g == 0) {
			a++;
		} else if (g == 1) {
			b++;
		} else {
			c++;
		}

		return dp[pos][a][b][c][d] = ans;
	}

	int ans = (int)1e9;

	if (lnk[pos][0][a] != -1) {
		q.insert(lnk[pos][0][a]);
		change(lnk[pos][0][a], 1);
		ans = min(ans, getdp(pos, a + 1, b, c, 1) + lnk[pos][0][a] - pos - go(lnk[pos][0][a]) + 1);
		change(lnk[pos][0][a], -1);
		q.erase(lnk[pos][0][a]);
	}

	if (lnk[pos][1][b] != -1 && d != 1) {
		q.insert(lnk[pos][1][b]);
		change(lnk[pos][1][b], 1);
		ans = min(ans, getdp(pos, a, b + 1, c, 0) + lnk[pos][1][b] - pos - go(lnk[pos][1][b]) + 1);
		change(lnk[pos][1][b], -1);
		q.erase(lnk[pos][1][b]);
	}

	if (lnk[pos][2][c] != -1) {
		q.insert(lnk[pos][2][c]);
		change(lnk[pos][2][c], 1);
		ans = min(ans, getdp(pos, a, b, c + 1, 0) + lnk[pos][2][c] - pos - go(lnk[pos][2][c]) + 1);
		change(lnk[pos][2][c], -1);
		q.erase(lnk[pos][2][c]);
	}

	return dp[pos][a][b][c][d] = ans;
}
		
int main() {
	cin >> n >> s;

	memset(lnk, -1, sizeof lnk);

	for (int i = n - 1; i >= 0; i--) {
		int x = i;
		memcpy(lnk[i], lnk[i + 1], sizeof lnk[i + 1]);

		int tp = 2;

		if (s[i] == 'V') {
			tp = 0;
		} else if (s[i] == 'K') {
			tp = 1;
		}

		for (int j = 0; j < maxn; j++) {
			if (x == -1) {
				break;
			}

			swap(lnk[i][tp][j], x);
		}
	}

	memset(dp, -1, sizeof dp);

	cout << getdp(0, 0, 0, 0, 0) << endl;

	return 0;
}