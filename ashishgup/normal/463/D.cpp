#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";

const int N=1e3+5;

int a[6][N], prev1[N][N], ans[N];
vector<int> g[N];

int dfs(int k)
{
	if(ans[k]!=-1)
		return ans[k];
	ans[k]=1;
	for(auto it:g[k])
	{
		ans[k]=max(ans[k], dfs(it) + 1);
	}
	return ans[k];
}

int main()
{
	IOS;
	int n, k;
	cin>>n>>k;
	memset(ans, -1, sizeof(ans));
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int p=1;p<=n;p++)
		{
			for(int q=p+1;q<=n;q++)
			{
				prev1[a[i][p]][a[i][q]]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(prev1[i][j]==k)
			{
				g[i].push_back(j);
			}
		}
	}
	int finans=0;
	for(int i=1;i<=n;i++)
	{
		finans=max(finans, dfs(i));
	}
	cout<<finans;
}