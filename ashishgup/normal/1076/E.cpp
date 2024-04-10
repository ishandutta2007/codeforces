#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int bit[N], val[N];
vector<int> g[N];
vector<pair<int, int> > q[N];

void update(int idx, int val)
{
	idx=N-1-idx;
	while(idx<N)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	idx=N-1-idx;
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

void dfs(int k, int par, int lvl)
{
	for(auto &it:q[k])
		update(lvl+it.first, it.second);
	val[k]=pref(lvl);
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
	for(auto &it:q[k])	
		update(lvl+it.first, -it.second);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int v, d, x;
		cin>>v>>d>>x;
		d=min(n, d);
		q[v].push_back({d, x});
	}
	dfs(1, 1, 1);
	for(int i=1;i<=n;i++)
		cout<<val[i]<<" ";
	return 0;
}