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
#define N (100000+5)
#define M N*100+5
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
int n,m,k,x,y,cnt,fa[N],d[N],Tp[N],Sn[N],Si[N],Id[N],Is,X1,X2,Y1,Y2;vector<int> S[M];
I void dfs1(int x,int La){d[x]=d[fa[x]=La]+1;Si[x]=1;for(RI i:S[x]) i^La&&(dfs1(i,x),Si[x]+=Si[i],Si[Sn[x]]<Si[i]&&(Sn[x]=i));}
I void dfs2(int x,int La){Tp[x]=La;Id[x]=++Is;if(!Sn[x]) return;dfs2(Sn[x],La);for(RI i:S[x]) i^fa[x]&&i^Sn[x]&&(dfs2(i,i),0);}
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	vector<int> P[N<<2];I void Ins(int x,int y,int w,int l=1,int r=n,int now=1){if(x<=l&&r<=y) return P[now].PB(w);int m=l+r>>1;x<=m&&(Ins(x,y,w,l,m,ls),0);y>m&&(Ins(x,y,w,m+1,r,rs),0);}
	I void Make(int Lx,int Ly,int l=1,int r=n,int now=1){RI A,B;
		for(RI i:P[now]) A=++cnt,B=++cnt,S[i].PB(A),S[B].PB(i^1),~Lx&&(S[Lx].PB(A),S[B].PB(Ly),S[Lx].PB(i^1),S[i].PB(Ly),0),Lx=A,Ly=B;
		if(l==r) return;int m=l+r>>1;Make(Lx,Ly,l,m,ls);Make(Lx,Ly,m+1,r,rs);
	}
	#undef ls
	#undef rs
}
I void Ins(int x,int y,int w){while(Tp[x]^Tp[y]) d[Tp[x]]<d[Tp[y]]&&(swap(x,y),0),Tree::Ins(Id[Tp[x]],Id[x],w),x=fa[Tp[x]];d[x]>d[y]&&(swap(x,y),0);x^y&&(Tree::Ins(Id[x]+1,Id[y],w),0);}
namespace SAT{
	int Sh,dfn[M],low[M],vis[M],st[M],H,scc[M],Dh;I void Tarjan(int x){
		vis[st[++H]=x]=1;dfn[x]=low[x]=++Dh;for(RI i:S[x])dfn[i]?(vis[i]&&(low[x]=min(low[x],low[i]))):(Tarjan(i),low[x]=min(low[x],low[i])) ;if(low[x]==dfn[x]){Sh++;while(st[H+1]^x)scc[st[H]]=Sh,vis[st[H]]=0,H--;}
	}I void Solve(){Me(st,-1);RI i;for(i=0;i<=cnt;i++) !dfn[i]&&(Tarjan(i),0);for(i=0;i<2*m;i+=2) if(scc[i]==scc[i^1]){puts("NO");exit(0);}puts("YES");for(i=0;i<2*m;i+=2) printf("%d\n",1+(scc[i]>scc[i^1]));}
}
int main(){
//	freopen("color.in","r",stdin);freopen("color.out","w",stdout);
	RI i;scanf("%d",&n);for(i=1;i<n;i++) scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);dfs1(1,0);dfs2(1,1);for(i=1;i<=n;i++) S[i].clear();scanf("%d",&m);
	cnt=2*m-1;for(i=0;i<2*m;i+=2)scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2),Ins(X1,Y1,i),Ins(X2,Y2,i^1);Tree::Make(-1,-1);SAT::Solve();
}