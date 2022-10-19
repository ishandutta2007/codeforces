#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,m4,edge_t=0,dfn_t=0,t=1,res=0,S,T;
int la[100002]={},siz[100002],dfn[100002],id[100002],bl[100002],a[100002]={},cnt[322]={},laz[322]={},st[322],ed[322],len[322],ans[100002];
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	int pos,ax,ay,bx,by,d;
}q[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(bbb a,bbb b)
{
	return (a.pos==b.pos)? (a.d>b.d):(a.pos<b.pos);
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	id[dfn[x]=(++dfn_t)]=x,siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x),siz[x]+=siz[v];
}
inline void modify(int l,int r,int d)
{
	if(bl[l]==bl[r])
	{
		if(!laz[bl[l]])res-=cnt[bl[l]];
		for(int i=l;i<=r;++i)
		{
			if(!a[i])++cnt[bl[l]];
			a[i]+=d;
			if(!a[i])--cnt[bl[l]];
		}
		if(!laz[bl[l]])res+=cnt[bl[l]];
		return ;
	}
	for(int i=bl[l]+1;i<bl[r];++i)
	{
		if(!laz[i])res+=len[i]-cnt[i];
		laz[i]+=d;
		if(!laz[i])res-=len[i]-cnt[i];
	}
	if(!laz[bl[l]])res-=cnt[bl[l]];
	for(int i=l;i<=ed[bl[l]];++i)
	{
		if(!a[i])++cnt[bl[l]];
		a[i]+=d;
		if(!a[i])--cnt[bl[l]];
	}
	if(!laz[bl[l]])res+=cnt[bl[l]];
	if(!laz[bl[r]])res-=cnt[bl[r]];
	for(int i=st[bl[r]];i<=r;++i)
	{
		if(!a[i])++cnt[bl[r]];
		a[i]+=d;
		if(!a[i])--cnt[bl[r]];
	}
	if(!laz[bl[r]])res+=cnt[bl[r]];
}
int main()
{
	read(n),read(m),m4=4*m,S=sqrt(n),T=(n-1)/S;
	for(int i=0;i<=T;++i)st[i]=i*S+1,ed[i]=min((i+1)*S,n),len[i]=ed[i]-st[i]+1;
	for(int i=1;i<=n;++i)bl[i]=(i-1)/S;
	for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	dfs(1,0);
	for(int i=1,x,y;i<=m;++i)
	{
		read(x),read(y);
		q[4*i-3]=(bbb){dfn[x],dfn[x],dfn[x]+siz[x]-1,dfn[y],dfn[y]+siz[y]-1,1};
		q[4*i-2]=(bbb){dfn[x]+siz[x]-1,dfn[x],dfn[x]+siz[x]-1,dfn[y],dfn[y]+siz[y]-1,-1};
		q[4*i-1]=(bbb){dfn[y],dfn[x],dfn[x]+siz[x]-1,dfn[y],dfn[y]+siz[y]-1,1};
		q[4*i]=(bbb){dfn[y]+siz[y]-1,dfn[x],dfn[x]+siz[x]-1,dfn[y],dfn[y]+siz[y]-1,-1};
	}
	sort(q+1,q+m4+1,cmp);
	for(int i=1;i<=n;++i)
	{
		while(t<=m4 && q[t].pos==i && q[t].d>0)modify(q[t].ax,q[t].ay,1),modify(q[t].bx,q[t].by,1),++t;
		modify(i,i,1),ans[id[i]]=res-1,modify(i,i,-1);
		while(t<=m4 && q[t].pos==i && q[t].d<0)modify(q[t].ax,q[t].ay,-1),modify(q[t].bx,q[t].by,-1),++t;
	}
	for(int i=1;i<=n;++i)printf("%d%c",ans[i],i==n? '\n':' ');
	return 0;
}