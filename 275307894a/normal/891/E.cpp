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
#define N 5000
#define M N*N+5
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound 
using namespace std;
int n,m,k,A[N+5];ll Ans=1,Ns,frc[N+5],Inv[N+5],B[N+5];
#define Bmod(x,y) ((x+=y)>=mod&&(x-=mod))
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
int main(){
//	freopen("calculate.in","r",stdin);freopen("calculate.out","w",stdout);
	RI i,j;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]),Ans=Ans*A[i]%mod;B[0]=1;for(i=1;i<=n;i++) for(j=i;~j;j--) B[j]=(A[i]*B[j]-(j?B[j-1]:0)+mod)%mod;
	for(i=0;i<=min(n,k);i++) {Ns=1;for(j=0;j<i;j++) Ns=Ns*(k-j)%mod;Ans-=B[i]*Ns%mod*mpow(mpow(n),i)%mod;}printf("%lld\n",(Ans%mod+mod)%mod); 
}