#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0, ans2=0;
int num[N], sum[N], vis[N], dp[N][2];
vector<int> g[N];

void dfs(int k, int par)
{
	num[k]=1;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		num[k]+=num[it];
		int node=it;
		sum[k]+=1*num[node]+sum[node];
	}
}

void dfs2(int k, int par)
{
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		int node=it;
		sum[node]+=(n-num[node]) + sum[k] - sum[node] - num[node];
		num[node]++;
		dfs2(node, k);
	}
}

void dfs3(int k, int par)
{
	dp[k][0]=1, dp[k][1]=0;
	int cur=0;
	for(auto &it:g[k])
	{	
		if(it==par)
			continue;
		dfs3(it, k);
		dp[k][0]+=dp[it][1];
		dp[k][1]+=dp[it][0];
		cur+=dp[it][0];
	}
	int even=0, odd=0;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		cur+=dp[it][0] * odd + dp[it][1] * even;
		odd+=dp[it][1];
		even+=dp[it][0];
	}
	ans2+=cur;
}

int32_t main()
{
	IOS;
	cin>>n;;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	dfs2(1, 1);
	dfs3(1, 1);
	int sumpath=0;
	for(int i=1;i<=n;i++)
		sumpath+=sum[i];
	sumpath/=2;
	int ans=(sumpath+ans2)/2;
	cout<<ans;
	return 0;
}