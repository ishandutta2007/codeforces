#include <cstdio>
#include <algorithm>
#include <vector>

const int v[6] = {4, 8, 15, 16, 23, 42};

int ans[6], s[6][6], s1, s2;

int query(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int get(int a, int b) {
	int xa = -1, ya = -1, xb = -1, yb = -1;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (s[i][j] == a) {
				xa = i, ya = j;
			}
		}
	}
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (s[i][j] == b) {
				xb = i, yb = j;
			}
		}
	}
	return xa == xb || xa == yb ? xa : ya;
}

int main() {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			s[i][j] = v[i] * v[j];
		}
	}
	s1 = query(1, 2), s2 = query(2, 3);
	ans[1] = v[get(s1, s2)];
	ans[0] = s1 / ans[1], ans[2] = s2 / ans[1];
	s1 = query(4, 5), s2 = query(5, 6);
	ans[4] = v[get(s1, s2)];
	ans[3] = s1 / ans[4], ans[5] = s2 / ans[4];
	printf("! ");
	for (int i = 0; i < 6; ++i) {
		printf("%d ", ans[i]);
	}
	putchar('\n');
}