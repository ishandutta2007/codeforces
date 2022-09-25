#include<cstdio>
using namespace std;
int head[100001],cnt,n,f[100001],tp[100001],sz[100001],dep[100001],sn[100001],id[100001],ecnt,m,a,b,c,d,v[100001],f1[100001][18],tid[100001];
char s;
struct edge{
	int l,r;
	long long sum,lazy;
}e[1200001];
void pushup(int m)
{
	e[m].sum=e[m<<1].sum+e[m<<1|1].sum;
}
void pushdown(int m)
{
	e[m<<1].lazy+=e[m].lazy;
	e[m<<1].sum+=e[m].lazy*(e[m<<1].r-e[m<<1].l+1);
	e[m<<1|1].lazy+=e[m].lazy;
	e[m<<1|1].sum+=e[m].lazy*(e[m<<1|1].r-e[m<<1|1].l+1);
	e[m].lazy=0;
}
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	e[m].sum=e[m].lazy=0;
	if(l==r)
	{
		e[m].sum=v[tid[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
	pushup(m);
}
void add(int m,int l,int r,long long y)
{
	if(e[m].l==l&&e[m].r==r)
	{
		e[m].lazy+=y;
		e[m].sum+=y*(e[m].r-e[m].l+1);
		return;
	}
	pushdown(m);
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=r)
	add(m<<1,l,r,y);
	else
	if(mid<l)
	add(m<<1|1,l,r,y);
	else
	add(m<<1,l,mid,y),add(m<<1|1,mid+1,r,y);
	pushup(m);
}
long long que(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	return e[m].sum;
	pushdown(m);
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=r)
	return que(m<<1,l,r);
	else
	if(mid<l)
	return que(m<<1|1,l,r);
	else
	return que(m<<1,l,mid)+que(m<<1|1,mid+1,r);
}
struct edg{
	int t,next;
}ed[200003];
void adde(int f,int t)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	head[t]=cnt;
}
void dfs1(int u,int fa)
{
	int tmp=0;
	sz[u]=1;
	f1[u][0]=f[u]=fa;
	for(int i=1;i<=17;i++)
	f1[u][i]=f1[f1[u][i-1]][i-1];
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs1(ed[i].t,u);
		sz[u]+=sz[ed[i].t];
		if(sz[ed[i].t]>tmp)
		tmp=sz[ed[i].t],sn[u]=ed[i].t;
	}
}
void dfs2(int u,int v)
{
	id[u]=++ecnt;
	tid[ecnt]=u;
	tp[u]=v;
	if(sn[u])
	dfs2(sn[u],v);
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=f[u]&&ed[i].t!=sn[u])
	dfs2(ed[i].t,ed[i].t);
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])
	a^=b^=a^=b;
	for(int i=17;i>=0;i--)
	if(dep[a]-(1<<i)>=dep[b])
	a=f1[a][i];
	if(a==b)
	return a;
	for(int i=17;i>=0;i--)
	if(f1[a][i]!=f1[b][i])
	a=f1[a][i],b=f1[b][i];
	return f1[a][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	for(int i=1;i<n;i++)
	scanf("%d%d",&a,&b),adde(a,b);
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	int rt=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==1) rt=b;
		else
		if(a==2)
		{
			scanf("%d%d",&c,&d);
			int lca=LCA(b,c),lca2=LCA(b,rt),lca3=LCA(c,rt);
			if(dep[lca]<dep[lca2])
			lca=lca2;
			if(dep[lca]<dep[lca3])
			lca=lca3;
			if(rt==lca)
			add(1,1,n,d);
			else
			if(LCA(rt,lca)==lca)
			{
				int t=rt;
				for(int i=17;i>=0;i--)
				if(dep[f1[t][i]]>dep[lca])
				t=f1[t][i];
				add(1,1,n,d),add(1,id[t],id[t]+sz[t]-1,-d);
			}
			else
			add(1,id[lca],id[lca]+sz[lca]-1,d);
		}
		else
		{
			if(rt==b)
			printf("%lld\n",que(1,1,n));
			else
			if(LCA(rt,b)==b)
			{	
				int t=rt;
				for(int i=17;i>=0;i--)
				if(dep[f1[t][i]]>dep[b])
				t=f1[t][i];
				printf("%lld\n",que(1,1,n)-que(1,id[t],id[t]+sz[t]-1));
			}
			else
			printf("%lld\n",que(1,id[b],id[b]+sz[b]-1));
		}
		
	}
}