#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=305;
const int M=1e5+5;
const int MOD=1e9+7;

int n, q, t;
int a[N], cost[N], lvl[N], cache[N][M], vis[N];
vector<int> g[N], rg[N];

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

int dfs(int x)
{
	int &ans=cost[x];
	if(ans!=-1)
		return ans;
	ans=a[x];
	int level=0;
	for(auto &it:g[x])
		ans+=dfs(it);
	return ans;
}

int dfs2(int x)
{
	int &ans=lvl[x];
	if(ans!=-1)
		return ans;
	ans=0;
	for(auto &it:rg[x])
		ans=1+dfs2(it);
	t-=ans*a[x];
	return ans;
}

int dp(int idx, int val)
{
	if(val<0)
		return 0;
	if(val==0)
		return 1;
	if(idx==n+1)
		return 0;
	int &ans=cache[idx][val];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, val) + dp(idx, val-cost[idx]);
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cost, -1, sizeof(cost));
	memset(cache, -1, sizeof(cache));
	memset(lvl, -1, sizeof(lvl));
	cin>>n>>q>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		int b, c;
		cin>>b>>c;
		g[c].push_back(b);
		rg[b].push_back(c);
	}
	if(checkLoop())
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cost[i]=dfs(i);
	for(int i=1;i<=n;i++)
		dfs2(i);
	int ans=dp(1, t);
	cout<<ans;
	return 0;
}