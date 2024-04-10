#include <bits/stdc++.h>

using namespace std;

const int MX = 50000;

int a[MX][5];

int cmp(int x, int y) {
	int z = 0;
	for (int i = 0; i < 5; i++) {
		if (a[x][i] < a[y][i]) z++;
	}
	
	return z >= 3 ? x : y;
}

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 5; j++)
				ignore = scanf("%d", a[i] + j);
		
		int x = 0;
		for (int i = 1; i < n; i++) {
			x = cmp(i, x);
		}
		
		for (int i = 0; i < n; i++) {
			if (cmp(i, x) != x) {
				x = -2;
				break;
			}
		}
		
		printf("%d\n", x + 1);
	}
	
	return 0;
}