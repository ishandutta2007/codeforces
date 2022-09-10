#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int cnt[N];
int dp[N][3][3];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	
	for(int i = 0; i <= m; ++i)
		for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 3; ++k)
				dp[i][j][k] = -MX;
	dp[0][0][0] = 0;

	for(int i = 1; i <= m; ++i)
		for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 3; ++k)
				for(int l = 0; l < 3; ++l){
					if(j + k + l > cnt[i])
						continue;
					
					dp[i][k][l] = max(dp[i][k][l], dp[i - 1][j][k] + j + (cnt[i] - j - k - l) / 3);
//					printf("%d %d %d -> %d\n", i, k, l, dp[i][k][l]);
				}

	printf("%d\n", dp[m][0][0]);
	return 0;
}