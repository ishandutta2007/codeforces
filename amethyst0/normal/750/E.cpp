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

const int maxn = (int)2e5 + 10, inf = (int)1e7;
char s[maxn];
int t[4 * maxn][5][5];

inline void build(int it, int l, int r) {
	if (l == r) {
		for (int i = 0; i <= 4; i++) {
			t[it][i][i] = 0;
			for (int j = i + 1; j <= 4; j++) {
				t[it][i][j] = inf;
			}
		}

		if (s[l] == '6') {
			t[it][3][3]++;
			t[it][4][4]++;
		} else if (s[l] == '7') {
			t[it][3][4] = 0;
			t[it][3][3]++;
		} else if (s[l] == '1') {
			t[it][2][3] = 0;
			t[it][2][2]++;
		} else if (s[l] == '0') {
			t[it][1][2] = 0;
			t[it][1][1]++;
		} else if (s[l] == '2') {
			t[it][0][1] = 0;
			t[it][0][0]++;
		}
	} else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);

		for (int i = 0; i < 5; i++) {
			for (int j = i; j < 5; j++) {
				t[it][i][j] = inf;
				for (int k = i; k <= j; k++) {
					t[it][i][j] = min(t[2 * it][i][k] + t[2 * it + 1][k][j], t[it][i][j]);
				}
			}
		}
	}
}

int ans[5][5];

inline void go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				ans[i][j] = t[it][i][j];
			}
		}
	} else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			go(2 * it, l, m, lm, rm);
		} else if (lm > m) {
			go(2 * it + 1, m + 1, r, lm, rm);
		} else {
			int m = (l + r) >> 1;

			go(2 * it, l, m, lm, m);
			int a[5][5];
			memcpy(a, ans, sizeof ans);
			go(2 * it + 1, m + 1, r, m + 1, rm);
			int b[5][5];
			memcpy(b, ans, sizeof ans);

			for (int i = 0; i < 5; i++) {
				for (int j = i; j < 5; j++) {
					ans[i][j] = inf;
					for (int k = i; k <= j; k++) {
						ans[i][j] = min(ans[i][j], a[i][k] + b[k][j]);
					}
				}
			}
		}
	}
}

int main() {
	int n, q;

	cin >> n >> q;

	scanf("%s", s);

	build(1, 0, n - 1);

	for (int i = 0; i < q; i++) {
		int l, r;

		scanf("%d %d", &l, &r);
		l--;
		r--;
		go(1, 0, n - 1, l, r);

		if (ans[0][4] > n) {
			printf("-1\n");
		} else {
			printf("%d\n", ans[0][4]);
		}
	}

	return 0;
}