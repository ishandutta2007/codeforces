#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5007;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int dp[N][2];
int help[N][2];

int main(){
	scanf("%d", &n);
	
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		char c;
		scanf(" %c", &c);
		
		int suf = 0;
		for(int j = i; j >= 0; --j){
			suf = (suf + dp[j][1])%MX;
			if(c == 'f' && j > 0)
				help[j][0] = ((dp[j - 1][0] + dp[j - 1][1])%MX + suf)%MX;
			
			if(c == 's')
				help[j][1] = (dp[j][0] + suf)%MX;
		}
		
		for(int j = 0; j <= i; ++j){
			dp[j][0] = help[j][0];
			dp[j][1] = help[j][1];
			help[j][0] = help[j][1] = 0;
//			printf("%d %d -> %d %d\n", i, j, dp[j][0], dp[j][1]);
		}
	}
	
	int res = 0;
	for(int i = 0; i <= n; ++i)
		res = (res + dp[i][1])%MX;
	printf("%d\n", res);
	return 0;
}