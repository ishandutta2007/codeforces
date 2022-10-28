#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n, b;
int c[N], d[N], cnt[N];
int dp[N][2][N];
vector<int> g[N];

void dfs0(int k, int par)
{
	cnt[k]=1;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		dfs0(it, k);
		cnt[k]+=cnt[it];
	}
}

void dfs(int u, int par)
{
	dp[u][0][0]=0;
	dp[u][0][1]=c[u], dp[u][1][1]=c[u]-d[u];
	vector<pair<int, int> > seq;
	for(auto &it:g[u])
	{
		if(it==par)
			continue;
		dfs(it, u);
		seq.push_back({cnt[it], it});
	}
	sort(seq.begin(), seq.end());
	int cur=1;
	for(auto &it:seq)
	{
		int v=it.second;
		for(int j=cur;j>=0;j--)
		{
			for(int k=1;k<=cnt[v];k++)
			{
				dp[u][0][j+k]=min(dp[u][0][j+k], dp[u][0][j] + dp[v][0][k]);
				dp[u][1][j+k]=min(dp[u][1][j+k], dp[u][1][j] + min(dp[v][0][k], dp[v][1][k]));
			}
		}
		cur+=it.first;
	}
}

int32_t main()
{
	IOS;
	cin>>n>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
		if(i>=2)
		{
			int x;
			cin>>x;
			g[x].push_back(i);
		}
	}	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=n;k++)
				dp[i][j][k]=1e15;
	dfs0(1, 1);
	dfs(1, 1);
	int ans=0;
	while(ans<=n && min(dp[1][0][ans], dp[1][1][ans])<=b)
		ans++;
	cout<<ans-1;
	return 0;
}