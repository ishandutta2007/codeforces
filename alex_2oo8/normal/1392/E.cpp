#include <bits/stdc++.h>

using namespace std;

const int MX = 25;

long long a[MX][MX], mn[MX][MX], mx[MX][MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j + 1 < n; j++) {
			a[i][j + 1] = mx[i + 1][j] - mn[i + 1][j + 1] + 1;
			mn[i][j + 1] = a[i][j + 1] + mn[i + 1][j + 1];
		}
		
		mx[i][n - 1] = a[i][n - 1] + mx[i + 1][n - 1];
		for (int j = n - 2; j >= 0; j--) {
			mx[i][j] = a[i][j] + mx[i][j + 1];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%lld ", a[i][j]);
		printf("\n");
	}
	
	fflush(stdout);
	
	int q;
	ignore = scanf("%d", &q);
	while (q--) {
		long long k;
		ignore = scanf("%lld", &k);
		printf("%d %d\n", 1, 1);
		int x = 0, y = 0;
		while (x != n - 1 || y != n - 1) {
			if (x + 1 < n && mn[x + 1][y] <= k && k <= mx[x + 1][y]) {
				x++;
			}
			else {
				y++;
			}
			
			k -= a[x][y];
			printf("%d %d\n", x + 1, y + 1);
		}
		
		fflush(stdout);
	}
	
	return 0;
}