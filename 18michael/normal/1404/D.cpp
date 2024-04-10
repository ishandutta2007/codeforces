#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int num[500002],to[1000002];
bool vis[1000002],u[1000002];
inline void dfs(int x)
{
	if(vis[x])return ;
	u[x]=vis[x]=vis[to[x]]=1,(sum+=x)%=(n<<1),dfs(to[x]<=n? to[x]+n:to[x]-n);
}
int main()
{
	scanf("%d",&n);
	if(!(n&1))
	{
		puts("First");
		for(int i=1;i<=n;++i)printf("%d ",i);
		for(int i=1;i<=n;++i)printf("%d ",i);
		return 0&fflush(stdout);
	}
	puts("Second"),fflush(stdout);
	for(int i=1,x;i<=(n<<1);++i)
	{
		scanf("%d",&x);
		if(!num[x])num[x]=i;
		else to[to[i]=num[x]]=i;
	}
	for(int i=1;i<=(n<<1);++i)if(!vis[i])dfs(i);
	for(int i=1;i<=(n<<1);++i)if(u[i]==!sum)printf("%d ",i);
	return 0&fflush(stdout);
}