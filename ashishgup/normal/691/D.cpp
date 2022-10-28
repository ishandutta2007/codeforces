#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int p[N], vis[N];
vector<int> g[N];
vector<int> v;

void dfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	v.push_back(k);
	for(auto it:g[k])
		dfs(it);
} 

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		v.clear();
		dfs(i);
		sort(v.begin(), v.end());
		vector<int> v2;
		for(auto it:v)
			v2.push_back(p[it]);
		sort(v2.begin(), v2.end());
		reverse(v2.begin(), v2.end());
		for(int i=0;i<v.size();i++)
			p[v[i]]=v2[i];
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
}