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
#define N 1000000
#define M 500000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound 
using namespace std;
int T,n,m,k,x,W[N+5],A[N+5],ToT,F[N+5];ll Ans,Ns;
I void Solve(){
	RI i;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	ToT=0;while(m--) scanf("%d",&x),ToT=(!ToT?x:__gcd(ToT,x));
	for(i=0;i<ToT;i++)F[i]=1e9,W[i]=0;for(i=1;i<=n;i++) F[i%ToT]=min(F[i%ToT],abs(A[i])),W[i%ToT]+=(A[i]<0);Ans=-1e18;
	Ns=0;for(i=1;i<=n;i++) Ns+=abs(A[i]);for(i=0;i<ToT;i++) W[i]--,W[i]&1&&(Ns-=2*F[i]),W[i]++;Ans=max(Ans,Ns);
	Ns=0;for(i=1;i<=n;i++) Ns+=abs(A[i]);for(i=0;i<ToT;i++) W[i]&1&&(Ns-=2*F[i]);Ans=max(Ans,Ns);printf("%lld\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}