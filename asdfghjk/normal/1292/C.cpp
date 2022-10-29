#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=3005;
int n,i,j,k,head[N],adj[N*2],nxt[N*2],size[N],dep[N];
long long f[N][N],ans;
bool v[N][N];
void dfs(int x,int dad)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dep[adj[y]]=dep[x]+1;
			dfs(adj[y],x);
			size[x]+=size[adj[y]];
		}
}
long long work(int x1,int x2,int dad1,int dad2)
{
	if(v[x1][x2])
		return f[x1][x2];
	f[x1][x2]=0;
	for(int y=head[x1];y;y=nxt[y])
		if(adj[y]!=dad1)
			f[x1][x2]=max(f[x1][x2],work(adj[y],x2,x1,dad2)+(dep[adj[y]]>dep[x1]?size[adj[y]]:n-size[x1])*(dep[x2]>dep[dad2]?size[x2]:n-size[dad2]));
	for(int y=head[x2];y;y=nxt[y])
		if(adj[y]!=dad2)
			f[x1][x2]=max(f[x1][x2],work(x1,adj[y],dad1,x2)+(dep[adj[y]]>dep[x2]?size[adj[y]]:n-size[x2])*(dep[x1]>dep[dad1]?size[x1]:n-size[dad1]));
	v[x1][x2]=v[x2][x1]=true;
	return f[x2][x1]=f[x1][x2];
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
	for(i=1;i<n;++i)
		ans=max(ans,work(adj[i*2-1],adj[i*2],adj[i*2],adj[i*2-1])+(dep[adj[i*2]]>dep[adj[i*2-1]]?size[adj[i*2]]*(n-size[adj[i*2]]):size[adj[i*2-1]]*(n-size[adj[i*2-1]])));
	printf("%lld",ans);
	return 0;
}