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
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,q,x,y,low[N+5],dfn[N+5],dh,cnt,st[N+5],sh,d[N+5],siz[N+5],son[N+5],top[N+5],Id[N+5],Idea,fa[N+5],W[N+5];multiset<int> F[N+5];char op;multiset<int>::it pus;
struct yyy{int to,z;}tmp;struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s,G;
I void con(int x,int y){G.add(x,y),G.add(y,x);}I void Tarjan(int x){
	low[x]=dfn[x]=++dh;st[++sh]=x;yyy tmp;for(RI i=s.h[x];i;i=tmp.z){
		tmp=s.f[i];if(dfn[tmp.to]){low[x]=min(low[x],dfn[tmp.to]);continue;}Tarjan(tmp.to);low[x]=min(low[x],low[tmp.to]);
		if(low[tmp.to]>=dfn[x]){con(++cnt,x);while(st[sh+1]^tmp.to) con(cnt,st[sh--]);}
	}
}
struct Tree{
	#define ls now<<1
	#define rs now<<1|1
	int F[N+5<<2];I void Up(int now){F[now]=min(F[ls],F[rs]);}
	I void Get(int x,int y,int l=1,int r=cnt,int now=1){if(l==r){F[now]=y;return;}int m=l+r>>1;x<=m?Get(x,y,l,m,ls):Get(x,y,m+1,r,rs);Up(now);}
	I int Find(int x,int y,int l=1,int r=cnt,int now=1){/*printf("%d %d\n",x,y);*/if(x<=l&&r<=y) return F[now];int m=l+r>>1,F1=1e9,F2=1e9;x<=m&&(F1=Find(x,y,l,m,ls));y>m&&(F2=Find(x,y,m+1,r,rs),0);return min(F1,F2);}
}T;
I void dfs1(int x,int LA){yyy tmp;d[x]=d[LA]+1;siz[x]=1;fa[x]=LA;for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^LA&&(dfs1(tmp.to,x),siz[x]+=siz[tmp.to],siz[son[x]]<siz[tmp.to]&&(son[x]=tmp.to));}
I void dfs2(int x,int LA){yyy tmp;top[x]=LA;Id[x]=++Idea;T.Get(Id[x],W[x]);if(!son[x]) return;dfs2(son[x],LA);for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^fa[x]&&tmp.to^son[x]&&(dfs2(tmp.to,tmp.to),0);}
I void CG(int x,int y){
	fa[x]&&(F[fa[x]].erase(F[fa[x]].lower_bound(W[x])),0);W[x]=y;fa[x]&&(F[fa[x]].insert(y),0);T.Get(Id[x],y);fa[x]&&(T.Get(Id[fa[x]],*F[fa[x]].begin()),0);
}
I int Qry(int x,int y){
	int Ans=2e9,now;while(top[x]^top[y]) d[top[x]]<d[top[y]]&&(swap(x,y),0),now=T.Find(Id[top[x]],Id[x]),Ans=min(Ans,now),x=fa[top[x]];d[x]>d[y]&&(swap(x,y),0);now=T.Find(Id[x],Id[y]);Ans=min(Ans,now);if(x>n) now=T.Find(Id[fa[x]],Id[fa[x]]),Ans=min(Ans,now);return Ans;
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;Me(T.F,0x3f);scanf("%d%d%d",&n,&m,&q);cnt=n;for(i=1;i<=n;i++)scanf("%d",&W[i]);while(m--) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);for(i=1;i<=n;i++) !dfn[i]&&(Tarjan(i),0);s=G;
	dfs1(1,0);for(i=n+1;i<=cnt;i++)for(W[i]=1e9,j=s.h[i];j;j=tmp.z) tmp=s.f[j],d[tmp.to]>d[i]&&(F[i].insert(W[tmp.to]),W[i]=min(W[i],W[tmp.to]));dfs2(1,1);
	while(q--){op=Gc();while(op<'A'||op>'Z') op=Gc();scanf("%d%d",&x,&y);op^'A'?(CG(x,y),0):(printf("%d\n",Qry(x,y)));}
}