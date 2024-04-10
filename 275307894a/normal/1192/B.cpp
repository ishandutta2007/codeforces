#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M (1000000+5)
#define K (20+5)
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
using namespace std;struct Edge{int to;ll w;};vector<Edge> S[N];
int n,m,k,H,Bg[N],En[N],Df[N],X[N],Y[N];ll D[N],Z[N],La,x,y,W;
I void dfs(int x,int La){Df[Bg[x]=++H]=x;for(Edge d:S[x]) d.to^La&&(D[d.to]=D[x]+d.w,dfs(d.to,x),Df[++H]=x);En[x]=H;}
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	ll F[N<<2],C[N<<2],LC[N<<2],CR[N<<2],LCR[N<<2],G[N<<2];I void PF(int now,ll w){G[now]+=w;F[now]+=w;C[now]+=w;LC[now]-=w;CR[now]-=w;}I void P(int now){G[now]&&(PF(ls,G[now]),PF(rs,G[now]),G[now]=0);}
	I void Up(int now){F[now]=max(F[ls],F[rs]);C[now]=min(C[ls],C[rs]);LC[now]=max(max(LC[ls],LC[rs]),F[ls]-2*C[rs]);CR[now]=max(max(CR[ls],CR[rs]),F[rs]-2*C[ls]);LCR[now]=max(max(LCR[ls],LCR[rs]),max(F[ls]+CR[rs],LC[ls]+F[rs]));}
	I void BD(int l=1,int r=H,int now=1){if(l==r) {F[now]=C[now]=D[Df[l]];LC[now]=CR[now]=-D[Df[l]];LCR[now]=0;return;}int m=l+r>>1;BD(l,m,ls);BD(m+1,r,rs);Up(now);}
	I void Ins(int x,int y,ll w,int l=1,int r=H,int now=1){if(x<=l&&r<=y) return PF(now,w);P(now);int m=l+r>>1;x<=m&&(Ins(x,y,w,l,m,ls),0);y>m&&(Ins(x,y,w,m+1,r,rs),0);Up(now);} 
}
int main(){
//	freopen("1.in","r",stdin);
	int i;scanf("%d%d%lld",&n,&m,&W);for(i=1;i<n;i++) scanf("%d%d%lld",&X[i],&Y[i],&Z[i]),S[X[i]].PB((Edge){Y[i],Z[i]}),S[Y[i]].PB((Edge){X[i],Z[i]});dfs(1,0);Tree::BD();
	for(i=1;i<n;i++) Bg[X[i]]>Bg[Y[i]]&&(swap(X[i],Y[i]),0);while(m--) scanf("%lld%lld",&x,&y),x=(x+La)%(n-1)+1,y=(y+La)%W,Tree::Ins(Bg[Y[x]],En[Y[x]],y-Z[x]),Z[x]=y,printf("%lld\n",La=Tree::LCR[1]);
}