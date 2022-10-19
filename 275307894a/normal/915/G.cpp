#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (4000000+5)
#define M ((1<<20)+5)
#define K (200000+5)
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
int n,m,k,ph,pr[N],Fl[N],mu[N];ll P[N],F[N],Ans;
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&k);mu[1]=P[1]=1;for(i=2;i<=k;i++) {
		!Fl[i]&&(pr[++ph]=i,P[i]=mpow(i,n),mu[i]=-1);for(j=1;j<=ph&&i*pr[j]<=k;j++){Fl[i*pr[j]]=1;P[i*pr[j]]=P[i]*P[pr[j]]%mod;if(i%pr[j]==0) break;mu[i*pr[j]]=-mu[i];}
	}for(i=1;i<=k;i++) {for(j=1;i*j<=k;j++) F[i*j]=(F[i*j]+mu[i]*P[j])%mod,F[i*j+i]=(F[i*j+i]-mu[i]*P[j])%mod;}
	for(i=1;i<=k;i++) {F[i]+=F[i-1];F[i]=(F[i]%mod+mod)%mod;Ans+=F[i]^i;}printf("%lld\n",Ans%mod);
}