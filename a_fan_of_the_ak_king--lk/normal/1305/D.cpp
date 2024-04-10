#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=200005,E=262144;
#define inf 2147483647
int n,i,j,t,a,b,m,u[N],v[N],d[2005],vis[2005],p,k;
int head[N],Next[N],adj[N];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int p)
{
	if(vis[i]==1||i==p)
		return;
	vis[i]=1;
	int j;
	for(j=head[i];j!=0;j=Next[j])
		dfs(adj[j],p);
}
int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u[i],&v[i]);
		Push(u[i],v[i]);
		Push(v[i],u[i]);
	}
	for(i=1;;++i)
	{
		memset(d,0,sizeof(d));
		for(j=1;j<n;++j)
			if(vis[u[j]]==0&&vis[v[j]]==0)
				++d[u[j]],++d[v[j]];
		a=b=0;
		for(j=1;j<=n;++j)
			if(d[j]==1)
				if(a==0)
					a=j;
				else
					b=j;
		if(b==0)
		{
			for(i=1;i<=n;++i)
				if(vis[i]==0)
					a=i;
			printf("! %d",a);
			return 0;
		}
		printf("? %d %d\n",a,b);
		fflush(stdout);
		scanf("%d",&p);
		dfs(a,p);
		dfs(b,p);
	}
}