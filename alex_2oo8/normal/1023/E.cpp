#include <bits/stdc++.h>

using namespace std;

const int MX = 500;


bool can(int a, int b, int c, int d) {
	printf("? %d %d %d %d\n", a, b, c, d);
	fflush(stdout);
	static char s[5];
	ignore = scanf(" %s", s);
	return s[0] == 'Y';
}

char ans[2 * MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	for (int i = 0, x = 1, y = 1; i < n - 1; i++) {
		if (x < n && can(x + 1, y, n, n)) {
			ans[i] = 'D';
			x++;
		}
		else {
			ans[i] = 'R';
			y++;
		}
	}
	
	for (int i = 0, x = n, y = n; i < n - 1; i++) {
		if (y > 1 && can(1, 1, x, y - 1)) {
			ans[2 * n - 3 - i] = 'R';
			y--;
		}
		else {
			ans[2 * n - 3 - i] = 'D';
			x--;
		}
	}
	
	printf("! %s\n", ans);
	
	return 0;
}