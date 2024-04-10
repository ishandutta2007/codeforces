#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, k, ans=0;
int deg[N], x[N], y[N], store[N], removed[N];
set<pair<int, int> > s, erased;
vector<int> g[N];

void update(int it)
{
	if(!removed[it])
		s.erase({deg[it], it});
	deg[it]--;
	if(!removed[it])
		s.insert({deg[it], it});
}

void work()
{
	while(s.size()>0 && s.begin()->first<k)
	{
		int node=s.begin()->second;
		for(auto &it:g[node])
		{
			if(erased.find({node, it})!=erased.end())
				continue;
			erased.insert({node, it});
			erased.insert({it, node});
			update(it);
		}
		s.erase({deg[node], node});
		removed[node]=1;
		ans--;
	}
}

int32_t main()
{
	cin>>n>>m>>k;
	ans=n;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		deg[x[i]]++;
		deg[y[i]]++;
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	for(int i=1;i<=n;i++)
	{
		s.insert({deg[i], i});
	}
	for(int i=m;i>=1;i--)
	{
		work();
		store[i]=ans;
		if(erased.find({x[i], y[i]})==erased.end())
		{
			update(x[i]);
			update(y[i]);
			erased.insert({x[i], y[i]});
			erased.insert({y[i], x[i]});
		}
	}
	for(int i=1;i<=m;i++)
		cout<<store[i]<<endl;
	return 0;
}