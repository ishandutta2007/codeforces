#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m, h, t;
int a[105], b[105], deg[N], taken[N];
pair<int, int> edges[N];
unordered_set<int> g[N];

void check(int idx, int u, int v)
{
	taken[u]=idx;
	taken[v]=idx;
	int curh=h, curt=t;
	if(deg[u]<curh+1 || deg[v]<curt+1)
		return;
	for(auto it:g[u])
	{
		if(curh==0)
			break;
		if(deg[v]<curt+curh+1&&g[v].find(it)!=g[v].end())
			continue;
		if(taken[it]!=idx)
		{
			a[curh]=it;
			taken[it]=idx;
			curh--;
		}
	} 
	for(auto it:g[u])
	{
		if(curh==0)
			break;
		if(taken[it]!=idx)
		{
			a[curh]=it;
			taken[it]=idx;
			curh--;
		}
	}
	if(curh)
		return;
	for(auto it:g[v])
	{
		if(!curt)
			break;
		if(taken[it]!=idx)
		{
			b[curt]=it;
			taken[it]=idx;
			curt--;
		}
	}
	if(curt)
		return;
	cout<<"YES"<<endl;
	cout<<u<<" "<<v<<endl;
	for(int i=1;i<=h;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<=t;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	exit(0);
}

int32_t main()
{
	IOS;
	cin>>n>>m>>h>>t;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
		edges[i].first=u;
		edges[i].second=v;
		deg[u]++, deg[v]++;
	}
	for(int i=1;i<=m;i++)
	{
		check(2*i, edges[i].first, edges[i].second);
		check(2*i+1, edges[i].second, edges[i].first);
	}
	cout<<"NO";
	return 0;
}