#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
LL d[N];
LL val[N];
LL dp[N][2];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%I64d", &val[i]);
	
	for(int i = 1; i < n; ++i)
		d[i] = val[i + 1] - val[i];
	
	for(int i = 1; i < n; ++i){
		if(d[i] < 0){
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + abs(d[i]));
		}
		else{
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + abs(d[i]));
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
		}
	}
	
	printf("%I64d\n", max(dp[n - 1][0], dp[n - 1][1]));
	return 0;
}