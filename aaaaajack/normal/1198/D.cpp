#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define Q 998244353
#define N 60
using namespace std;
int dp[N][N][N][N];
char s[N][N];
int cov[N][N];
int solve(int l,int r,int u,int d){
	if(l>r||u>d) return 0;
	if(l==r&&u==d) return cov[l][u];
	if(dp[l][r][u][d]>=0) return dp[l][r][u][d];
	dp[l][r][u][d]=max(r-l+1,d-u+1);
	for(int i=l;i<r;i++){
		dp[l][r][u][d]=min(dp[l][r][u][d],solve(l,i,u,d)+solve(i+1,r,u,d));
	}
	for(int i=u;i<d;i++){
		dp[l][r][u][d]=min(dp[l][r][u][d],solve(l,r,u,i)+solve(l,r,i+1,d));
	}
	return dp[l][r][u][d];
}
int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<n;j++){
			if(s[i][j]=='#') cov[i][j]=1;
		}
	}
	printf("%d\n",solve(0,n-1,0,n-1));
	return 0;
}