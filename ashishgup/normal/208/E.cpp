#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int LG=19;

int n, tim=0;
int starttime[N], endtime[N], storelevel[N];
int par[LG][N];
vector<int> level[N];
vector<int> g[N];

void dfs(int k, int parent, int lvl)
{
	starttime[k]=++tim;
	storelevel[k]=lvl;
	par[0][k]=parent;
	level[lvl].push_back(tim);
	for(auto it:g[k])
	{
		if(it==parent)
			continue;
		dfs(it, k, lvl+1);
	}
	endtime[k]=tim;
}

void precompute()
{
	for(int j=1;j<LG;j++)
	{
		for(int i=1;i<=n;i++)
			par[j][i]=par[j-1][par[j-1][i]];
	}
}

int kth_ancestor(int u, int k)
{
	int cur=u;
	for(int j=20;j>=0;j--)
	{
		if(k & (1LL<<j))
			cur=par[j][cur];
	}
	return cur;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int par;
		cin>>par;
		g[par].push_back(i);
	}
	dfs(0, 0, 0);
	precompute();
	int q;
	cin>>q;
	while(q--)
	{
		int v, p;
		cin>>v>>p;
		int node=kth_ancestor(v, p);
		if(node==0)
			cout<<"0 ";
		else
		{
			int cur=storelevel[v];
			int ans=upper_bound(level[cur].begin(), level[cur].end(), endtime[node]) - lower_bound(level[cur].begin(), level[cur].end(), starttime[node]);
			ans--;
			cout<<max(0LL, ans)<<" ";
		}
	}
	return 0;
}