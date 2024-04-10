#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=200005;
int n,m,i,j,head[N],Next[N*2],adj[N*2],dp[N][2],ans,k,a[N],t,u,v;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	dp[i][0]=dp[i][1]=0;
	if(a[i]==1)
		dp[i][1]=(1<<29);
	if(a[i]==2)
		dp[i][0]=(1<<29);
	int j,mx[2];
	mx[0]=mx[1]=0;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
		{
			dfs(adj[j],i);
			if(dp[i][0]<min(dp[adj[j]][0],dp[adj[j]][1]+1))
			{
				dp[i][0]=min(dp[adj[j]][0],dp[adj[j]][1]+1);
				mx[0]=adj[j];
			}
			if(dp[i][1]<min(dp[adj[j]][0]+1,dp[adj[j]][1]))
			{
				dp[i][1]=min(dp[adj[j]][0]+1,dp[adj[j]][1]);
				mx[1]=adj[j];
			}
		}
	int s1=0,s2=0;
	s1=dp[i][0];
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa&&adj[j]!=mx[0])
			s1=max(s1,dp[i][0]+min(dp[adj[j]][0],dp[adj[j]][1]+1));
	s2=dp[i][1];
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa&&adj[j]!=mx[1])
			s2=max(s2,dp[i][1]+min(dp[adj[j]][0]+1,dp[adj[j]][1]));
	ans=max(ans,min(s1,s2));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		k=ans=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			head[i]=0;
		}
		for(i=1;i<n;++i)
		{
			scanf("%d %d",&u,&v);
			Push(u,v);
			Push(v,u);
		}
		dfs(1,0);
		printf("%d\n",(ans+1)/2+1);
	}
}