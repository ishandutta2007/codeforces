#include<bits/stdc++.h>

using namespace std;

char s[200000];
int dp[200000][2][4];

int main() {
	int n;
	scanf("%d %s", &n, s);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 3; k++) {
				dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
				dp[i + 1][s[i] - '0'][k + (s[i] - '0' == j)] = max(dp[i + 1][s[i] - '0'][k + (s[i] - '0' == j)], dp[i][j][k] + 1);
			}
	
	printf("%d\n", max(dp[n][0][2], dp[n][1][2]));
	
	return 0;
}