#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

struct data
{
	int v, l, r;
	
	data() {}

	data(int v, int l, int r): v(v), l(l), r(r) {}
};

int n, m;
int dist[N], vis[N];
set<int> s;
vector<data> g[N];

int work(int x)
{
	for(int i=1;i<=n;i++)
		dist[i]=0, vis[i]=0;
	dist[1]=1e9;
	priority_queue<pair<int, int>, vector<pair<int, int> > > pq;
	pq.push({dist[1], 1});
	while(!pq.empty())
	{
		int node=pq.top().second;
		int curd=pq.top().first;
		pq.pop();
		if(vis[node])
			continue;
		vis[node]=1;
		for(auto &it:g[node])
		{
			if(x>=it.l && x<=it.r && min(it.r, curd) > dist[it.v])
			{
				dist[it.v]=min(it.r, curd);
				pq.push({dist[it.v], it.v});
			}
		}
	}
	return dist[n];
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a, b, l, r;
		cin>>a>>b>>l>>r;
		g[a].push_back(data(b, l, r));
		g[b].push_back(data(a, l, r));
		s.insert(l);
		s.insert(r);
	}	
	int ans=0;
	for(auto &it:s)
		ans=max(ans, work(it) - it + 1);
	if(ans)
		cout<<ans;
	else
		cout<<"Nice work, Dima!";
	return 0;
}