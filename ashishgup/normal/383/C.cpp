#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, tim=0;
int a[N], level[N], discovery[N], start[N], finish[N];
vector<int> g[N];
int bit[N][2];

void dfs(int k, int par, int lvl)
{
	level[k]=lvl%2;
	discovery[++tim]=k;
	start[k]=tim;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
	finish[k]=tim;
}

void update(int i, int id, int k)
{
	while(i<=n)
	{
		bit[i][id]+=k;
		i+=(i&(-i));
	}
}

int prefsum(int i, int id)
{
	int ans=0;
	while(i>0)
	{
		ans+=bit[i][id];
		i-=(i&(-i));
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1, 1);
	for(int i=1;i<=m;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int x, val;
			cin>>x>>val;
			int curlvl=level[x];
			update(start[x], curlvl, val);
			update(finish[x]+1, curlvl, -1*val);
			update(start[x], curlvl^1, -1*val);
			update(finish[x]+1, curlvl^1, val);   
		}
		else
		{
			int x;
			cin>>x;
			int ans=a[x] + prefsum(start[x], level[x]);
			cout<<ans<<endl;
		}
	}
	return 0;
}