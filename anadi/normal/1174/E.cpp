#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int ans;
int best;

int cnt[N];
int dp[22][N];

int getPower(int a){
	int ret = 0;
	while((1 << ret) <= a)
		++ret;
	return ret;
}

int solve(){
	dp[1][1] = 1;
	for(int i = 2; i <= best; ++i)
		for(int j = i; j <= cnt[i]; ++j){
			dp[i][j] = (1LL * dp[i][j - 1] * (cnt[i] - j + 1))%MX;
			if(j - 1 <= cnt[i - 1])
				dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 1] * (cnt[i] - cnt[i - 1]))%MX;
		}
	
//	printf("%d\n", dp[best][n]);
	return dp[best][n];
}

int main(){
	scanf("%d", &n);
	if(n <= 2){
		puts("1");
		return 0;
	}

	best = getPower(n);
	for(int i = 1; i <= best; ++i)
		cnt[i] = n / (1 << (best - i));
	ans = solve();

	int v = 1 << (best - 1);
	if(v * 3 / 2 <= n){
		for(int i = 1; i < best; ++i){
			int cur = v * 3 / 2;
			for(int j = 1; j <= best; ++j){
				cnt[j] = n / cur;
				if(j != i)	cur /= 2;
				else	cur /= 3;
			}
			
			ans = (ans + solve())%MX;
		}
	}
	
	
	printf("%d\n", ans);
	return 0;
}