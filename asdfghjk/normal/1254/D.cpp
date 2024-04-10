#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=150005,md=998244353;
int n,q,w,i,j,k,head[N],adj[N*2],nxt[N*2],dep[N],fa[N],size[N],son[N],tp[N],id[N],g[400][N],c[N],d[N],e[N],tot,p[N],All,invn,ans;
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
void work(int x,int dad)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			work(adj[y],x);
			size[x]+=size[adj[y]];
		}
}
void Work(int x,int dad)
{
	g[tot][x]=k;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
			Work(adj[y],x);
}
void dfs(int x,int dad)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dep[adj[y]]=dep[x]+1;
			fa[adj[y]]=x;
			dfs(adj[y],x);
			size[x]+=size[adj[y]];
			if(!son[x]||size[adj[y]]>size[son[x]])
				son[x]=adj[y];
		}
}
void Dfs(int x,int dad)
{
	id[x]=++i;
	if(son[x])
	{
		tp[son[x]]=tp[x];
		Dfs(son[x],x);
	}
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad&&adj[y]!=son[x])
		{
			tp[adj[y]]=adj[y];
			Dfs(adj[y],x);
		}
}
void add(int x,int y)
{
	while(x<=n)
	{
		e[x]=(e[x]+y)%md;
		x+=x&-x;
	}
}
int sum(int x)
{
	int rtn=0;
	while(x)
	{
		rtn=(rtn+e[x])%md;
		x-=x&-x;
	}
	return rtn;
}
int main()
{
	scanf("%d%d",&n,&q);
	w=(int)sqrt(n);
	invn=pw(n,md-2);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		++d[j],++d[k];
	}
	for(i=1;i<=n;++i)
		if(d[i]>w)
		{
			p[++tot]=i;
			work(i,-1);
			for(j=head[i];j;j=nxt[j])
			{
				k=size[adj[j]];
				Work(adj[j],i);
			}
		}
	dfs(1,-1);
	tp[1]=1;
	i=0;
	Dfs(1,-1);
	while(q--)
	{
		scanf("%d",&i);
		if(i==1)
		{
			scanf("%d%d",&i,&j);
			All=(All+j)%md;
			if(d[i]>w)
			{
				c[i]=(c[i]-j+md)%md;
				continue;
			}
			All=(All-1ll*j*(n-size[i])%md*invn%md+md)%md;
			add(id[i],1ll*j*(n-size[i])%md*invn%md);
			for(k=head[i];k;k=nxt[k])
				if(dep[adj[k]]>dep[i])
					add(id[adj[k]],(md-1ll*size[adj[k]]*invn%md*j%md)%md);
		}
		else
		{
			scanf("%d",&i);
			ans=All;
			j=i;
			while(j)
			{
				ans=(1ll*ans+sum(id[j])-sum(id[tp[j]]-1)+md)%md;
				j=fa[tp[j]];
			}
			for(j=1;j<=tot;++j)
				ans=(ans+1ll*g[j][i]*invn%md*c[p[j]])%md;
			printf("%d\n",ans);
		}
	}
	return 0;
}