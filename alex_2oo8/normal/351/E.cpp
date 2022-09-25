#include <bits/stdc++.h>

using namespace std;

const int MX = 2000, MXA = 100000;

int p[MX], pos[MX], neg[MX], dp[MX + 1][MX + 1];
vector<int> f[MXA + 1];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
		if (p[i] < 0) p[i] *= -1;
		
		f[p[i]].push_back(i);
	}
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (p[i] < p[j]) neg[j]++;
			else if (p[i] > p[j]) pos[i]++;
	
	int ans = 0;
	for (int x = 0; x <= MXA; x++) {
		int m = f[x].size();
		for (int i = 1; i <= m; i++)
			for (int j = 0; j <= i; j++)
				dp[i][j] = 1e9;
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j <= i; j++) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + pos[f[x][i]]);
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + i - j + neg[f[x][i]]);
			}
		
		int mn = 1e9;
		for (int i = 0; i <= m; i++) mn = min(dp[m][i], mn);
		
		ans += mn;
	}
	
	printf("%d\n", ans);
	
	return 0;
}