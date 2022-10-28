#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, ans=0;
int s[N], r[N], best[N];
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>r[i];
		g[s[i]].push_back(r[i]);
	}	
	for(int i=1;i<=m;i++)
	{
		if(g[i].size())
			sort(g[i].rbegin(), g[i].rend());
	}
	for(int i=1;i<=m;i++)
	{
		int cur=0;
		for(int j=0;j<g[i].size();j++)
		{
			cur+=g[i][j];
			if(cur<0)
				break;
			best[j+1]+=cur;
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans, best[i]);
	cout<<ans;
	return 0;
}