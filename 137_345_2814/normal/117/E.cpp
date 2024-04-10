#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
#define lsj 1+2
#define ak ==
#define ioi 3
int n,head[100001],cnt,c[100001],id[100001],f1[100001],tp[100001],sz[100001],f[100001][18],lc,ecnt,sid[100001],q,a,b,ins[100001],fg,rt,dis[100001],sn[100001],dep[100001],m,fr[100001];
struct edge{
	int t,next;
}ed[200001];
void adde(int f,int t)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	head[t]=cnt;
}
stack<int> p;
void dfs1(int u,int fa)
{
	ins[u]=1;
	p.push(u);
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		if(!ins[ed[i].t])
		dfs1(ed[i].t,u);
		else
		{
			fg=1;
			rt=u;
			while(lsj ak ioi)
			{
				int s=p.top();p.pop();
				for(int j=0;j<=17;j++)f[s][j]=s;
				lc++;c[s]=1;
				if(s==ed[i].t)
				break;
			}
		}
		if(fg)return;
	}
	p.pop();
}
void dfs2(int u,int fa)
{
	fr[u]=u;
	id[u]=++ecnt;
	sid[ecnt]=u;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&c[ed[i].t]&&!id[ed[i].t])
	dis[ed[i].t]=dis[u]+1,dfs2(ed[i].t,u);
}
struct edg{
	int l,r,sum,lazy;
}e[1200001];
void pushup(int m)
{
	e[m].sum=e[m<<1].sum+e[m<<1|1].sum;
}
void pushdown(int m)
{
	e[m<<1].lazy^=1;
	e[m<<1].sum=(e[m<<1].r-e[m<<1].l+1)-e[m<<1].sum;
	e[m<<1|1].lazy^=1;
	e[m<<1|1].sum=(e[m<<1|1].r-e[m<<1|1].l+1)-e[m<<1|1].sum;
	e[m].lazy=0;
}
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	e[m].sum=e[m].lazy=0;
	if(l==r)
	return;
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
}
void add(int m,int l,int r)
{
	if(l>r)return;
	if(e[m].l==l&&e[m].r==r)
	{
		e[m].lazy^=1;
		e[m].sum=(e[m].r-e[m].l+1)-e[m].sum;
		return;
	}
	if(e[m].lazy)
	pushdown(m);
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=r)
	add(m<<1,l,r);
	else
	if(mid<l)
	add(m<<1|1,l,r);
	else
	add(m<<1,l,mid),add(m<<1|1,mid+1,r);
	pushup(m);
}
long long que(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	return e[m].sum;
	if(e[m].lazy)
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
void dfs3(int u,int fa)
{
	int tmp=0;
	sz[u]=1;
	f[u][0]=f1[u]=fa;
	for(int i=1;i<=17;i++)
	f[u][i]=f[f[u][i-1]][i-1];
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!c[ed[i].t])
	{
		dfs3(ed[i].t,u);
		sz[u]+=sz[ed[i].t];
		if(sz[ed[i].t]>tmp)
		tmp=sz[ed[i].t],sn[u]=ed[i].t;
	}
}
void dfs4(int u,int v)
{
	id[u]=++ecnt;
//	tid[ecnt]=u;
	tp[u]=v;
	if(sn[u])
	dfs4(sn[u],v);
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=f[u][0]&&ed[i].t!=sn[u]&&!c[ed[i].t])
	dfs4(ed[i].t,ed[i].t);
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])
	a^=b^=a^=b;
	for(int i=17;i>=0;i--)
	if(dep[a]-(1<<i)>=dep[b])
	a=f[a][i];
	if(a==b)
	return a;
	for(int i=17;i>=0;i--)
	if(f[a][i]!=f[b][i])
	a=f[a][i],b=f[b][i];
	return f[a][0];
}
void adds(int x,int y,int s)
{
	int lca=LCA(x,y);
	while(tp[x]!=tp[lca])
	{
		add(1,id[tp[x]],id[x]);
		x=f[tp[x]][0];
	}
	if(x!=lca)
	add(1,id[lca]+1,id[x]);x=y;
	while(tp[x]!=tp[lca])
	{
		add(1,id[tp[x]],id[x]);
		x=f[tp[x]][0];
	}
	if(x!=lca)
	add(1,id[lca]+1,id[x]);
	if(s)
	add(1,id[lca],id[lca]);
}
inline int Abs(int s)
{
	return s>0?s:-s;
}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&a,&b),adde(a,b);
	dfs1(1,0);
	for(int i=1;i<=n;i++)
	if(c[i])
	{
		dis[i]=0;
		dfs2(i,0);
		break;
	}
	for(int i=1;i<=n;i++)
	if(c[i])
	for(int j=head[i];j;j=ed[j].next)
	if(!c[ed[j].t])
	dfs3(ed[j].t,ed[j].t),dfs4(ed[j].t,ed[j].t),fr[ed[j].t]=i;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(f[a][17]==f[b][17])
		adds(a,b,0);
		else
		{
			if(!c[a])
			adds(a,f[a][17],1);
			if(!c[b])
			adds(b,f[b][17],1);
			a=fr[f[a][17]],b=fr[f[b][17]];
			int tmp=0,f2=id[a]-1,f3=id[a]+1;
			if(f2==0)f2=lc;
			if(f3>lc)f3=1;
			if(lc%2==0&&((sid[f2]<sid[f3])^(id[a]>id[b])))
			tmp=1;
			if(a==b)tmp=0;
			if(id[a]>id[b])a^=b^=a^=b;
			if(Abs(dis[a]-dis[b])<=lc/2&&(tmp==0||Abs(dis[a]-dis[b])<lc/2))
			add(1,id[a],id[b]-1);
			else
			add(1,1,id[a]-1),add(1,id[b],lc);
		}
		int tmp=n-que(1,1,n)+1,tmp2=que(1,1,lc);
		if(tmp2!=lc)
		tmp--;
		printf("%d\n",tmp);
	}
}