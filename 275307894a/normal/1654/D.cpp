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
#define N (200000+5)
#define M (200000)
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
struct Edge{int to,x,y;};vector<Edge> S[N];
int x,y,a,b,n,T,F[N],A[N],pr[N],Fl[N],La[N],ph;ll Ans,Inv[N];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
I void dfs(int x,int Ls,int a,int b,ll ToT){
	if(x^1){
		RI p,G=__gcd(a,b);a/=G;b/=G;p=a;while(p^1) A[La[p]]--,F[La[p]]=min(F[La[p]],A[La[p]]),ToT=ToT*Inv[La[p]]%mod,p/=La[p];
		p=b;while(p^1) A[La[p]]++,F[La[p]]=min(F[La[p]],A[La[p]]),ToT=ToT*La[p]%mod,p/=La[p];
	}
	Ans+=ToT;for(Edge i:S[x]) i.to^Ls&&(dfs(i.to,x,i.x,i.y,ToT),0);
	if(x^1){
		RI p,G=__gcd(a,b);a/=G;b/=G;p=a;while(p^1) A[La[p]]++,F[La[p]]=min(F[La[p]],A[La[p]]),ToT=ToT*La[p]%mod,p/=La[p];
		p=b;while(p^1) A[La[p]]--,F[La[p]]=min(F[La[p]],A[La[p]]),ToT=ToT*Inv[La[p]]%mod,p/=La[p];
	}
}
I void Solve(){
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) S[i].clear();for(i=1;i<n;i++) scanf("%d%d%d%d",&x,&y,&a,&b),S[x].PB((Edge){y,a,b}),S[y].PB((Edge){x,b,a});
	for(i=1;i<=n;i++) F[i]=0,A[i]=0;Ans=0;dfs(1,0,0,0,1);Ans%=mod; for(i=1;i<=n;i++) Ans=Ans*mpow(i,-F[i])%mod;printf("%lld\n",Ans);
} 
int main(){
////	freopen("1.in","r",stdin);
	RI i,j;for(i=2;i<=M;i++){
		!Fl[i]&&(pr[++ph]=i,La[i]=i);for(j=1;j<=ph&&i*pr[j]<=M;j++){La[i*pr[j]]=pr[j];Fl[i*pr[j]]=1;if(i%pr[j]==0) break;}
	}for(Inv[0]=i=1;i<=M;i++)Inv[i]=mpow(i);
	scanf("%d",&T);while(T--) Solve();
}