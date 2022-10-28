#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, ans2=0;
int vis[N], indeg[N], c[N], idx[N];
set<int> v;
vector<int> g[N];
vector<pair<int, int> > ng[N];

bool findLoop(int v) 
{
	if(vis[v]==1)
		return 1;
	if(vis[v]==2)
		return 0;
	vis[v]=1;
	for(auto &it:g[v])
	{
		if(findLoop(it))
			return 1;
	}
	vis[v]=2;
	return 0;
}

bool checkLoop()
{
	fill(vis+1, vis+n+1, 0);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && findLoop(i))
			return 1;
	}
	return 0;
}

int check(int x)
{
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		for(auto &it:ng[i])
		{
			if(c[it.second]>x)
				g[i].push_back(it.first);
		}
	}
	return !checkLoop();
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

void work(int x)
{
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=1;i<=n;i++)
		for(auto &it:g[i])
			indeg[it]++;
	vector<int> topo;
	for(int i=1;i<=n;i++)
	{
		if(!indeg[i])
			pq.push(i);
	}
	while(!pq.empty())
	{
		int u=pq.top();
		pq.pop();
		topo.push_back(u);
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				pq.push(v);
		}
	}
	int ctr=0;
	for(auto &it:topo)
		idx[it]=++ctr;
	for(int i=1;i<=n;i++)
	{
		for(auto &it:ng[i])
		{
			if(c[it.second]<=x && idx[it.first]<idx[i])
				v.insert(it.second);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;	
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v>>c[i];
		ng[u].push_back({v, i});
	}
	int ans=binsearch(0, 1e9);
	check(ans);
	work(ans);
	cout<<ans<<" "<<v.size()<<endl;
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}