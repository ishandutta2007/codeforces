#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e6+5;

int n, q;
int a[N], ans[N], sieve[N], prime[N];
vector<int> g[N];
vector<pair<int, int> > v[N];

void precompute()
{
	fill(sieve, sieve+N, 1);
	for(int i=2;i<N;i++)
	{
		if(sieve[i])
		{
			for(int j=1;i*j<N;j++)
			{
				sieve[i*j]=0;
				prime[i*j]=i;
			}
		}
	}
}

void dfs(int k, int par, int lvl)
{
	int curlvl=0, storeans=-1;
	int cur=a[k];
	while(prime[cur])
	{
		if(v[prime[cur]].size())
		{
			if(v[prime[cur]].back().second>curlvl)
			{
				curlvl=v[prime[cur]].back().second;
				storeans=v[prime[cur]].back().first;
			}
		}
		cur/=prime[cur];
	}
	ans[k]=storeans;
	cur=a[k];
	while(prime[cur])
	{
		v[prime[cur]].push_back({k, lvl});
		cur/=prime[cur];
	}
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
	cur=a[k];
	while(prime[cur])
	{
		v[prime[cur]].pop_back();
		cur/=prime[cur];
	}
}

int32_t main()
{
	IOS;
	precompute();
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 1);
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int v;
			cin>>v;
			cout<<ans[v]<<endl;
		}
		else
		{
			int v, val;
			cin>>v>>val;
			a[v]=val;
			dfs(1, 0, 1);
		}
	}
	return 0;    
}