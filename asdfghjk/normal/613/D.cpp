#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const int N=100005,inf=1000000;
int n,q,i,j,k,K,l,head[N],adj[N*2],nxt[N*2],a[N],id[N],s[N],top,Head[N],Adj[N*2],Nxt[N*2],Len[N*2],w[N],num,f[N][2],p[N][20],dep[N];
bool b[N];
set<int> g[N];
bool cmp(int a,int b)
{
	return id[a]<id[b];
}
void dfs(int x,int dad)
{
	id[x]=++i;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dep[adj[y]]=dep[x]+1;
			p[adj[y]][0]=x;
			dfs(adj[y],x);
		}
}
int lca(int a,int b)
{
	int c,d;
	if(dep[a]<dep[b])
		swap(a,b);
	for(c=dep[a]-dep[b],d=0;c;c>>=1,++d)
		if(c&1)
			a=p[a][d];
	if(a==b)
		return a;
	for(c=18;c>=0;--c)
		if(p[a][c]!=p[b][c])
			a=p[a][c],b=p[b][c];
	return p[a][0];
}
void addedge(int u,int v,int w)
{
	//printf("%d %d\n",u,v);
	Adj[++l]=v;
	Nxt[l]=Head[u];
	Head[u]=l;
	Adj[++l]=u;
	Nxt[l]=Head[v];
	Head[v]=l;
	Len[l]=Len[l-1]=w;
}
void work(int x,int dad)
{
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad)
			work(Adj[y],x);
	if(b[x])
	{
		f[x][1]=inf;
		f[x][0]=0;
		for(int y=Head[x];y;y=Nxt[y])
			if(Adj[y]!=dad)
			{
				if(b[Adj[y]])
					f[x][0]+=1+f[Adj[y]][0];
				else
					f[x][0]+=min(f[Adj[y]][1],Len[y]>1?f[Adj[y]][0]+1:inf);
			}
	}
	else
	{
		int z;
		f[x][1]=1;
		for(int y=Head[x];y;y=Nxt[y])
			if(Adj[y]!=dad)
				f[x][1]+=min(f[Adj[y]][0],f[Adj[y]][1]);
		z=0;
		for(int y=Head[x];y;y=Nxt[y])
			if(Adj[y]!=dad)
				z+=min(Len[y]>1?f[Adj[y]][0]+1:inf,f[Adj[y]][1]);
		f[x][1]=min(f[x][1],z);
		f[x][0]=f[x][1];
		for(int y=Head[x];y;y=Nxt[y])
			if(Adj[y]!=dad)
				f[x][0]=min(f[x][0],z-min(Len[y]>1?f[Adj[y]][0]+1:inf,f[Adj[y]][1])+f[Adj[y]][0]);
	}
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
		g[j].insert(k),g[k].insert(j);
	}
	adj[n*2-1]=1;
	nxt[n*2-1]=head[0];
	head[0]=n*2-1;
	adj[n*2]=0;
	nxt[n*2]=head[1];
	head[1]=n*2;
	i=0;
	dfs(0,-1);
	for(i=1;(1<<i)<n;++i)
		for(j=1;j<=n;++j)
			if(p[j][i-1])
				p[j][i]=p[p[j][i-1]][i-1];
	scanf("%d",&q);
	int cnt=0;
	while(q--)
	{++cnt;
		scanf("%d",&K);
		for(i=1;i<=K;++i)
			scanf("%d",a+i);
		if(K<=1)
		{
			puts("0");
			continue;
		}
		sort(a+1,a+1+K,cmp);
		w[num=1]=s[top=1]=0;
		l=0;
		for(i=1;i<=K;++i)
		{
			if(lca(a[i],s[top])==s[top])
			{
				w[++num]=s[++top]=a[i];
				continue;
			}
			while(top>1)
			{
				j=lca(a[i],s[top]);
				if(id[s[top-1]]>id[j])
				{
					addedge(s[top-1],s[top],dep[s[top]]-dep[s[top-1]]);
					--top;
				}
				else if(id[s[top-1]]==id[j])
				{
					addedge(j,s[top],dep[s[top]]-dep[j]);
					--top;
					break;
				}
				else
				{
					addedge(j,s[top],dep[s[top]]-dep[j]);
					w[++num]=s[top]=j;
					break;
				}
			}
			w[++num]=s[++top]=a[i];
		}
		while(top>1)
		{
			addedge(s[top-1],s[top],dep[s[top]]-dep[s[top-1]]);
			--top;
		}
		for(i=1;i<=num;++i)
			b[w[i]]=false;
		for(i=1;i<=K;++i)
			b[a[i]]=true;
		for(i=1;i<=l;++i)
			if(Len[i*2]==1&&b[Adj[i*2-1]]&&b[Adj[i*2]])
				break;
		if(i<=l)
		{
			puts("-1");
			for(i=1;i<=num;++i)
				Head[w[i]]=0;
			for(i=1;i<=K;++i)
				b[a[i]]=false;
			continue;
		}
		work(0,-1);
		printf("%d\n",min(f[0][0],f[0][1]));
		for(i=1;i<=num;++i)
			Head[w[i]]=0;
		for(i=1;i<=K;++i)
			b[a[i]]=false;
	}
	return 0;
}