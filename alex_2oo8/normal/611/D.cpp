#include<bits/stdc++.h>

using namespace std;

const int md = 1000000007;

void add(int &x, int y) {
	x += y;
	if (x >= md) x -= md;
}

char s[5001];
int dp[5000][5000], first[5001][5001], sum[5000];

int main() {
	int n;
	scanf("%d %s", &n, s);
	
	for (int i = 0; i <= n; i++) first[i][n] = first[n][i] = n;
	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
			if (s[i] == s[j]) first[i][j] = first[i + 1][j + 1] + 1;
			else first[i][j] = 0;
	
	for (int len = 0; len < n; len++) {
		dp[0][len] = 1;
		add(sum[len], 1);
		
		for (int i = 1; i + len < n; i++) {
			if (s[i] == '0') continue;
			
			dp[i][i + len] = sum[i - 1];
			
			if (i - 1 - len >= 0) {
				int f = first[i - 1 - len][i];
				if (f > len || s[i - 1 - len + f] > s[i + f]) add(dp[i][i + len], md - dp[i - 1 - len][i - 1]);
			}
			
			add(sum[i + len], dp[i][i + len]);
		}
	}
	
	printf("%d\n", sum[n - 1]);
	
	return 0;
}