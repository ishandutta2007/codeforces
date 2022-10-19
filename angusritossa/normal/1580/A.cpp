#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int n, m, grid[450][450], t, pre[450][450], best[450];
int num1sInRange(int a, int b, int c, int d) {
	return pre[c][d] - pre[c][b-1] - pre[a-1][d] + pre[a-1][b-1];
}
int num0sInRange(int a, int b, int c, int d) {
	return (d-b+1)*(c-a+1) - num1sInRange(a, b, c, d);
}
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char a;
				scanf(" %c", &a);
				grid[i][j] = a == '1';
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				pre[i][j] = grid[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			}
		}
		int ans = 1e9;
		for (int left = m; left >= 1; left--) {
			fill_n(best, m+1, 1e9);
			for (int i = 1; i <= n; i++) {
				for (int j = left+3; j <= m; j++) {
					int add = -num0sInRange(i, j, n, j)-num0sInRange(i, left, n, left)-num1sInRange(i, left+1, n, j-1)+num0sInRange(i, left+1, i, j-1);
					ans = min(ans, add+best[j]);
					if (i >= 4) {
						int a = i-3;
						int val = num0sInRange(a+1, j, n, j)+num0sInRange(a+1, left, n, left)+num1sInRange(a+1, left+1, n, j-1)+num0sInRange(a, left+1, a, j-1);
						best[j] = min(best[j], val);
					}
				}
			}
		}
		printf("%d\n", ans);
	}

}