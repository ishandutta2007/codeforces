#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 3000
#define K 35
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,k;ll Ans,ToT1,ToT2,dp[N+5][N+5],Q1[N+5],Q2[N+5],F1[N+5],F2[N+5];
int main(){
	//freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);k=max(n,m);dp[0][0]=1;
	for(i=1;i<=k;i++){
		for(dp[i][0]=j=1;j<=k;j++) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
	} 
	for(i=1;i<m;i++){
//		for(j=1;j<=n;j++) Q1[j]=dp[j][i],Q2[j]=dp[j][m-i];
		for(j=1;j<=n;j++) F1[j]=dp[j][i]*dp[n-j+1][i-1]%mod,F2[j]=(F2[j-1]+dp[j][m-i]*dp[n-j+1][m-i-1])%mod;
		for(j=1;j<=n;j++) Ans=(Ans+F1[j]*F2[n-j]*2)%mod;
	}
	swap(n,m);
	for(i=1;i<m;i++){
//		for(j=1;j<=n;j++) Q1[j]=dp[j][i],Q2[j]=dp[j][m-i];
		for(j=1;j<=n;j++) F1[j]=dp[j][i]*dp[n-j+1][i-1]%mod,F2[j]=(F2[j-1]+dp[j][m-i]*dp[n-j+1][m-i-1])%mod;
		for(j=1;j<=n;j++) Ans=(Ans+F1[j]*F2[n-j]*2)%mod;
	}
	swap(n,m);
	for(i=1;i<n;i++){
		//for(j=1;j<=n;j++) Q1[j]=(Q1[j-1]+dp[j][i-1])%mod,Q2[j]=(Q2[j-1]+dp[j][m-i])%mod;
		//for(j=1;j<=n;j++) F1[j]=Q1[j]*dp[n-j+1][i-1]%mod,F2[j]=(F2[j-1]+Q2[j]*dp[n-j+1][m-i])%mod;
		//for(j=2;j<n;j++) Ans=(Ans+F1[j-1]*F2[n-j]*2)%mod;
		for(j=1;j<m;j++)Ans=(Ans-(dp[j][i]*dp[m-j+1][i-1]%mod)*(dp[j+1][n-i-1]*dp[m-j][n-i]%mod)*2)%mod;
	}
	printf("%lld\n",(Ans+mod)%mod);
}