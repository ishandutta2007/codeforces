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
#define N 20000000
#define M 10
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
int n,x,F[N+5],Maxn,Fl[N+5],ph,pr[N+5];ll dp[N+5],Ans;
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&x),Maxn=max(Maxn,x),F[x]++;
	for(i=2;i<=Maxn;i++){
		!Fl[i]&&(pr[++ph]=i);for(j=1;j<=ph&&i*pr[j]<=Maxn;j++){Fl[i*pr[j]]=1;if(i%pr[j]==0) break;}
	}
	for(j=1;j<=ph;j++)for(i=Maxn/pr[j];i;i--) F[i]+=F[i*pr[j]]; 
	for(i=Maxn;i;i--) for(dp[i]=1ll*F[i]*i,j=1;j<=ph&&i*pr[j]<=Maxn;j++) dp[i]=max(dp[i],dp[i*pr[j]]+1ll*(F[i]-F[i*pr[j]])*i);printf("%lld\n",dp[1]);
}