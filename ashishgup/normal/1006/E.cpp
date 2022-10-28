#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, q;
int ans[N], store[N];
vector<int> g[N];
vector<pair<int, int> > queries[N];
vector<int> v;

void dfs(int k)
{
	store[k]=v.size();
	v.push_back(k);
	for(auto it:g[k])
		dfs(it);
	for(auto it:queries[k])
	{
		int idx=it.first-1 + store[k];
		if(idx>=v.size())
			ans[it.second]=-1;
		else
			ans[it.second]=v[idx];
	}
}

int32_t main()
{
	IOS;
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		int par;
		cin>>par;
		g[par].push_back(i);
	}
	for(int i=1;i<=q;i++)
	{
		int u, k;
		cin>>u>>k;
		queries[u].push_back({k, i});
	}
	dfs(1);
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}