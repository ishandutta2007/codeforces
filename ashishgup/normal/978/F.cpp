#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int a[N], vis[N], ans[N];
map<int, vector<int> > store;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		store[a[i]].push_back(i);
	}
	int cur=0;
	for(auto it:store)
	{
		for(auto j:it.second)
			ans[j]=cur;
		cur+=it.second.size();
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(a[v]);
		g[v].push_back(a[u]);
	}	
	for(int i=1;i<=n;i++)
	{
		if(g[i].size())
		{
			sort(g[i].begin(), g[i].end());
			auto it=lower_bound(g[i].begin(), g[i].end(), a[i]);
			int idx=it-g[i].begin();
			ans[i]-=idx;
		}
		cout<<ans[i]<<" ";
	}
	return 0;
}