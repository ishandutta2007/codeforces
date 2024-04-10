#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int n,K,i,j,k,l,head[N],adj[N],nxt[N],a[N],sz[N],size[N],Head[N],Adj[N],Nxt[N],lt,rt,mid,w,num[N],p[N],mx1[N],mx2[N];
bool v[N];
int find(int x)
{
	return !p[x]?x:p[x]=find(p[x]);
}
void addedge(int u,int v)
{
	//printf("%d %d\n",u,v);
	Adj[++l]=v;
	Nxt[l]=Head[u];
	Head[u]=l;
	Adj[++l]=u;
	Nxt[l]=Head[v];
	Head[v]=l;
}
void dfs(int x,int dad)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dfs(adj[y],x);
			size[x]+=size[adj[y]];
		}
}
void Dfs(int x,int dad)
{
	sz[x]=(a[x]>=mid);
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			Dfs(adj[y],x);
			sz[x]+=sz[adj[y]];
			if(sz[adj[y]]==size[adj[y]]&&a[x]>=mid)
				p[find(adj[y])]=find(x);
		}
}
void dzx(int x,int dad)
{
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			if(a[adj[y]]>=mid&&n-size[adj[y]]==sz[1]-sz[adj[y]]&&find(x)!=find(adj[y]))
				p[find(x)]=find(adj[y]);
			dzx(adj[y],x);
		}
}
void work(int x,int dad)
{
	v[x]=true;
	mx1[x]=mx2[x]=0;
	for(int y=Head[x];y;y=Nxt[y])
		if(a[Adj[y]]>=mid&&Adj[y]!=dad)
		{
			work(Adj[y],x);
			if(mx1[Adj[y]]>mx1[x])
			{
				mx2[x]=mx1[x];
				mx1[x]=mx1[Adj[y]];
			}
			else if(mx1[Adj[y]]>mx2[x])
				mx2[x]=mx1[Adj[y]];
		}
	w=max(w,mx1[x]+mx2[x]+num[x]);
	mx1[x]+=num[x],mx2[x]+=num[x];
}
int main()
{
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
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
	lt=1,rt=1000000;
	while(lt<rt)
	{
		mid=(lt+rt+1)/2;
		for(i=1;i<=n;++i)
			Head[i]=p[i]=num[i]=0,v[i]=false;
		Dfs(1,-1);
		dzx(1,-1);
		for(i=1;i<=n;++i)
			num[find(i)]++;
		l=0;
		for(i=1;i<n;++i)
			if(find(adj[i*2-1])!=find(adj[i*2]))
				addedge(find(adj[i*2-1]),find(adj[i*2]));
		w=0;
		for(i=1;i<=n;++i)
			if(find(i)==i&&a[i]>=mid&&!v[i])
				work(i,-1);
		if(w>=K)
			lt=mid;
		else
			rt=mid-1;
	}
	printf("%d",lt);
	return 0;
}