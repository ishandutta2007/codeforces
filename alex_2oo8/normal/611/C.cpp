#include<bits/stdc++.h>

using namespace std;

char s[501][502];
int dp[501][501], hor[501][501], ver[501][501];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf(" %s", s[i] + 1);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			hor[i][j] = hor[i][j - 1];
			ver[i][j] = ver[i - 1][j];
			if (s[i][j] == '.' && s[i - 1][j] == '.') {
				dp[i][j]++;
				ver[i][j]++;
			}
			
			if (s[i][j] == '.' && s[i][j - 1] == '.') {
				dp[i][j]++;
				hor[i][j]++;
			}
		}
	
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		printf("%d\n", dp[x2][y2] - dp[x1][y2] - dp[x2][y1] + dp[x1][y1] + ver[x2][y1] - ver[x1][y1] + hor[x1][y2] - hor[x1][y1]);
	}
	
	return 0;
}