#include<bits/stdc++.h>
using namespace std;
const int N=20405,M=205;
int n,m,na,nb,S,T,cc,ans,a[M],b[M],hd[M],d[M],iter[M],Q[M],vis[M][M];
struct st{int x1,y1,x2,y2;}w[55];
struct E{int v,nxt,w;}e[N];
inline void add(int u,int v,int w){e[++cc]=(E){v,hd[u],w};hd[u]=cc;e[++cc]=(E){u,hd[v],0};hd[v]=cc;}
inline int bfs()
{
	for(int i=1;i<=T;i++)d[i]=0,iter[i]=hd[i];
	int ql=0,qr=0;Q[++qr]=S;d[S]=1;
	while(ql<qr)
	{
		int x=Q[++ql];
		for(int i=hd[x];i;i=e[i].nxt)if(!d[e[i].v]&&e[i].w)d[e[i].v]=d[x]+1,Q[++qr]=e[i].v;
	}
	return d[T];
}
int dfs(int x,int f)
{
	if(x==T||!f)return f;
	int sf=0;
	for(int i=iter[x];i;i=e[i].nxt)if(d[e[i].v]==d[x]+1&&e[i].w)
	{
		int w=dfs(e[i].v,min(e[i].w,f));
		if(f){e[i].w-=w;e[i^1].w+=w;f-=w;sf+=w;}
	}
	return sf;
}
int main()
{
	scanf("%d%d",&n,&m);cc=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&w[i].x1,&w[i].y1,&w[i].x2,&w[i].y2),w[i].x2++,w[i].y2++;
		a[++na]=w[i].x1;a[++na]=w[i].x2;b[++nb]=w[i].y1;b[++nb]=w[i].y2;
	}
	sort(a+1,a+na+1);na=unique(a+1,a+na+1)-a-1;
	sort(b+1,b+nb+1);nb=unique(b+1,b+nb+1)-b-1;
	S=na+nb+1;T=S+1;
	for(int i=1;i<na;i++)add(S,i,a[i+1]-a[i]);
	for(int i=1;i<nb;i++)add(na+i,T,b[i+1]-b[i]);
	for(int i=1,lx,rx,ly,ry;i<=m;i++)
	{
		lx=lower_bound(a+1,a+na+1,w[i].x1)-a;rx=lower_bound(a+1,a+na+1,w[i].x2)-a;
		ly=lower_bound(b+1,b+nb+1,w[i].y1)-b;ry=lower_bound(b+1,b+nb+1,w[i].y2)-b;
		for(int x=lx;x<rx;x++)for(int y=ly;y<ry;y++)if(!vis[x][y])vis[x][y]=1,add(x,na+y,1e9);
	}
	while(bfs())ans+=dfs(S,1e9);printf("%d\n",ans);return 0;
}