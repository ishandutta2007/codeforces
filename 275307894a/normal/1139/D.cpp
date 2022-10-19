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
#define N 100000
#define K 50
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5) 
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int T,n,pr[N+5],ph,Fl[N+5],mu[N+5];ll Ans,ToT,Inv[N+5];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;for(i=2;i<=N;i++){
		!Fl[i]&&(pr[++ph]=i,mu[i]=1);for(j=1;j<=ph&&i*pr[j]<=N;j++){
			Fl[i*pr[j]]=1;if(i%pr[j]==0) break;mu[i*pr[j]]=-mu[i];
		}
	}for(Inv[0]=1,i=1;i<=N;i++) Inv[i]=mpow(i),mu[i]+=mu[i-1];
//	scanf("%d",&T);while(T--){
		scanf("%d",&n);Ans=0;for(i=2;i<=n;i=j+1) j=n/(n/i),ToT=(n/i),Ans+=(mu[j]-mu[i-1])*ToT*Inv[n-ToT];printf("%lld\n",(Ans%mod+1+mod)%mod);
//	}
}