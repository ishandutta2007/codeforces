#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;

int n, d, k, node;
int deg[N], maxlvl[N];
vector<int> g[N];

void expand(int u, int lvl)
{
	if(lvl<=0)
		return;
	if(node>=n+1)
		return;
	for(int i=deg[u]+1;i<=k;i++)
	{
		if(node==n+1)
			return;
		g[u].push_back(node);
		g[node].push_back(u);
		deg[node]++;
		int store=node;
		node++;
		expand(store, lvl-1);	
	}
}

int32_t main()
{
	IOS;
	cin>>n>>d>>k;
	for(int i=1;i<=d;i++)
	{
		deg[i]++;
		deg[i+1]++;
		g[i].push_back(i+1);
		g[i+1].push_back(i);
		maxlvl[i]=min(i-1, d+1-i);
	}
	node=d+2;
	for(int i=2;i<=d;i++)
	{
		expand(i, maxlvl[i]);
	}
	if(node<n+1||node>n+1)
	{
		cout<<"NO";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(deg[i]>k)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			if(it>i)
				cout<<i<<" "<<it<<endl;
		}
	}
	return 0;
}