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
#define N 300000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,Ns[N+5],X[N+5],Y[N+5],Z[N+5],Ans[N+5];
struct Edge{int x,y,w,id;}S[N+5];I bool cmp(Edge x,Edge y){return x.w<y.w;}
namespace Dsu{
	struct Ques{int id,w,g;}T[N+5],Tp;
	int fa[N+5],H,cnt,un,wn,W[N+5],g[N+5];I int GF(int x){return fa[x]^x?GF(fa[x]):x;}I void BD(){for(RI i=1;i<=n;i++) fa[i]=i,W[i]=g[i]=1;cnt=n;}
	I void Merge(int x,int y){un=GF(x);wn=GF(y);if(un==wn) return;g[un]>g[wn]&&(swap(un,wn),0);T[++H]=(Ques){un,W[wn],g[wn]};W[wn]&&W[un]&&(cnt-=2);W[wn]^=W[un];fa[un]=wn;g[un]==g[wn]&&(g[wn]++);}
	I void Cl(){Tp=T[H--];W[Tp.id]&&Tp.w&&(cnt+=2);W[fa[Tp.id]]=Tp.w;g[fa[Tp.id]]=Tp.g;fa[Tp.id]=Tp.id;}
}
I void Solve(int x=1,int y=m,int l=1,int r=m){
	if(l>r) return;RI M=l+r>>1,Lp=Dsu::H,i;for(i=l;i<=M;i++) Z[i]<=S[x].w&&(Dsu::Merge(X[i],Y[i]),0);Ans[M]=y+1;
	for(i=x;i<=y;i++) {S[i].id<=M&&(Dsu::Merge(S[i].x,S[i].y),0);if(!Dsu::cnt){Ans[M]=i;break;}}while(Lp^Dsu::H) Dsu::Cl();
	for(i=x;i<=Ans[M];i++) S[i].id<l&&(Dsu::Merge(S[i].x,S[i].y),0);Solve(min(Ans[M],y),y,l,M-1);while(Lp^Dsu::H) Dsu::Cl();
	for(i=l;i<=M;i++)Z[i]<=S[x].w&&(Dsu::Merge(X[i],Y[i]),0);Solve(x,min(Ans[M],y),M+1,r);while(Lp^Dsu::H) Dsu::Cl();
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d",&n,&m);Dsu::BD();for(i=1;i<=m;i++) scanf("%d%d%d",&X[i],&Y[i],&Z[i]),S[i]=(Edge){X[i],Y[i],Z[i],i};sort(S+1,S+m+1,cmp);Solve();for(i=1;i<=m;i++) printf("%d\n",Ans[i]>m?-1:S[Ans[i]].w);
}