#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int A[][3] = {{-1, 3, 4}, {3, -1, -1}, {4, -1, -1}};

int n;
int ans = 0;

int main() {
	int x, y, z = -1;
	scanf("%d%d", &n, &x);
	n--, x--;
	while (n--) {
		scanf("%d", &y);
		y--;
		if (A[x][y] == -1) {
			puts("Infinite");
			return 0;
		}
		if (z == 2 && x == 0 && y == 1) {
			ans --;
		}
		ans += A[x][y];
		z = x, x = y;
	}
	puts("Finite");
	printf("%d\n", ans);
	return 0;
}