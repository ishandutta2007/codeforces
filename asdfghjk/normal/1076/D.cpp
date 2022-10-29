#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=300005;
typedef long long ll;
struct node
{
	int h;
	ll d;
}t;
bool operator <(node a,node b)
{
	return a.d>b.d;
}
priority_queue<node> q;
int n,m,K,i,j,k,head[N],adj[N*2],nxt[N*2],len[N*2],fa[N],Head[N],Adj[N*2],Nxt[N*2];
ll dis[N];
bool v[N],vis[N];
void dfs(int x)
{
	for(int y=Head[x];y;y=Nxt[y])
	{
		dfs(Adj[y]);
		if(K>0)
		{
			--K;
			vis[(fa[Adj[y]]+1)/2]=true;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&j,&k,&len[i*2]);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		len[i*2-1]=len[i*2];
	}
	printf("%d\n",K);
	K=m-K;
	for(i=2;i<=n;++i)
		dis[i]=1ll<<60;
	q.push((node){1,0});
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(v[t.h])
			continue;
		v[t.h]=true;
		for(i=head[t.h];i;i=nxt[i])
			if(t.d+len[i]<dis[adj[i]])
			{
				dis[adj[i]]=t.d+len[i];
				fa[adj[i]]=i&1?i+1:i-1;
				q.push((node){adj[i],dis[adj[i]]});
			}
	}
	memset(v,false,sizeof(v));
	for(i=2;i<=n;++i)
		v[(fa[i]+1)/2]=true;
	if(K<=m-(n-1))
	{
		for(i=1;i<=m&&K;++i)
			if(!v[i])
			{
				vis[i]=true;
				--K;
				if(K==0)
					break;
			}
	}
	else
	{
		for(i=2;i<=n;++i)
		{
			Adj[i-1]=i;
			Nxt[i-1]=Head[adj[fa[i]]];
			Head[adj[fa[i]]]=i-1;
		}
		K-=m-(n-1);
		for(i=1;i<=m;++i)
			if(!v[i])
				vis[i]=true;
		dfs(1);
	}
	for(i=1;i<=m;++i)
		if(!vis[i])
			printf("%d ",i);
	return 0;
}