#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int n,q,K,m,i,j,k,h[N],t[N],num,fa[N],s[N],id[N],size[N],son[N],tp[N],dep[N],head[N],adj[N*2],nxt[N*2],p[N],cnt,stk[N],top,g[N],Head[N],Adj[N*2],Nxt[N*2],l,f[N];
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
int dis(int a,int b)
{
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}
bool cmp(int a,int b)
{
	return id[a]<id[b];
}
void addedge(int u,int v)
{
	Adj[++l]=v;
	Nxt[l]=Head[u];
	Head[u]=l;
	Adj[++l]=u;
	Nxt[l]=Head[v];
	Head[v]=l;
}
void dzx(int x,int dad)
{
	if(s[x])
		f[x]=x;
	else
		f[x]=0;
	for(int y=Head[x],a,b;y;y=Nxt[y])
		if(Adj[y]!=dad)
		{
			dzx(Adj[y],x);
			if(f[Adj[y]]&&(!f[x]||1ll*(a=dis(f[Adj[y]],x)-1)/s[f[Adj[y]]]<1ll*(b=dis(f[x],x)-1)/s[f[x]]||1ll*(a=dis(f[Adj[y]],x)-1)/s[f[Adj[y]]]==1ll*(b=dis(f[x],x)-1)/s[f[x]]&&h[f[Adj[y]]]<h[f[x]]))
				f[x]=f[Adj[y]];
		}
	if(s[x])
		f[x]=x;
}
void phh(int x,int dad,int u)
{
	int a,b;
	if(u)
	{
		if(u&&(!f[x]||1ll*(a=dis(u,x)-1)/s[u]<1ll*(b=dis(f[x],x)-1)/s[f[x]]||1ll*(a=dis(u,x)-1)/s[u]==1ll*(b=dis(f[x],x)-1)/s[f[x]]&&h[u]<h[f[x]]))
			f[x]=u;
	}
	if(s[x])
		f[x]=x;
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad)
			phh(Adj[y],x,f[x]);
	Head[x]=0;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	dfs(1,-1);
	tp[1]=1;
	i=0;
	Dfs(1,-1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&K,&m);
		num=0;
		for(int i=1,j,k;i<=K;++i){scanf("%d%d",&j,&k);s[j]=k;h[j]=i;t[++num]=j;}
		for(i=1;i<=m;++i)
		{
			scanf("%d",&j);
			g[i]=t[++num]=j;
		}
		t[++num]=1;
		sort(t+1,t+1+num,cmp);
		cnt=0;
		for(i=1;i<=num;i=j)
		{
			for(j=i;j<=num&&t[i]==t[j];++j);
			p[++cnt]=t[i];
		}
		if(cnt==1)
		{
			puts("1");
			for(i=1;i<=cnt;++i)
				s[p[i]]=0;
			continue;
		}
		l=0;
		stk[1]=p[1],stk[2]=p[2];
		top=2;
		for(i=3;i<=cnt;++i)
		{
			while(top>1&&dep[lca(stk[top],p[i])]<=dep[stk[top-1]])
			{
				addedge(stk[top-1],stk[top]);
				--top;
			}
			if((j=lca(p[i],stk[top]))==stk[top])
				stk[++top]=p[i];
			else
			{
				addedge(j,stk[top]);
				stk[top]=j;
				stk[++top]=p[i];
			}
		}
		while(top>1)
		{
			addedge(stk[top-1],stk[top]);
			--top;
		}
		dzx(1,-1);
		phh(1,-1,0);
		for(i=1;i<=m;++i)
			printf("%d ",h[f[g[i]]]);
		puts("");
		for(i=1;i<=cnt;++i)
			s[p[i]]=0;
	}
	return 0;
}