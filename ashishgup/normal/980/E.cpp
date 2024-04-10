#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e6+5;
const int LG = log2(N) + 2;

int n, k;
vector<int> g[N];
int taken[N], level[N], par[LG][N];

void dfs(int k, int parent, int lvl)
{
	par[0][k]=parent;
	level[k]=lvl;
	for(auto it:g[k])
	{
		if(it==parent)
			continue;
		dfs(it, k, lvl+1);
	}
}

void precompute()
{
	for(int i=1;i<LG;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(par[i-1][j])
				par[i][j]=par[i-1][par[i-1][j]];
		}
	}
}

inline int dist(int k)
{
	if(taken[k])
		return 0;
	int ans=1;
	for(int i=LG-1;i>=0;i--)
	{
		if(!taken[par[i][k]] && par[i][k])
		{
			ans+=(1<<i);
			k=par[i][k];
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	k=n-k;
	dfs(n, 0, 0);
	precompute();
	taken[n]=1;
	k--;
	for(int i=n-1;i>=1;i--)
	{
		int willtake=dist(i);
		if(willtake<=k)
		{
			k-=willtake;
			int cur=i;
			while(!taken[cur] && cur!=0)
			{
				taken[cur]=1;
				cur=par[0][cur];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!taken[i])
			cout<<i<<" ";
	}
	return 0;
}