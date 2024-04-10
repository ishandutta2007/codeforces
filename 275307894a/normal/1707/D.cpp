#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (2000+5)
#define M (8000+5)
#define K (1500+5)
#define mod 1004535809
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;vector<int> S[N];
int n,p,x,y;ll dp[N][N],Q[N][N],Ps[N][N],frc[N],Inv[N],G[N],Ts[N],F[N],Ct[N];
I ll mpow(ll x,int y=p-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%p),y>>=1,x=x*x%p;return Ans;}
I void EG(ll x,ll p,ll &a,ll &b){if(!p){a=1;b=0;return;}EG(p,x%p,b,a);b-=x/p*a;}
I ll GI(int x){ll a,b;EG(x,p,a,b);return (a%p+p)%p;}
I void Make(int x,int La){
	int i,j;for(int i:S[x]) i^La&&(Make(i,x),0);G[0]=1;for(i=1;i<=n;i++) {G[i]=1;Ct[i]=0;for(int j:S[x]) j^La&&(Q[j][i]?(G[i]=G[i]*Q[j][i]%p):(Ct[i]++));}
	for(i=1;i<=n;i++)dp[x][i]=(Ct[i]?0:G[i]);if(x^1){for(int i:S[x]){for(j=1;j<=n;j++) Q[i][j]?(G[j]=G[j]*GI(Q[i][j])%p):(Ct[j]--),F[j]=(F[j-1]+(Ct[j]?0:G[j]))%p,dp[x][j]=(dp[x][j]+F[j-1]*dp[i][j])%p,Q[i][j]?(G[j]=G[j]*Q[i][j]%p):(Ct[j]++);}}
	for(i=1;i<=n;i++) Q[x][i]=(Q[x][i-1]+dp[x][i])%p;
}
I ll C(int x,int y){return frc[x]*Inv[y]%p*Inv[x-y]%p;}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&p);for(i=1;i<n;i++) scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);for(frc[0]=Inv[0]=i=1;i<=n;i++) frc[i]=frc[i-1]*i%p,Inv[i]=mpow(frc[i]);
	Make(1,0);for(i=1;i<n;i++){Ts[i]=dp[1][i];for(j=1;j<i;j++) Ts[i]=(Ts[i]+(p-Ts[j])*C(i,j))%p;printf("%lld ",Ts[i]);}
}