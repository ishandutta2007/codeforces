#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 998244353;
const LL INF = 1e18 + 9LL;

int n;
int dp[N][205][2];

void add(int &a, int b){
	a += b;
	if(a >= MX)
		a -= MX;
}

int main(){
	scanf("%d", &n); 
	dp[0][0][0] = 1;
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		
		if(a != -1){
			for(int j = 0; j < a; ++j){
				add(dp[i][a][0], dp[i - 1][j][0]);
				add(dp[i][a][0], dp[i - 1][j][1]);
			}
			
			add(dp[i][a][1], dp[i - 1][a][0]);
			add(dp[i][a][1], dp[i - 1][a][1]);

			for(int j = a + 1; j <= 200; ++j)
				add(dp[i][a][1], dp[i - 1][j][1]);
		}
		else{
			int sum = dp[i - 1][0][0];
			for(int j = 1; j <= 200; ++j){
				add(dp[i][j][0], sum);
				add(sum, dp[i - 1][j][0]);
				add(sum, dp[i - 1][j][1]);
			}
			
			sum = 0;
			for(int j = 200; j >= 1; --j){
				add(sum, dp[i - 1][j][1]);
				add(dp[i][j][1], sum);
				add(dp[i][j][1], dp[i - 1][j][0]);
			}
		}
	}
	
	int sum = 0;
	for(int i = 1; i <= 200; ++i)
		add(sum, dp[n][i][1]);
	printf("%d\n", sum);
	return 0;
}