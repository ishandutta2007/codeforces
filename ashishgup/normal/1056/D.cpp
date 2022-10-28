#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int subtree[N];
vector<int> v;
vector<int> g[N];

void dfs(int k)
{
	subtree[k]=0;
	for(auto &it:g[k])
	{
		dfs(it);
		subtree[k]+=subtree[it];
	}
	if(!g[k].size())
		subtree[k]=1;
	v.push_back(subtree[k]);
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
	}	
	dfs(1);
	sort(v.begin(), v.end());
	int r=-1;
	for(int i=1;i<=n;i++)
	{
		while(r+1<n && v[r+1]<=i)
		{
			cout<<i<<" ";
			r++;
		}
	}
	return 0;
}