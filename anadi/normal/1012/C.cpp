#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int h[N];
int dp[N][N][3];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	
	dp[0][0][0] = MX;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 3; ++j)
			dp[0][i][j] = MX;

	for(int i = 1; i <= n; ++i){
		dp[i][0][0] = MX;
		dp[i][0][1] = 0;
		dp[i][0][2] = h[i - 1] <= h[i] ? h[i] - h[i - 1] + 1 : MX;

		int to = (i + 1) / 2;
		for(int j = 1; j <= to; ++j){
			if(h[i - 1] < h[i])
				dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
			else if(h[i - 2] <= h[i])
				dp[i][j][0] = min(dp[i - 1][j - 1][1] + h[i - 1] - h[i] + 1, dp[i - 1][j - 1][2]);
			else
				dp[i][j][0] = min(dp[i - 1][j - 1][1] + h[i - 1] - h[i] + 1, dp[i - 1][j - 1][2] + h[i - 2] - h[i]);

			dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][2]);
			if(h[i - 1] > h[i])
				dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0]);
			
			if(h[i - 1] <= h[i])
				dp[i][j][2] = dp[i - 1][j][0] + h[i] - h[i - 1] + 1;
			else
				dp[i][j][2] = MX;
		}
		
		for(int j = to + 1; j <= n; ++j)
			for(int t = 0; t < 3; ++t)
				dp[i][j][t] = MX;
	}
	
	int to = (n + 1) / 2;
	for(int i = 1; i <= to; ++i)
		printf("%d ", min(dp[n][i][0], min(dp[n][i][1], dp[n][i][2])));
	return 0;
}