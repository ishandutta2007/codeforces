#include <bits/stdc++.h>

using namespace std;

const int MX = 21, md = 31607;

int p[MX][MX], q[MX][MX], col[MX], cc[MX][MX], n, ans = 1;

void brute(int k, int prob, int cnt) {
	if (k == n) {
		int sum = 1;
		for (int i = 0; i < n; i++) {
			sum = sum * (1 - col[i] + md) % md;
		}
		
		if (cnt % 2 == 0) {
			prob = md - prob;
		}
		
		ans = (ans + prob * sum) % md;
		
		return;
	}
	
	int probHere = 1;
	for (int i = 0; i < n; i++) {
		probHere = probHere * q[k][i] % md;
	}
	
	brute(k + 1, prob * probHere % md, cnt + 1);
	
	for (int i = 0; i < n; i++) {
		cc[k][i] = col[i];
		col[i] = col[i] * q[k][i] % md;
	}
	
	brute(k + 1, prob, cnt);
	
	for (int i = 0; i < n; i++) col[i] = cc[k][i];
}

int main() {
	int inv1e4 = 0;
	while (inv1e4 * 10000 % md != 1) inv1e4++;
	
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0, x; j < n; j++) {
			ignore = scanf("%d", &x);
			
			p[i][j] = x * inv1e4 % md;
		}
	
	fill(col, col + n, 1);
	
	for (int d1 = 0; d1 < 2; d1++)
		for (int d2 = 0; d2 < 2; d2++) {
			int prob = 1;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					q[i][j] = p[i][j];
					
					if (i == j && d1 == 1) {
						prob = prob * q[i][j] % md;
						q[i][j] = 1;
					}
					
					if (i == n - 1 - j && d2 == 1) {
						prob = prob * q[i][j] % md;
						q[i][j] = 1;
					}
				}
			
			brute(0, prob, d1 + d2);
		}
	
	printf("%d\n", ans);
	
	return 0;
}