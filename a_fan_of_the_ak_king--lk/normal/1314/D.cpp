#include<bits/stdc++.h>
using namespace std;
const int N=105,M=998244353,P=1000000007;
typedef long double lb;
int n,m,k,a[1005][1005],i,j,vis[1005],c[1005],t,l0,l1,p0[1005],p1[1005];
long long dp[105][9],ans=1000000000000ll,b[105][105];
long long dfs(int i,int j)
{
	if(j==t)
		return b[i][1];
	if(dp[i][j]<=100000000000ll)
		return dp[i][j];
	int m;
	for(m=1;m<=n;++m)
		if(c[m]==0)
			dp[i][j]=min(dp[i][j],dfs(m,j+1)+b[i][m]);
	return dp[i][j];
}
int main()
{
	cin>>n>>t;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=1000000000000ll;
		}
	int ti=6000;
	t/=2;
	srand(time(0));
	while(ti--)
	{
		for(i=2;i<=n;++i)
			c[i]=rand()%2;
		l0=l1=0;
		for(i=1;i<=n;++i)
			if(c[i])
				p1[++l1]=i;
			else
				p0[++l0]=i;
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				b[i][j]=1000000000000ll;
		for(i=1;i<=n;++i)
			for(j=0;j<=t;++j)
				dp[i][j]=1000000000000ll;
		for(i=1;i<=l0;++i)
			for(j=1;j<=l0;++j)
				for(k=1;k<=l1;++k)
					b[p0[i]][p0[j]]=min(b[p0[i]][p0[j]],1ll*a[p0[i]][p1[k]]+a[p1[k]][p0[j]]);
		ans=min(ans,dfs(1,1));
	}
	cout<<ans;
}