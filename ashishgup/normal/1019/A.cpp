#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3005;

int n, m, ans=1e18;
int p[N], c[N], f[N];
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>c[i];
		f[p[i]]++;
		g[p[i]].push_back(c[i]);
	}
	for(int i=2;i<=m;i++)
	{
		if(g[i].size())
		{
			sort(g[i].begin(), g[i].end());
			for(int j=1;j<g[i].size();j++)
			{
				g[i][j]+=g[i][j-1];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cur=0, taken=f[1];
		vector<int> v;
		for(int j=2;j<=m;j++)
		{
			int totake=max(0LL, f[j]-(i-1));
			if(totake>0)
				cur+=g[j][totake-1];
			taken+=totake;
			for(int k=totake;k<(int)g[j].size();k++)
				v.push_back(g[j][k]-((k>0)?g[j][k-1]:0));
		}
		if(v.size())
			sort(v.begin(), v.end());
		for(int j=0;j<i-taken;j++)
			cur+=v[j];
		ans=min(ans, cur);
	}
	cout<<ans;
	return 0;
}