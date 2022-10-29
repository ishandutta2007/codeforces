#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > v[300005];
long long dp[300005],ans;
int a[300005];
void dfs(int node,int p)
{
	long long mx=0,smx=0;
	for (auto u:v[node])
	{
		if (u.first!=p)
		{
			dfs(u.first,node);
			long long tmp=dp[u.first]-u.second;
			if (tmp>=mx)
			{
				smx=mx;
				mx=tmp;
			}
			else if (tmp>=smx)
			smx=tmp;
		}
	}
	dp[node]=mx+a[node];
	ans=max(ans,mx+smx+a[node]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	dfs(1,0);
	printf("%I64d",ans);
}