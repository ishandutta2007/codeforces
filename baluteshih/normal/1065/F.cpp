#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int dp[1000005],k;
pii dp2[1000005];
vector<int> child[1000005];

void dfs(int x)
{
	if(child[x].empty())
		return dp[x]=1,dp2[x]=MP(1,k),void();
	int mx=0;
	dp[x]=0,dp2[x]=MP(0,0);
	for(int i:child[x])
	{
		dfs(i);
		if(dp2[i].S>0)
		{
			dp[x]+=dp2[i].F,mx=max(dp[i]-dp2[i].F,mx);
			dp2[x].S=max(dp2[x].S,dp2[i].S-1),dp2[x].F+=dp2[i].F;
		}
		else
			mx=max(dp[i],mx);
	}
	dp[x]+=mx;
}

int main()
{jizz
	int n,x;
	cin >> n >> k;
	for(int i=2;i<=n;++i)
		cin >> x,child[x].pb(i);
	dfs(1);
	cout << max(dp[1],dp2[1].F) << "\n";
	//DB(dp,1,n+1);
	//for(int i=1;i<=n;++i)
	//	cout << "(" << dp2[i].F << "," << dp2[i].S << ") ";
}