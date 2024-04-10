#include<bits/stdc++.h>

using namespace std;

const int MX = 500;

int c[MX], dp[MX][MX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", c + i);
	
	for (int len = 0; len < n; len++)
		for (int i = 0; i + len < n; i++) {
			int j = i + len;
			dp[i][j] = MX;
			int l = i, r = j;
			while (l < r && c[l] == c[r]) {
				l++;
				r--;
				
				if (l < r) dp[i][j] = min(dp[i][j], dp[l][r]);
			}
			
			if (l >= r) dp[i][j] = 1;
			
			for (int k = i; k < i + len; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	
	printf("%d\n", dp[0][n - 1]);
	
	return 0;
}