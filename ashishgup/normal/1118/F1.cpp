//Previous Submission Stuck

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, red=0, blue=0, ans=0;
int a[N], subtree[3][N];
vector<int> g[N];

void dfs(int u, int par)
{
	subtree[a[u]][u]++;
	for(auto &it:g[u])
	{
		if(it==par)
			continue;
		dfs(it, u);
		if(subtree[1][it]==red && subtree[2][it]==0)
			ans++;
		else if(subtree[1][it]==0 && subtree[2][it]==blue)
			ans++;
		for(int j=0;j<=2;j++)
			subtree[j][u]+=subtree[j][it];
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		red+=(a[i]==1);
		blue+=(a[i]==2);
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	cout<<ans;
	return 0;
}