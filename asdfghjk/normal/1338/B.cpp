#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,i,j,k,x,head[N],adj[N*2],nxt[N*2],d[N],dep[N];
bool v[N];
void dfs(int x,int dad)
{
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dep[adj[y]]=dep[x]+1;
			dfs(adj[y],x);
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
		++d[j],++d[k];
	}
	for(i=1;;++i)
		if(d[i]!=1)
			break;
	dfs(i,-1);
	for(i=1,j=0;i<=n;++i)
		if(d[i]==1)
		{
			if(!v[dep[i]%2])
				++j;
			v[dep[i]%2]=true;
		}
	if(j==1)
		printf("1");
	else
		printf("3");
	x=n-1;
	for(i=1;i<=n;++i)
	{
		for(j=head[i],k=0;j;j=nxt[j])
			if(d[adj[j]]==1)
				++k;
		if(k)
			x-=k-1;
	}
	printf(" %d",x);
	return 0;
}