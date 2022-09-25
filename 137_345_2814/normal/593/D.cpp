#include<cstdio>
using namespace std;
int head[200001],cnt,n,sz[200001],dep[200001],sn[200001],id[200001],tp[200001],tid[200001],f[200001],f1[200001][19],ecnt,m;
long long val[200001],edg[200001][3],a,b,c,d;
struct ed1{
	int l,r;
	long long v;
}e[800001];
inline long long un(long long x,long long y)
{
	if((double)1e18/x<y)
	return 1e18+5000;
	else
	return x*y;
}
void pushup(int m)
{
	e[m].v=un(e[m<<1].v,e[m<<1|1].v);
}
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	if(e[m].l==e[m].r)
	{
		e[m].v=val[tid[l]];
		return;
	}
	int mid=(e[m].l+e[m].r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
	pushup(m);
}
void add(int m,int x,long long y)
{
	if(e[m].l==e[m].r)
	{
		e[m].v=y;
		return;
	}
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=x)
	add(m<<1,x,y);
	else
	add(m<<1|1,x,y);
	pushup(m);
}
long long query(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	return e[m].v;
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=r)
	return query(m<<1,l,r);
	else
	if(mid<l)
	return query(m<<1|1,l,r);
	else
	return un(query(m<<1,l,mid),query(m<<1|1,mid+1,r));
}
struct edge{
	int t,next;
	long long v;
}ed[400003];
void adde(int f,int t,long long v)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[cnt].v=v;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	head[t]=cnt;
	ed[cnt].v=v;
}
void dfs1(int u,int fa)
{
	f1[u][0]=f[u]=fa;
	for(int i=1;i<=18;i++)
	f1[u][i]=f1[f1[u][i-1]][i-1];
	dep[u]=dep[fa]+1;sz[u]=1;
	int tmp=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs1(ed[i].t,u);
		sz[u]+=sz[ed[i].t];
		if(sz[ed[i].t]>tmp)
		tmp=sz[ed[i].t],sn[u]=ed[i].t;
	}
}
void dfs2(int u,int v,long long sb)
{
	id[u]=++ecnt;
	tid[ecnt]=u;
	val[u]=sb;tp[u]=v;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t==sn[u])
	dfs2(sn[u],v,ed[i].v);
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=sn[u]&&ed[i].t!=f[u])
	dfs2(ed[i].t,ed[i].t,ed[i].v);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])
	x^=y^=x^=y;
	for(int i=18;i>=0;i--)
	if(dep[x]-(1<<i)>=dep[y])
	x=f1[x][i];
	if(x==y)
	return x;
	for(int i=18;i>=0;i--)
	if(f1[x][i]!=f1[y][i])
	x=f1[x][i],y=f1[y][i];
	return f1[x][0];
}
long long querys(int a,int b)
{
	long long tmp=1;
	int lca=LCA(a,b);
	while(tp[a]!=tp[lca])
	{
		tmp=un(tmp,query(1,id[tp[a]],id[a]));
		a=f[tp[a]];
	}
	if(a!=lca)
	tmp=un(tmp,query(1,id[lca]+1,id[a]));
	while(tp[b]!=tp[lca])
	{
		tmp=un(tmp,query(1,id[tp[b]],id[b]));
		b=f[tp[b]];
	}
	if(b!=lca)
	tmp=un(tmp,query(1,id[lca]+1,id[b]));
	return tmp;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	scanf("%lld%lld%lld",&edg[i][0],&edg[i][1],&edg[i][2]),adde(edg[i][0],edg[i][1],edg[i][2]);
	dfs1(1,0);
	dfs2(1,1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&a);
		if(a==1)
		{
			scanf("%lld%lld%lld",&b,&c,&d);
			long long st=querys(b,c);
			printf("%lld\n",d/st);
		}
		else
		{
			scanf("%lld%lld",&b,&c);
			int a1=edg[b][0],a2=edg[b][1];
			if(dep[a1]<dep[a2])
			a1=a2;
			add(1,id[a1],c);
		}
	}
}