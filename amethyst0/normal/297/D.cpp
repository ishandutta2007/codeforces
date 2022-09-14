#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = 1010;

char a[maxn][maxn], b[maxn][maxn];

int ans[maxn][maxn];

bool good(char c, char a, char b) {
	return (c == 'E' && a == b) || (c == 'N' && a != b);
}

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	int cnt = 0;

	int num = 0;

	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);

		num += m - 1;

		for (int j = 0; j < m - 1; j++) {
			if (a[i][j] == 'E') {
				cnt++;
			}
		}

		if (i != n - 1) {
			num += m;
			scanf("%s", b[i]);

			for (int j = 0; j < m; j++) {
				if (b[i][j] == 'E') {
					cnt++;
				}
			}
		}
	}

	if (k == 1) {
		if (4 * cnt >= 3 * num) {
			printf("YES\n");

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					printf("1 ");
				}

				printf("\n");
			}
		}
		else {
			printf("NO\n");
		}

		//system("pause");

		return 0;
	}

	printf("YES\n");

	if (n < m) {
		for (int i = 0; i < n; i++) {
			int s = 0;

			ans[i][0] = s;

			int cnt = 0;

			if (i != 0 && good(b[i - 1][0], ans[i - 1][0], ans[i][0])) {
				cnt++;
			}

			for (int j = 1; j < m; j++) {
				if (a[i][j - 1] == 'N') {
					s ^= 1;
				}

				ans[i][j] = s;

				if (i != 0 && good(b[i - 1][j], ans[i - 1][j], ans[i][j])) {
					cnt++;
				}
			}

			if (i != 0 && 2 * cnt < m) {
				for (int j = 0; j < m; j++) {
					ans[i][j] ^= 1;
				}
			}
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			int s = 0;

			ans[0][i] = s;

			int cnt = 0;

			if (i != 0 && good(a[0][i - 1], ans[0][i - 1], ans[0][i])) {
				cnt++;
			}

			for (int j = 1; j < n; j++) {
				if (b[j - 1][i] == 'N') {
					s ^= 1;
				}

				ans[j][i] = s;

				if (i != 0 && good(a[j][i - 1], ans[j][i - 1], ans[j][i])) {
					cnt++;
				}
			}

			if (i != 0 && 2 * cnt < n) {
				for (int j = 0; j < n; j++) {
					ans[j][i] ^= 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", ans[i][j] + 1);
		}

		printf("\n");
	}

	//system("pause");
}