#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=50005;
int n,m,i,j,k,l,head[N],adj[N],nxt[N],rhead[N],radj[N],rnxt[N],id[N],col[N],cnt,size[N],Head[N],Adj[N],Nxt[N],d[N],f[1005][1005],q[N],bg,ed,pt[N],ans[N],head_[2*N],adj_[2*N],nxt_[2*N],len,dis[N],g[N];
bool v[N];
void dfs(int x)
{
	v[x]=true;
	for(int y=head[x];y;y=nxt[y])
		if(!v[adj[y]])
			dfs(adj[y]);
	id[++j]=x;
}
void rdfs(int x)
{
	col[x]=cnt;
	++size[cnt];
	for(int y=rhead[x];y;y=rnxt[y])
		if(!col[radj[y]])
			rdfs(radj[y]);
}
void Addedge(int u,int v,int w)
{
	adj_[++len]=v;
	nxt_[len]=head_[u];
	head_[u]=len;
	g[len]=w;
	//printf("%d %d %d\n",u,v,w);
}
bool spfa(int x)
{
	if(f[col[1]][x]==-1||f[x][col[n]]==-1)
		return false;
	v[x]=true;
	for(int y=head_[x];y;y=nxt_[y])
		if(dis[x]+g[y]>dis[adj_[y]])
		{
			dis[adj_[y]]=dis[x]+g[y];
			if(v[adj_[y]]||spfa(adj_[y]))
				return true;
		}
	return v[x]=false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i]=k;
		nxt[i]=head[j];
		head[j]=i;
		radj[i]=j;
		rnxt[i]=rhead[k];
		rhead[k]=i;
	}
	for(i=1,j=0;i<=n;++i)
		if(!v[i])
			dfs(i);
	for(;j>=1;--j)
		if(!col[id[j]])
		{
			++cnt;
			rdfs(id[j]);
		}
	for(i=1;i<=m;++i)
		if(col[radj[i]]!=col[adj[i]])
		{
			Adj[++l]=col[adj[i]];
			Nxt[l]=Head[col[radj[i]]];
			Head[col[radj[i]]]=l;
			pt[i]=l;
		}
	for(i=1;i<=l;++i)
		++d[Adj[i]];
	for(i=1;i<=cnt;++i)
		if(d[i]==0)
			q[++ed]=i;
	bg=1;
	while(bg<=ed)
	{
		for(i=Head[q[bg]];i;i=Nxt[i])
		{
			--d[Adj[i]];
			if(!d[Adj[i]])
				q[++ed]=Adj[i];
		}
		++bg;
	}
	for(i=1;i<=cnt;++i)
	{
		for(j=1;j<=cnt;++j)
			f[q[i]][j]=-1;
		f[q[i]][q[i]]=0;
		for(j=i;j<=cnt;++j)
			if(f[q[i]][q[j]]!=-1)
				for(k=Head[q[j]];k;k=Nxt[k])
					f[q[i]][Adj[k]]=max(f[q[i]][Adj[k]],f[q[i]][q[j]]+1);
	}
	if(f[col[1]][col[n]]==-1)
	{
		printf("No");
		return 0;
	}
	for(i=1;i<=cnt;++i)
		if(f[col[1]][i]!=-1&&f[i][col[n]]!=-1&&size[i]>1)
		{
			printf("No");
			return 0;
		}
	for(i=1;i<=m;++i)
		if(!pt[i])
			ans[i]=1;
		else if(f[col[1]][col[radj[i]]]==-1||f[col[adj[i]]][col[n]]==-1)
			ans[i]=1;
		else
		{
			Addedge(col[radj[i]],col[adj[i]],1);
			Addedge(col[adj[i]],col[radj[i]],-2);
		}
	for(i=1;i<=cnt;++i)
		v[i]=false;
	for(i=1;i<=cnt;++i)
		if(f[col[1]][i]!=-1&&f[i][col[n]]!=-1&&spfa(i))
		{
			printf("No");
			return 0;
		}
	puts("Yes");
	for(i=1;i<=m;++i)
	{
		if(ans[i])
			printf("%d\n",ans[i]);
		else
			printf("%d\n",dis[col[adj[i]]]-dis[col[radj[i]]]);
	}
	return 0;
}