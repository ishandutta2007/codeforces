#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int dp[N][N];
int val[N][N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i][i]);
	
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j + i <= n + 1; ++j)
			val[j][i + j - 1] = val[j + 1][i + j - 1] ^ val[j][i + j - 2];
	
	for(int i = 0; i < n; ++i)
		for(int j = 1; j + i <= n; ++j)
			dp[j][j + i] = max(max(dp[j + 1][j + i], dp[j][j + i - 1]), val[j][i + j]);
	
	int q;
	scanf("%d", &q);
	
	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", dp[l][r]);
	}

	return 0;
}