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
#define N 1000
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
int n,m,k,Ne,La;ll ToT,frc[N+5],Inv[N+5],F[N+5],G[N+5],dp[2][N+5][2][2];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&k);for(frc[0]=Inv[0]=1,i=1;i<=n;i++) frc[i]=frc[i-1]*i%mod,Inv[i]=Inv[i-1]*mpow(i)%mod;
	dp[0][0][1][0]=1;for(i=1;i<=n;i++){
		Ne=i&1;La=Ne^1;Me(dp[Ne],0);for(j=0;j<=i;j++){
			dp[Ne][j][0][0]=dp[La][j][0][0]+dp[La][j][1][0];dp[Ne][j][1][0]=dp[La][j][0][1]+dp[La][j][1][1];
			if(j) dp[Ne][j][0][0]+=dp[La][j-1][0][0],dp[Ne][j][1][0]+=dp[La][j-1][0][1],dp[Ne][j][0][1]=dp[La][j-1][0][0]+dp[La][j-1][1][0],dp[Ne][j][1][1]=dp[La][j-1][0][1]+dp[La][j-1][1][1];
			dp[Ne][j][0][0]%=mod;dp[Ne][j][0][1]%=mod;dp[Ne][j][1][0]%=mod;dp[Ne][j][1][1]%=mod;
		}
	}for(i=0;i<=n;i++)F[i]=(dp[n&1][i][0][0]+dp[n&1][i][1][0])*frc[n-i]%mod;
	for(i=k;i<=n;i++)ToT+=((i-k)&1?mod-F[i]:F[i])*frc[i]%mod*Inv[k]%mod*Inv[i-k]%mod;printf("%lld\n",ToT%mod);
}