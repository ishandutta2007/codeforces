#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=-1;
int x[N], y[N], vis[N];
vector<int> gx[N], gy[N];

void dfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	for(auto it:gx[x[k]])
		dfs(it);
	for(auto it:gy[y[k]])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		gx[x[i]].push_back(i);
		gy[y[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans++;
			dfs(i);
		}
	}
	cout<<ans;
	return 0;
}