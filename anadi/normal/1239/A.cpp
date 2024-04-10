#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int dp[N];

int main(){
	dp[1] = 2, dp[2] = 4;
	for(int i = 3; i < N; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MX;
	
	scanf("%d %d", &n, &m);
	printf("%d\n", (((dp[n] + dp[m] - 2) % MX) + MX) % MX);
	return 0;
}