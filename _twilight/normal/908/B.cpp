#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int mov[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};

int n, m, l;
int sx, sy;
int key[4];
char str[105];
char a[55][55];

inline void init() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'S') {
				sx = i, sy = j;
			}
		}
	}
	scanf("%s", str);
	l = strlen(str);
	for (int i = 0; i < l; i++)
		str[i] -= '0';
}

int ans = 0;
boolean simulate() {
	int curx = sx, cury = sy;
	for (int i = 0; i < l; i++) {
		int dir = key[str[i]];
		curx += mov[0][dir], cury += mov[1][dir];
		if (curx < 1 || curx > n || cury < 1 || cury > m)
			return false;
		if (a[curx][cury] == '#')
			return false;
		if (a[curx][cury] == 'E')
			return true;
	}
	return false;
}

inline void solve() {
	for (int a = 0; a < 4; a++)
		for (int b = 0; b < 4; b++)
			if (a != b)
				for (int c = 0; c < 4; c++)
					if (c != b && c != a)
						for (int d = 0; d < 4; d++)
							if ((a != d) && (b != d) && (c != d)) {
								key[0] = a, key[1] = b;
								key[2] = c, key[3] = d;
								ans += simulate();
							}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}