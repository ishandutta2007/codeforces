#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int n,m,q,cnt,i,j,k,l,head[N],adj[N],nxt[N],id[N],pre[N],col[N],tot,Head[N],Adj[N],Nxt[N],size[N],dep[N],fa[N],son[N],tp[N],c[N],d[N],bl[N];
bool v[N],b[N];
void Addedge(int u,int v)
{
	Adj[++l]=v;
	Nxt[l]=Head[u];
	Head[u]=l;
	Adj[++l]=u;
	Nxt[l]=Head[v];
	Head[v]=l;
}
void dfs(int x,int dad)
{
	id[x]=pre[x]=++cnt;
	for(int y=head[x];y;y=nxt[y])
		if(!id[adj[y]])
		{
			dfs(adj[y],(y+1)/2);
			pre[x]=min(pre[x],pre[adj[y]]);
			if(pre[adj[y]]>id[x])
				b[(y+1)/2]=true;
		}
		else if((y+1)/2!=dad)
			pre[x]=min(pre[x],id[adj[y]]);
}
void work(int x)
{
	col[x]=tot;
	for(int y=head[x];y;y=nxt[y])
		if(!col[adj[y]]&&!b[(y+1)/2])
			work(adj[y]);
}
void dfs1(int x,int dad)
{
	bl[x]=i;
	size[x]=1;
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad)
		{
			dep[Adj[y]]=dep[x]+1;
			fa[Adj[y]]=x;
			dfs1(Adj[y],x);
			size[x]+=size[Adj[y]];
			if(!son[x]||size[Adj[y]]>size[son[x]])
				son[x]=Adj[y];
		}
}
void dfs2(int x,int dad)
{
	if(son[x])
	{
		tp[son[x]]=tp[x];
		dfs2(son[x],x);
	}
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad&&Adj[y]!=son[x])
		{
			tp[Adj[y]]=Adj[y];
			dfs2(Adj[y],x);
		}
}
int lca(int a,int b)
{
	while(tp[a]!=tp[b])
	{
		if(dep[tp[a]]<dep[tp[b]])
			swap(a,b);
		a=fa[tp[a]];
	}
	return dep[a]<dep[b]?a:b;
}
void dzx(int x,int dad)
{
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad)
		{
			dzx(Adj[y],x);
			c[x]+=c[Adj[y]],d[x]+=d[Adj[y]];
		}
	if(c[x]&&d[x])
		k=0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	for(i=1;i<=n;++i)
		if(!id[i])
			dfs(i,-1);
	for(i=1;i<=n;++i)
		if(!col[i])
		{
			++tot;
			work(i);
		}
	for(i=1;i<=m;++i)
		if(col[adj[i*2-1]]!=col[adj[i*2]])
			Addedge(col[adj[i*2-1]],col[adj[i*2]]);
	for(i=1;i<=tot;++i)
		if(!tp[i])
		{
			dfs1(i,-1);
			tp[i]=i;
			dfs2(i,-1);
		}
	while(q--)
	{
		scanf("%d%d",&i,&j);
		i=col[i],j=col[j];
		if(bl[i]!=bl[j])
		{
			printf("No");
			return 0;
		}
		k=lca(i,j);
		c[i]++,c[k]--;
		d[j]++,d[k]--;
	}
	k=1;
	for(i=1;i<=tot;++i)
		if(bl[i]==i)
			dzx(i,-1);
	if(k)
		printf("Yes");
	else
		printf("No");
	return 0;
}