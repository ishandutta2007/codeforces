#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 500000
#define M 1000000
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,m,k,Fl[N+5],x[N+5],y[N+5],z[N+5],Ans[N+5],Q[N+5],Fa[N+5],fa[N+5],d[N+5],top[N+5],id[N+5],siz[N+5],idea,son[N+5],F[N+5<<2],G[N+5<<2],un,wn; 
struct yyy{int to,w,z;};
struct ljb{int head,h[N+5];yyy f[N+5<<2];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s;
I int Getfa(int x){return x==Fa[x]?x:Fa[x]=Getfa(Fa[x]);}
I void dfs1(int x,int last){
	d[x]=d[last]+1;yyy tmp;siz[x]=1;fa[x]=last;for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^last&&(Q[tmp.to]=Q[x]^tmp.w,dfs1(tmp.to,x),siz[x]+=siz[tmp.to],siz[son[x]]<siz[tmp.to]&&(son[x]=tmp.to));
}
I void dfs2(int x,int last){
	top[x]=last;id[x]=++idea;yyy tmp;if(!son[x]) return;dfs2(son[x],last);for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^fa[x]&&tmp.to^son[x]&&(dfs2(tmp.to,tmp.to),0);
}
I void insert(int x,int y,int l=1,int r=n+1,int now=1){
	F[now]=1;if(x<=l&&r<=y) return (void)(G[now]=1);int m=l+r>>1;x<=m&&(insert(x,y,l,m,now<<1),0);y>m&&(insert(x,y,m+1,r,now<<1|1),0);
}
I int find(int x,int y,int l=1,int r=n+1,int now=1){//printf("%d %d\n",x,y);
	if(G[now]) return 1;if(x<=l&&r<=y) return F[now];int m=l+r>>1;return (x<=m&&find(x,y,l,m,now<<1))||(y>m&&find(x,y,m+1,r,now<<1|1));
}I void swap(int &x,int &y){x^=y^=x^=y;}
I void Get(int x,int y){while(top[x]^top[y])d[top[x]]<d[top[y]]&&(swap(x,y),0),insert(id[top[x]],id[x]),x=fa[top[x]];d[x]>d[y]&&(swap(x,y),0);x^y&&(insert(id[x]+1,id[y]),0);}
I int Query(int x,int y){while(top[x]^top[y]) {d[top[x]]<d[top[y]]&&(swap(x,y),0);if(find(id[top[x]],id[x]))return 1;x=fa[top[x]];}d[x]>d[y]&&(swap(x,y),0);return x^y&&find(id[x]+1,id[y]);}
int main(){ 
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) Fa[i]=i;for(i=1;i<=m;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);for(i=1;i<=m;i++) un=Getfa(x[i]),wn=Getfa(y[i]),un^wn&&(Fa[un]=wn,s.add(x[i],y[i],z[i]),s.add(y[i],x[i],z[i]),Ans[i]=1);
	for(i=1;i<=n;i++) Fl[Getfa(i)]=1;for(i=1;i<=n;i++)Fl[i]&&(s.add(n+1,i,0),0);dfs1(n+1,0);dfs2(n+1,n+1);for(i=1;i<=m;i++)!Ans[i]&&Q[x[i]]^Q[y[i]]^z[i]&&!Query(x[i],y[i])&&(Get(x[i],y[i]),Ans[i]=1);for(i=1;i<=m;i++)puts(Ans[i]?"YES":"NO");
}