#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], b[N], vis[N];
set<int> s1, s2;
vector<int> g[N];

void dfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	s1.insert(k);
	s2.insert(a[k]);
	for(auto &it:g[k])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		int u=i;
		int v=i+b[i];
		if(v>=1 && v<=n)
			g[u].push_back(v), g[v].push_back(u);
		v=i-b[i];
		if(v>=1 && v<=n)
			g[u].push_back(v), g[v].push_back(u);
	}	
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		s1.clear();
		s2.clear();
		dfs(i);
		if(s1!=s2)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}