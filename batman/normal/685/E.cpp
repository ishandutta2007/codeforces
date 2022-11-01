#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001)
#define M ((ll)200*1000+10)

ll n,m,q,dp[N][N],ans[M];
pair <ll,ll> ed[M];
vector <pair<pair<ll,ll>,pair<ll,ll> > > qu[M];

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	memset(dp,31,sizeof dp);
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&ed[i].first,&ed[i].second);
	for(int i=0;i<q;i++)
	{
		ll l,r,s,t;
		scanf("%d%d%d%d",&l,&r,&s,&t);
		qu[l].push_back({{r,i},{s,t}});
	}
	for(int i=m;i>=1;i--)
	{
		ll v=ed[i].first,u=ed[i].second;
		for(int j=1;j<=n;j++)
			dp[v][j]=dp[u][j]=min(dp[v][j],dp[u][j]);
		dp[u][v]=dp[v][u]=i;
		for(auto u:qu[i])ans[u.first.second]=(dp[u.second.first][u.second.second]<=u.first.first);
	}
	for(int i=0;i<q;i++)
	{
		if(ans[i])printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}