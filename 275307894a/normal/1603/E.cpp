#include<bits/stdc++.h>
#include<cstdio>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N (200+5)
#define M (N*50+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k,p,A[N+5],Cnt,P,Ne,La,vis[22][N][N];ll dp[22][N][N],frc[N],Inv[N],Ans;
I ll mpow(ll x,int y=p-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%p),y>>=1,x=x*x%p;return Ans;}
I ll dfs(int x,int S,int w){
	if(vis[x][S][w]) return dp[x][S][w];ll &Ns=dp[x][S][w];vis[x][S][w]=1;Ns=0;
	if(x<m&&x>w)return 0;if(x==m){if(w^n) Ns=Inv[n-w];return Ns;}
	for(RI i=0;i+w<=n&&S+i*(m-x)<=n-m+1;i++) Ns=(Ns+dfs(x+1,S+i*(m-x),w+i)*Inv[i])%p;return Ns;
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d",&n,&p);for(frc[0]=Inv[0]=i=1;i<=n;i++) frc[i]=frc[i-1]*i%p,Inv[i]=mpow(frc[i]);
	for(i=max(n-20,1);i<=n+1;i++)Me(vis,0),m=n-i+1,Ans+=dfs(0,0,0);printf("%lld\n",Ans%p*frc[n]%p);
}