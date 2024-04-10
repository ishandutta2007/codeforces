#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, ans=0;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int cur;
			cin>>cur;
			g[i].push_back(cur);
		}
		sort(g[i].begin(), g[i].end());
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j+1<g[i].size();j++)
		{
			int l=g[i][j];
			int r=g[i][j+1];
			int lidx=(i-1+n)%n;
			int left=upper_bound(g[lidx].begin(), g[lidx].end(), r) - lower_bound(g[lidx].begin(), g[lidx].end(), l);
			int ridx=(i+1)%n;
			int right=upper_bound(g[ridx].begin(), g[ridx].end(), r) - lower_bound(g[ridx].begin(), g[ridx].end(), l);
			ans+=(left!=right);
		}
	}
	cout<<ans;
	return 0;
}