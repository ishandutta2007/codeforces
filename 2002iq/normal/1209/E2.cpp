#include <bits/stdc++.h>
using namespace std;
int n,m,dp[15][(1<<12)],mem[2005][(1<<12)];
deque<int> arr[2005];
int get(int c,int mask)
{
	if (mem[c][mask]!=-1)
	return mem[c][mask];
	int ret=0;
	for (int i=0;i<n;i++)
	{
		arr[c].push_front(arr[c].back());
		arr[c].pop_back();
		int cur=0;
		for (int j=0;j<n;j++)
		{
			if (mask&(1<<j))
			cur+=arr[c][j];
		}
		ret=max(ret,cur);
	}
	return mem[c][mask]=ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++)
		arr[i].resize(n);
		vector<pair<int,int> > v;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				scanf("%d",&arr[j][i]);
				v.push_back({arr[j][i],j});
			}
		}
		sort(v.begin(),v.end(),greater<pair<int,int> >());
		set<int> imp;
		for (int i=0;i<v.size() && imp.size()!=n;i++)
		imp.insert(v[i].second);
		vector<int> col(imp.begin(),imp.end());
		for (int i=0;i<=col.size();i++)
		{
			for (int j=0;j<(1<<n);j++)
			dp[i][j]=-1e9;
		}
		dp[0][(1<<n)-1]=0;
		memset(mem,-1,sizeof(mem));
		for (int i=0;i<col.size();i++)
		{
			for (int j=0;j<(1<<n);j++)
			{
				dp[i+1][j]=dp[i][j];
				for (int k=j;k;k=((k-1)&j))
				dp[i+1][(j^k)]=max(dp[i+1][(j^k)],dp[i][j]+get(col[i],k));
			}
		}
		printf("%d\n",dp[col.size()][0]);
	}
}