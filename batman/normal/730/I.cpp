#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)3010)

ll n,p,s,dp[N][N],par[N][N],now[N][N];
pair <pair<ll,ll>,ll> a[N];

int main()
{
	cin>>n>>p>>s;
	for(int i=1;i<=n;i++)cin>>a[i].first.first;
	for(int i=1;i<=n;i++)cin>>a[i].first.second,a[i].second=i;
	sort(a+1,a+n+1,greater <pair<pair<ll,ll>,ll> >());
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=-(ll)1e9;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			dp[i][j]=(j?dp[i-1][j-1]+a[i].first.second:0);
			now[i][j]=now[i-1][j-1]+1;
			if(dp[i][j]<dp[i-1][j]+(i-1-j<p?a[i].first.first:0))
			{
				dp[i][j]=dp[i-1][j]+(i-1-j<p?a[i].first.first:0);par[i][j]=1;
				if(i-1-j>=p)par[i][j]=2;
				now[i][j]=now[i-1][j];
			}
		}
	cout<<dp[n][s]<<"\n";
	ll y=s;
	vector <ll> ex1,ex2;
	for(int i=n;i>=1;i--)
	{
 		if(par[i][y]==0)ex2.push_back(a[i].second),y--;
		else if(par[i][y]==1)ex1.push_back(a[i].second);
	}
	sort(ex1.begin(),ex1.end());
	sort(ex2.begin(),ex2.end());
	for(auto u:ex1)cout<<u<<" ";cout<<"\n";
	for(auto u:ex2)cout<<u<<" ";
	return 0;
}