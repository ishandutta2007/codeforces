#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define max(a,b) (a)>(b)?a:b
#define min(a,b) (a)<(b)?a:b
const int maxn = 510, mod = int(1e9)+7;
int n,m;
char cc[maxn][maxn];
unsigned int dp[maxn][maxn][2] = {};

int ans(int x1, int y1, int x2, int y2){
	if(x1 > x2
		|| y1 > y2
		|| cc[y1][x1] != cc[y2][x2]
		)
		return 0;
	if(x2+y2-x1-y1 <= 1)
		return 1;
	if(dp[x1][y1][x2] != -1)
		return dp[x1][y1][x2];
	return dp[x1][y1][x2] =
		  (ans(x1,y1+1,x2,y2-1)
		 + ans(x1,y1+1,x2-1,y2)
		 + ans(x1+1,y1,x2,y2-1)
		 + ans(x1+1,y1,x2-1,y2))%mod;
}

int main(){
	unsigned int ans = 0;
	scanf("%d%d",&n,&m);
	rep(i,0,n)
		scanf(" %s ",cc[i]);
	dp[0][m-1][0] = cc[0][0] == cc[n-1][m-1];
	if(m+n <= 3){
		printf("%d\n", dp[0][m-1][0]);
		return 0;
	}
	rep(i,1,(m+n)/2){
		int b = i&1;
		rep(j,0,maxn)
			rep(k,0,maxn)
				dp[j][k][b] = 0;
		rep(j,0,i)
			rep(k,j,m){
				if(k > j){
					dp[j+1][k][b] += dp[j][k][!b];
					dp[j+1][k-1][b] += dp[j][k][!b];
					dp[j][k-1][b] += dp[j][k][!b];
				}
				dp[j][k][b] += dp[j][k][!b];
			}
		rep(j,0,i+1)
			rep(k,max(j,m-i-1),min(m,m-i-1+n))
				if(cc[i-j][j] != cc[m+n-2-i-k][k])
					dp[j][k][b] = 0;
				else
					dp[j][k][b] %= mod;

		if(i == (m+n)/2-1)
			rep(j,0,i+1)
				ans += dp[j][j][b],
				ans += (m+n)&1 ? dp[j][j+1][b] : 0,
				ans %= mod;
	}
	printf("%d\n",ans);
}