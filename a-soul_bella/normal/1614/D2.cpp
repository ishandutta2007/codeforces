#include <bits/stdc++.h>
using namespace std;
int N=20000000;
int mn[20000005],cnt[20000005];
long long dp[20000005];
int p[20],qwq=0,c[20];
inline void dfs(int now,int x)
{
	if(now==qwq+1)
	{
		++cnt[x];
		return ;
	}
	for(int i=0;i<=c[now];i++)
		dfs(now+1,x),x*=p[now];
}
signed main()
{
	for(int i=2;i<=N;i++)
	{
		if(!mn[i])
		{
			for(int j=i;j<=N;j+=i)
				if(!mn[j]) mn[j]=i;
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		qwq=0;
		while(x!=1)
		{
			c[++qwq]=0;
			int t=p[qwq]=mn[x];
			while(x%t==0) x/=t,++c[qwq];
		}
		dfs(1,1);
	}
	for(signed x=N;x>=2;x--)
	{
		signed now=x;
		dp[x]=max(dp[x],1ll*cnt[x]*x);
		while(now!=1)
		{
			signed X=x/mn[now];
			dp[X]=max(dp[X],dp[x]+1ll*(cnt[X]-cnt[x])*X);
			now/=mn[now];
		}
	}
	cout << dp[1];
	return 0;
}