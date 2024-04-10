#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=500005;
int n,i,j,k,head[N],adj[N],nxt[N],v[N],d[N];
void dfs(int x,int col)
{
	for(;head[x];head[x]=nxt[head[x]])
	{
		if(v[(head[x]+1)/2])
			continue;
		v[(head[x]+1)/2]=(head[x]&1?col:3-col);
		dfs(adj[head[x]],col);
		return;
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&j,&k);
		k+=200000;
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	for(i=1;i<=400000;++i)
		while(head[i])
		{
			dfs(i,1);
			dfs(i,2);
		}
	for(i=1;i<=n;++i)
		printf("%c",v[i]==1?'b':'r');
	return 0;
}