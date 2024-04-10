#include <bits/stdc++.h> 

using namespace std;

char s[7][7];

bool valid (int x, int y) {
	return x >= 1 and y >= 1 and x <= 4 and y <= 4 and s[x][y] == 'x';
}

int main (int argc, char const *argv[]) {
	for (int i = 1; i <= 4; ++i) {
		scanf("%s", s[i] + 1);
	}
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			if (s[i][j] == '.') {
				if (valid(i, j + 1) and valid(i, j + 2)) {
					puts("YES");
					return 0;
				}
				if (valid(i, j - 1) and valid(i, j - 2)) {
					puts("YES");
					return 0;
				}
				if (valid(i, j - 1) and valid(i, j + 1)) {
					puts("YES");
					return 0;
				}
				if (valid(i - 1, j) and valid(i - 2, j)) {
					puts("YES");
					return 0;
				}
				if (valid(i + 1, j) and valid(i + 2, j)) {
					puts("YES");
					return 0;
				}
				if (valid(i - 1, j) and valid(i + 1, j)) {
					puts("YES");
					return 0;
				}
				if (valid(i - 1, j - 1) and valid(i - 2, j - 2)) {
					puts("YES");
					return 0;
				}
				if (valid(i + 1, j + 1) and valid(i + 2, j + 2)) {
					puts("YES");
					return 0;
				}
				if (valid(i - 1, j - 1) and valid(i + 1, j + 1)) {
					puts("YES");
					return 0;
				}
				if (valid(i - 1, j + 1) and valid(i - 2, j + 2)) {
					puts("YES");
					return 0;
				}
				if (valid(i + 1, j - 1) and valid(i + 2, j - 2)) {
					puts("YES");
					return 0;
				}
				if (valid(i - 1, j + 1) and valid(i + 1, j - 1)) {
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}