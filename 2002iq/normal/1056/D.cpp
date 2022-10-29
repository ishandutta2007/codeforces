#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int dp[100005],cnt[100005];
void dfs(int node)
{
	if (v[node].empty())
	dp[node]=1;
	for (int u:v[node])
	{
		dfs(u);
		dp[node]+=dp[u];
	}
	cnt[dp[node]]++;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		v[p].push_back(i);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<cnt[i];j++)
		printf("%d ",i);
	}
}