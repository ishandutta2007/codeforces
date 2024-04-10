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
#define N (1000000+5)
#define M (N*200)+5
#define mod 1000000007
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
int n,m,k,T;ll Ans,frc[N+5],Inv[N+5];const int Inv2=(mod+1)/2;
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
I ll C(int x,int y){return frc[x]*Inv[y]%mod*Inv[x-y]%mod;}
I void Solve(){
	RI i,j;scanf("%d%d%d",&n,&m,&k);for(frc[0]=Inv[0]=i=1;i<=n;i++)frc[i]=frc[i-1]*i%mod,Inv[i]=mpow(frc[i]);if(n==m){printf("%lld\n",1ll*n*k%mod);return;}
	Ans=0;for(i=1;i<=min(m,n-1);i++) Ans+=C(n-i-1,m-i)*k%mod*i%mod*mpow(Inv2,n-i)%mod;printf("%lld\n",Ans%mod);
}
int main(){
//freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--) Solve();
}