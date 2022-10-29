#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=500005;
int n,i,j,k,dep[N],size[N],son[N],head[N],adj[N],nxt[N],mx[5000005],sum[N],ans[N],id;
char c[N];
void dfs(int x)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
	{
		dep[adj[y]]=dep[x]+1;
		sum[adj[y]]=sum[x]^(1<<(c[y]-'a'));
		dfs(adj[y]);
		size[x]+=size[adj[y]];
		if(!son[x]||size[adj[y]]>size[son[x]])
			son[x]=adj[y];
	}
}
void dzx(int x)
{
	ans[id]=max(ans[id],dep[x]+mx[sum[x]]-2*dep[id]);
	for(int y=0;y<22;++y)
		ans[id]=max(ans[id],dep[x]+mx[sum[x]^(1<<y)]-2*dep[id]);
	for(int y=head[x];y;y=nxt[y])
		dzx(adj[y]);
}
void phh(int x)
{
	mx[sum[x]]=max(mx[sum[x]],dep[x]);
	for(int y=head[x];y;y=nxt[y])
		phh(adj[y]);
}
void tk(int x)
{
	mx[sum[x]]=-(1<<30);
	for(int y=head[x];y;y=nxt[y])
		tk(adj[y]);
}
void work(int x)
{
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=son[x])
		{
			work(adj[y]);
			tk(adj[y]);
			ans[x]=max(ans[x],ans[adj[y]]);
		}
	if(son[x])
	{
		work(son[x]);
		ans[x]=max(ans[x],ans[son[x]]);
	}
	id=x;
	ans[id]=max(ans[id],dep[x]+mx[sum[x]]-2*dep[id]);
	for(int y=0;y<22;++y)
		ans[id]=max(ans[id],dep[x]+mx[sum[x]^(1<<y)]-2*dep[id]);
	mx[sum[x]]=max(mx[sum[x]],dep[x]);
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=son[x])
		{
			id=x;
			dzx(adj[y]);
			phh(adj[y]);
		}
}
int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;++i)
	{
		scanf("%d %c",&j,&c[i-1]);
		adj[i-1]=i;
		nxt[i-1]=head[j];
		head[j]=i-1;
	}
	for(i=0;i<=(1<<22);++i)
		mx[i]=-(1<<30);
	sum[1]=0;
	dfs(1);
	work(1);
	for(i=1;i<=n;++i)
		printf("%d ",max(0,ans[i]));
	return 0;
}