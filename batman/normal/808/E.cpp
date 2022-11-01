#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)

ll n,m,dp[N];
vector <ll> v[4];
pair <ll,ll> pos[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll w,c;
		cin>>w>>c;
		v[w].push_back(c);
	}
	for(int i=1;i<=3;i++)sort(v[i].begin(),v[i].end()),reverse(v[i].begin(),v[i].end());
	for(int i=1;i<=m;i++)
	{
		dp[i]=dp[i-1],pos[i]=pos[i-1];
		if(pos[i-1].first<v[1].size())
			dp[i]=dp[i-1]+v[1][pos[i-1].first],pos[i].first++;
		if(i>1 && pos[i-2].second<v[2].size() && dp[i-2]+v[2][pos[i-2].second]>dp[i])
			dp[i]=dp[i-2]+v[2][pos[i-2].second],pos[i]=pos[i-2],pos[i].second++;
		if(i>1 && pos[i-2].first<(ll)v[1].size()-1 && dp[i-2]+v[1][pos[i-2].first]+v[1][pos[i-2].first+1]>dp[i])
			dp[i]=dp[i-2]+v[1][pos[i-2].first]+v[1][pos[i-2].first+1],pos[i]=pos[i-2],pos[i].first+=2;
	}
	//cout<<dp[1]<<"\n";
	ll ans=dp[m],now=0;
	for(int i=0;i<v[3].size();i++)
	{
		now+=v[3][i];
	//	cout<<now<<" "<<dp[m-i*3]<<"\n";
		if(m-(i+1)*3<0)break;
		ans=max(ans,dp[m-(i+1)*3]+now);
	}
	cout<<ans;
	return 0;
}