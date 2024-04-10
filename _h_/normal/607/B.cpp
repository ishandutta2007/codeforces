#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
const int mxn = 502;
int main(){
	int n,c[mxn],dp[mxn][mxn];
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",c+i);
	rep(i,0,n+1)dp[i][i] =0;
	rep(i,0,n)dp[i][i+1] = 1;
	rep(d,2,n+1)
		rep(i,0,n-d+1){
			int j = i+d;
			if(c[i] == c[j-1]){
				dp[i][j] = dp[i+1][j-1];
			}
			dp[i][j] = 1000;
			rep(x,i+1,j)dp[i][j] = min(dp[i][j], dp[i][x]+dp[x][j]);
			if(c[i] == c[j-1]){
				dp[i][j] = min(dp[i][j],d==2?1:dp[i+1][j-1]);
			}
		}
	printf("%d\n",dp[0][n]);
}