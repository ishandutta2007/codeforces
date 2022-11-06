#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int oo=1000000001;
const int V=120;
int a[V],b[V];
int dp[22][1<<20];
int vis[22][1<<20];
char op[30][120];
int n,m,x[30];
int dfs()
{
	memset(dp[m],0,sizeof(dp[m]));
	for(int pos=m-1;pos>=0;pos--)
	{
	    for(int st=0;st<(1<<m);st++)
		if(x[pos]==1)
		{
			dp[pos][st]=-oo;
			for(int i=0;i<m;i++)
			{
				if(st&(1<<i))continue;
				int tmp;
				int ts=(st|(1<<i));
				if(op[pos][0]=='b')
				{
					tmp=dp[pos+1][st];
					dp[pos][st]=max(dp[pos][st],tmp);
					tmp=dp[pos+1][ts];
					dp[pos][st]=max(dp[pos][st],tmp);
				}
				else
				{
					tmp=dp[pos+1][ts]+a[i];
					dp[pos][st]=max(dp[pos][st],tmp);
				}
			}
		}
		else
		{
			dp[pos][st]=oo;
			for(int i=0;i<m;i++)
			{
				if(st&(1<<i))continue;
				int tmp;
				int ts=(st|(1<<i));
				if(op[pos][0]=='b')
				{
					tmp=dp[pos+1][st];
					dp[pos][st]=min(dp[pos][st],tmp);
					tmp=dp[pos+1][ts];
					dp[pos][st]=min(dp[pos][st],tmp);
				}
				else
				{
					tmp=dp[pos+1][ts]-a[i];
					dp[pos][st]=min(dp[pos][st],tmp);
				}
			}
		}
	}
	//printf("%d %d %d\n",pos,st,dp[pos][st]);
	//return dp[pos][st];
	return dp[0][0];
}
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
		sort(b,b+n);
		scanf("%d",&m);
		for(int i=0;i<m;i++)a[i]=b[n-1-i];
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++)
		{
			scanf("%s%d",op[i],&x[i]);
		}
		printf("%d\n",dfs());
	}
}