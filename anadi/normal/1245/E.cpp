#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 11;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n = 10;
int h[N][N];
double dp[N][N];

int nx(int x, int y, int m){
	if(x % 2 == 0)
		y += m;
	else
		y -= m;

	if(y > 10 || y < 1)
		return x - 1;
	return x;
}

int ny(int x, int y, int m){
	if(x % 2 == 0){
		y += m;
		if(y > 10)
			y = 11 - y % 10;
		return y;
	}
	
	y -= m;
	if(y < 1)
		y = 1 - y;
	return y;
}

int main(){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &h[i][j]);
	
	dp[1][1] = 0;
	dp[1][2] = 6;
	dp[1][3] = 6;
	dp[1][4] = 6;
	dp[1][5] = 6;
	dp[1][6] = 6;
	
	for(int i = 7; i <= 10; ++i){
		for(int j = 1; j <= 6; ++j)
			dp[1][i] += dp[1][i - j];
		
		dp[1][i] /= 6;
		dp[1][i] += 1.0;
	}
	
	for(int i = 2; i <= 10; ++i){
		if(i % 2 == 1){
			for(int j = 1; j <= 10; ++j){
				for(int t = 1; t <= 6; ++t){
					int x = nx(i, j, t);
					int y = ny(i, j, t);
					
					double cand = dp[x][y];
					if(h[x][y] != 0)
						cand = min(cand, dp[x - h[x][y]][y]);

					cand += 1.0;
					dp[i][j] += cand;
				}
				
				dp[i][j] /= 6.0;
			}
		}
		else{
			for(int j = 10; j >= 1; --j){
				for(int t = 1; t <= 6; ++t){
					int x = nx(i, j, t);
					int y = ny(i, j, t);
					
					double cand = dp[x][y];
					if(h[x][y] != 0)
						cand = min(cand, dp[x - h[x][y]][y]);

					cand += 1.0;
					dp[i][j] += cand;
				}
				
				dp[i][j] /= 6.0;
			}			
		}
	}
	
	printf("%.10lf\n", dp[n][1]);
	return 0;
}