#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

char s[MX + 1];
int a[MX], dp[MX + 1][2][2];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d %s", &n, s);
		
		for (int i = 0; i < n; i++) a[i] = s[i] == 'L' ? 0 : 1;
		
		int ans = n;
		for (int msk = 0; msk < 4; msk++) {
			int a0 = msk % 2;
			int a1 = msk / 2;
			
			int add = 0;
			if (a[0] != a0) add++;
			if (a[1] != a1) add++;
			
			for (int i = 0; i <= n; i++)
				for (int j = 0; j < 2; j++)
					for (int k = 0; k < 2; k++)
						dp[i][j][k] = n;
			
			dp[2][a1][a1 == a0 ? 1 : 0] = add;
			for (int i = 2; i < n; i++)
				for (int x = 0; x < 2; x++)
					for (int t = 0; t < 2; t++)
						for (int y = 0; y < 2; y++) {
							if (x == y && t == 1) continue;
							
							int& val = dp[i + 1][y][x == y ? t + 1 : 0];
							val = min(val, dp[i][x][t] + (a[i] == y ? 0 : 1));
						}
			
			for (int x = 0; x < 2; x++)
				for (int t = 0; t < 2; t++) {
					int c = t + 1;
					if (a0 == x) {
						c++;
						if (a1 == x) c++;
					}
					
					if (c >= 3) continue;
					
					ans = min(dp[n][x][t], ans);
				}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}