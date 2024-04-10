#pragma comment(linker, "/STACK:1000000000")
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
#include <ctime>

#define ll long long
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = 2010;
int lnk[maxn][maxn];
int dst[maxn][maxn];
char c[maxn][maxn];

void write(int x, int y) {
	if (x == 0 && y == 0) {
		if (dst[x][y] != 0) {
			printf("a");
		}
		else {
			printf("%c", c[x][y]);
		}

		return;
	}

	int px = x;
	int py = y;

	if (lnk[x][y] == 0) {
		px--;
	}
	else {
		py--;
	}

	write(px, py);

	if (dst[px][py] != dst[x][y]) {
		printf("a");
	}
	else {
		printf("%c", c[x][y]);
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dst[i][j] = (int)1e9;
		}
	}

	dst[0][0] = 0;

	if (c[0][0] != 'a' && k != 0) {
		dst[0][0] = 1;
	}

	for (int d = 0; d < 2 * n - 2; d++) {
		bool fl = false;

		char f = 'z';

		for (int i = 0; i < n; i++) {
			int j = d - i;

			if (j < 0 || j >= n) {
				continue;
			}

			if (dst[i][j] < k) {
				fl = true;
			}

			if (i + 1 < n && dst[i][j] == k) {
				f = min(f, c[i + 1][j]);
			}

			if (j + 1 < n && dst[i][j] == k) {
				f = min(f, c[i][j + 1]);
			}
		}

		if (fl) {
			for (int i = 0; i < n; i++) {
				int j = d - i;

				if (j < 0 || j >= n) {
					continue;
				}

				if (i + 1 < n) {
					char cc = c[i + 1][j];

					int p = 0;

					if (cc != 'a') {
						p++;
					}

					if (dst[i + 1][j] > dst[i][j] + p && dst[i][j] + p != k + 1) {
						dst[i + 1][j] = dst[i][j] + p;
						lnk[i + 1][j] = 0;
					}
				}

				if (j + 1 < n) {
					char cc = c[i][j + 1];

					int p = 0;

					if (cc != 'a') {
						p++;
					}

					if (dst[i][j + 1] > dst[i][j] + p && dst[i][j] + p != k + 1) {
						dst[i][j + 1] = dst[i][j] + p;
						lnk[i][j + 1] = 1;
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				int j = d - i;

				if (j < 0 || j >= n) {
					continue;
				}

				if (dst[i][j] != k) {
					continue;
				}

				if (i + 1 < n && c[i + 1][j] == f) {
					dst[i + 1][j] = dst[i][j];
					lnk[i + 1][j] = 0;
				}

				if (j + 1 < n && c[i][j + 1] == f) {
					dst[i][j + 1] = dst[i][j];
					lnk[i][j + 1] = 1;
				}
			}
		}
	}

	write(n - 1, n - 1);

	//system("pause");
}