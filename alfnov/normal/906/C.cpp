#include<bits/stdc++.h>
using namespace std;
int g[25],dp[1<<22],p[1<<22],p2[1<<22];
void print(int x)
{
	if(x==0)return;
	cout<<p2[x]<<" ";
	print(p[x]);
}
int main()
{
	int n,m,flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)g[i]=1<<i-1;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u]|=1<<v-1;
		g[v]|=1<<u-1;
	}
	for(int i=1;i<=n;i++)if(g[i]!=(1<<n)-1)flag=1;
	if(flag==0)
	{
		cout<<0<<endl;
		return 0;
	}
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)dp[g[i]]=1,p2[g[i]]=i;
	for(int i=0;i<(1<<n);i++)for(int j=1;j<=n;j++)if(i&(1<<j-1))
		if(dp[i|g[j]]>dp[i]+1)
		{
			dp[i|g[j]]=dp[i]+1;
			p[i|g[j]]=i,p2[i|g[j]]=j;
		}
	cout<<dp[(1<<n)-1]<<endl;
	print((1<<n)-1);
	return 0;
}