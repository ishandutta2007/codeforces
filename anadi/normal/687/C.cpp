#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define pb push_back
#define LOGN 20

const int INF = 1e9 + 9;
const LL MX = 1e9 + 7;
const int mxn = 509;

int n, k;
bool dp[mxn][mxn][mxn];

int main(){
	scanf("%d %d", &n, &k);
	
	dp[0][0][0] = true;
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		
		for(int j = 0; j <= k; ++j)
			for(int l = 0; l <= j; ++l)
				if(dp[i - 1][j][l] || (j >= a && dp[i - 1][j - a][l]) || (l >= a && dp[i - 1][j - a][l - a]))
					dp[i][j][l] = true;
	}
	
	int res = 0;
	for(int i = 0; i <= k; ++i)
		if(dp[n][k][i])
			++res;
	printf("%d\n", res);
	for(int i = 0; i <= k; ++i)
		if(dp[n][k][i])
			printf("%d ", i);
	return 0;
}