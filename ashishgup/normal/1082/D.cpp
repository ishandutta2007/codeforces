#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n;
int a[N];
vector<int> g[2];
vector<int> ans[N];

bool comp(int u, int v)
{
	return a[u]>a[v];
}

void add_edge(int u, int v)
{
	ans[u].push_back(v);
	ans[v].push_back(u);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			g[0].push_back(i);
		else
			g[1].push_back(i);
	}
	sort(g[1].begin(), g[1].end(), comp);
	vector<int> leaves;
	while(leaves.size()<2 && g[0].size())
	{
		int cur=g[0].back();
		g[0].pop_back();
		leaves.push_back(cur);
		a[cur]--;
	}
	while(leaves.size()<2 && g[1].size())
	{
		int cur=g[1].back();
		g[1].pop_back();
		leaves.push_back(cur);
		a[cur]--;
	}
	vector<int> path;
	while(g[1].size())
	{
		path.push_back(g[1].back());
		a[g[1].back()]-=2;
		g[1].pop_back();
	}
	for(int i=0;i<path.size();i++)
	{
		if(!g[0].size())
			break;
		int cur=path[i];
		while(a[cur]>0 && g[0].size())
		{
			add_edge(cur, g[0].back());
			a[cur]--;
			g[0].pop_back();
		}
	}
	if(g[0].size())
	{
		cout<<"NO";
		return 0;
	}
	for(int i=0;i+1<path.size();i++)
		add_edge(path[i], path[i+1]);
	add_edge(leaves[0], path[0]);
	add_edge(leaves.back(), path.back());
	int diam=1 + path.size();
	cout<<"YES "<<diam<<endl;
	cout<<n-1<<endl;
	for(int i=1;i<=n;i++)
		for(auto &it:ans[i])
			if(it>i)
				cout<<i<<" "<<it<<endl;
	return 0;
}