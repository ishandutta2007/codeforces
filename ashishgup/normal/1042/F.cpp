#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, dist, ans=1;
vector<int> g[N];

int dfs(int k, int par)
{
	vector<int> v;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		v.push_back(dfs(it, k));
	}
	if(!v.size())
		return 1;
	sort(v.begin(), v.end());
	while(v.size()>1)
	{
		if(v.back() + v[v.size()-2]>dist)
		{
			ans++;
			v.pop_back();
		}
		else
			break;
	}		
	return 1+v.back();
}

int32_t main()
{
	IOS;
	cin>>n>>dist;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root=1;
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()>1)
			root=i;
	}
	dfs(root, root);
	cout<<ans;
	return 0;
}