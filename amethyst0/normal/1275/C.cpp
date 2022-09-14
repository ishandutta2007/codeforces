//#pragma comment(linker, "/STACK:1000000000")
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
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;
int dp[maxn][5];
char s[maxn];
pii nxt[maxn][5];

int n;

int go(int pos, int fl) {
	if (dp[pos][fl] != -1) {
		return dp[pos][fl];
	}

	if (pos == n) {
		return dp[pos][fl] = 0;
	}

	int ans = go(pos + 1, fl) + 1;
	nxt[pos][fl] = mp(1, fl);

	char c = s[pos];

	if (c == 'e' && fl == 2) {

	}
	else if (c == 'o' && fl == 4) {
		
	}
	else if (c == 'n' && fl == 1) {
		if (ans > go(pos + 1, 2)) {
			ans = go(pos + 1, 2);
			nxt[pos][fl] = mp(0, 2);
		}
	}
	else if (c == 'w' && fl == 3) {
		if (ans > go(pos + 1, 4)) {
			ans = go(pos + 1, 4);
			nxt[pos][fl] = mp(0, 4);
		}
	}
	else if (c == 't') {
		if (ans > go(pos + 1, 3)) {
			ans = go(pos + 1, 3);
			nxt[pos][fl] = mp(0, 3);
		}
	}
	else if (c == 'o') {
		if (ans > go(pos + 1, 1)) {
			ans = go(pos + 1, 1);
			nxt[pos][fl] = mp(0, 1);
		}
	}
	else {
		if (ans > go(pos + 1, 0)) {
			ans = go(pos + 1, 0);
			nxt[pos][fl] = mp(0, 0);
		}
	}

	return dp[pos][fl] = ans;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		scanf("%s", s);
		n = strlen(s);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 5; j++) {
				dp[i][j] = -1;
			}
		}

		printf("%d\n", go(0, 0));

		int pos = 0;
		int fl = 0;

		while (pos < n) {
			if (nxt[pos][fl].first == 1) {
				printf("%d ", pos + 1);
			}

			fl = nxt[pos][fl].second;
			pos++;
		}

		printf("\n");
	}

	//system("pause");
}