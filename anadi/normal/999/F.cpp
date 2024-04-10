#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int K = 11;
const int N = 507;
const int M = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int cnt[M];
int cnt2[M];

int happy[K];
int dp[N * K][N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n * m; ++i){
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		cnt2[a]++;
	}
	
	for(int i = 1; i <= m; ++i)
		scanf("%d", &happy[i]);
	
	for(int i = 1; i <= n * m; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= m; ++k)
				if(k <= i)
					dp[i][j] = max(dp[i - k][j - 1] + happy[k], dp[i][j]);
	
	int res = 0;
	for(int i = 1; i < M; ++i)
		res += dp[cnt[i]][cnt2[i]];
	printf("%d\n", res);
	return 0;
}