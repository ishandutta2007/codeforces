#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int T = (1 << 20) + 7;

const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;
const LL bigInf = 1e18 + 9LL;

int n, K;
int tab[N];
int dp[N][50];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	
	for(int i = 1; i <= 30; ++i)
		dp[0][i] = inf;
	dp[0][0] = 0;

	for(int i = 1; i <= n; ++i){
		int cur = tab[i] / 100;
		for(int j = 0; j <= 30; ++j){
			dp[i][j] = inf;
			for(int ii = j + 1; ii <= 30 && ii <= j + cur; ++ii)
				dp[i][j] = min(dp[i][j], dp[i - 1][ii] + cur * 100 - (ii - j) * 100);
			
			if(j >= cur / 10)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - cur / 10] + 100 * cur);
//			if(j <= 6)	printf("%d %d -> %d\n", i, j, dp[i][j]);
		}
	}
	
	int res = inf;
	for(int i = 0; i <= 30; ++i)
		res = min(res, dp[n][i]);
	printf("%d\n", res);
	return 0;
}