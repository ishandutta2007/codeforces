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
#define N 200000
#define M 1000000
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
int n,m,k,x,y,Maxn,A[N+5],Fl[M+5],pr[M+5],ph,Las[M+5];ll frc[M+5],Inv[M+5],ToT=1,Q[N+5],Ans[N+5];vector<int> Id[N+5];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
namespace Tree{
	ll F[N+5];I void BD(){for(RI i=0;i<=n;i++) F[i]=1;}I void Ins(int x,ll w){while(x<=n) F[x]=F[x]*w%mod,x+=x&-x;}I ll Qry(int x){ll Ans=1;while(x) Ans=Ans*F[x]%mod,x-=x&-x;return Ans;}
}
struct Ques{int Y,w;}now;vector<Ques> S[N+5],G[N+5];
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d",&n);Tree::BD();for(Q[0]=i=1;i<=n;i++) scanf("%d",&A[i]),Maxn=max(Maxn,A[i]),Q[i]=Q[i-1]*A[i]%mod;for(frc[0]=i=1;i<=Maxn;i++) frc[i]=frc[i-1]*i%mod;Inv[Maxn]=mpow(frc[Maxn]);
	for(i=Maxn-1;~i;i--) Inv[i]=Inv[i+1]*(i+1)%mod;for(i=1;i<=Maxn;i++) Inv[i]=Inv[i]*frc[i-1]%mod;
	for(i=2;i<=Maxn;i++){
		!Fl[i]&&(pr[++ph]=i,Las[i]=ph);for(j=1;j<=ph&&i*pr[j]<=Maxn;j++){Fl[i*pr[j]]=1;Las[i*pr[j]]=j;if(i%pr[j]==0) continue;}
	}for(i=1;i<=ph;i++) Id[i].push_back(0);for(i=1;i<=n;i++) {
		x=A[i];while(x^1){y=Las[x];while(x%pr[y]==0) x/=pr[y];Id[y].push_back(i);}
	}for(i=1;i<=ph;i++) Id[i].push_back(n+1),ToT=ToT*(pr[i]-1)%mod*Inv[pr[i]]%mod;scanf("%d",&m);for(i=1;i<=m;i++) scanf("%d%d",&x,&y),G[x].push_back((Ques){y,i}),Ans[i]=Q[y]*mpow(Q[x-1])%mod*ToT%mod;
	for(i=1;i<=ph;i++) for(j=1;j<Id[i].size();j++) Id[i][j]>Id[i][j-1]+1&&(S[Id[i][j-1]+1].push_back((Ques){Id[i][j]-1,pr[i]}),0);
	for(i=1;i<=n;i++) {
		for(j=0;j<S[i].size();j++) Tree::Ins(i,S[i][j].w*Inv[S[i][j].w-1]%mod),Tree::Ins(S[i][j].Y+1,(S[i][j].w-1)*Inv[S[i][j].w]%mod)/*,printf("I %d %lld\n",i,S[i][j].w*Inv[S[i][j].w-1]%mod)*/;
		for(j=0;j<G[i].size();j++) Ans[G[i][j].w]=Ans[G[i][j].w]*Tree::Qry(G[i][j].Y)%mod/*,printf("Q %d %lld\n",G[i][j].Y,Tree::Qry(G[i][j].Y))*/;
	}for(i=1;i<=m;i++) printf("%lld\n",Ans[i]);
}