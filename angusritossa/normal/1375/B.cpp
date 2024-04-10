#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int n, m, grid[310][310];
int am(int i, int j) {
	int ans = 0;
	if (i > 0) ans++;
	if (i < n-1) ans++;
	if (j > 0) ans++;
	if (j < m-1) ans++;
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d%d", &n, &m);
		bool bad = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &grid[i][j]);
				if (grid[i][j] > am(i, j)) bad = 1;
			}
		}
		if (bad) printf("NO\n");
		else {
			printf("YES\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					printf("%d ", am(i, j));
				}
				printf("\n");
			}
		}
	}
}