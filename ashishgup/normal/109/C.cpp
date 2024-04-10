#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, sz=0, ans=0;
int vis[N], comp[N];
vector<int> g[N];
vector<int> v;

bool lucky(int x)
{
	while(x>0)
	{
		int dig=x%10;
		if(dig!=4 && dig!=7)
			return 0;
		x/=10;
	}
	return 1;
}

void dfs(int u)
{
	if(vis[u])
		return;
	v.push_back(u);
	vis[u]=1;
	sz++;
	for(auto &it:g[u])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		if(!lucky(w))
			g[u].push_back(v), g[v].push_back(u);
	}	
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			sz=0;
			v.clear();
			dfs(i);
			for(auto &it:v)
				comp[it]=sz;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int others=n-comp[i];
		ans+=others*(others-1);
	}
	cout<<ans;
	return 0;
}