#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, k, d;
int vis[N], police[N];
queue<int> q;
vector<pair<int, int> > g[N];
set<int> ans;

int32_t main()
{
	IOS;
	cin>>n>>k>>d;
	for(int i=1;i<=k;i++)
	{
		int v;
		cin>>v;
		q.push(v);
		police[v]=v;
		vis[v]=1;
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:g[node])
		{
			if(vis[it.first])
			{
				if(police[it.first]!=police[node])
					ans.insert(it.second);
				continue;
			}
			vis[it.first]=1;	
			police[it.first]=police[node];
			q.push(it.first);
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}