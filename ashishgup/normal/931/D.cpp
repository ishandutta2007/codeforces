#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int level[N];
vector<int> g[N];

void dfs(int k, int par, int lvl)
{
	level[lvl]++;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int p;
		cin>>p;
		g[p].push_back(i);
		g[i].push_back(p);
	}
	dfs(1, 1, 1);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=level[i]%2;
	cout<<ans;
	return 0;
}