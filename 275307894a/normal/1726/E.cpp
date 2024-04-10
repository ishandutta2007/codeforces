#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=6e5+5,M=(1<<18)+5,K=1e5+5,mod=998244353,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;
int n,m,k,x,y,z;ll Ans,f[N],g[N],frc[N],Inv[N];
ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
ll C(int x,int y){return frc[x]*Inv[y]%mod*Inv[x-y]%mod;}
void Solve(){
	int i;scanf("%d",&n);for(frc[0]=f[0]=Inv[0]=i=1;i<=n;i++) f[i]=f[i-1]*(i*4-2)%mod,frc[i]=frc[i-1]*i%mod,Inv[i]=mpow(frc[i]);
	g[0]=1;for(i=1;i<=n;i++) g[i]=(g[i-1]+(i>1?g[i-2]*(i-1):0))%mod;
	Ans=0;for(i=0;i<=n;i+=4)Ans+=g[n-i]*f[i/4]%mod*C(n-i/2,i/2)%mod;printf("%lld\n",Ans%mod);
}
int main(){
//	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}