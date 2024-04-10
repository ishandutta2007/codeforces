#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int vis[N];
set<int> cur;
vector<int> ans;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cur.insert(1);
	while(!cur.empty())
	{
		int node=*cur.begin();
		cur.erase(node);
		vis[node]=1;
		ans.push_back(node);
		for(auto &it:g[node])
		{
			if(!vis[it])
				cur.insert(it);
		}
	}
	for(auto &it:ans)
		cout<<it<<" ";
	return 0;
}