#include <bits/stdc++.h>

using namespace std;

typedef double LD;
typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define pb push_back
#define PLL pair <LL, LL>
#define pb push_back

const int INF = 1e9 + 9;
const LL MX = 1e9 + 7LL;
const int mxn = 1e5 + 7;

int n;
int dp[mxn][3];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		if(a == 0){
			dp[i][0] = dp[i][1] = INF;
			dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
		}

		if(a == 1){
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = INF;
			dp[i][2] = dp[i - 1][0] + 1;
		}

		if(a == 2){
			dp[i][0] = INF;
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = dp[i - 1][1] + 1;
		}
		
		if(a == 3){
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = INF;
		}
		
	}
	
	printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
	return 0;
}