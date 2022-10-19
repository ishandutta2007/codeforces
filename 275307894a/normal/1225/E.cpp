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
#define N 2000
#define K 1000
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,Q[2][N+5][N+5],Id[2][N+5][N+5];char c[N+5][N+5];ll dp[2][N+5][N+5],G[2][N+5][N+5];
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);if(n==1&&m==1){Pc(49);return 0;}for(i=1;i<=n;i++) scanf("%s",c[i]+1);
	for(i=1;i<=n;i++) for(j=m;j;j--)Q[0][i][j]=Q[0][i][j+1]+(c[i][j]=='R');for(i=n;i;i--) for(j=1;j<=m;j++) Q[1][i][j]=Q[1][i+1][j]+(c[i][j]=='R');
	for(i=1;i<=n;i++) for(Id[0][i][1]=1,j=2;j<=m;j++) {Id[0][i][j]=Id[0][i][j-1];while(Q[0][i][Id[0][i][j]+1]>m-j)Id[0][i][j]++;}
	for(j=1;j<=m;j++) for(Id[1][1][j]=1,i=2;i<=n;i++) {Id[1][i][j]=Id[1][i-1][j];while(Q[1][Id[1][i][j]+1][j]>n-i)Id[1][i][j]++;}
	dp[0][1][1]=dp[1][1][1]=G[0][1][1]=G[1][1][1]=1;for(i=1;i<=n;i++){
		for(j=1+(i==1);j<=m;j++) dp[0][i][j]=(G[1][i][j-1]-G[1][i][Id[0][i][j]-1])%mod,dp[1][i][j]=(G[0][i-1][j]-G[0][Id[1][i][j]-1][j])%mod,G[0][i][j]=G[0][i-1][j]+dp[0][i][j],G[1][i][j]=G[1][i][j-1]+dp[1][i][j]; 
	}printf("%lld\n",(dp[0][n][m]+dp[1][n][m])%mod);
}