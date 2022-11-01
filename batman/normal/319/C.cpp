#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

ll n,a[N],b[N],dp[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	vector <pair<ll,ll> > v;v.push_back({0,0});
	for(int i=1;i<n;i++)
	{
		ll id=lower_bound(v.begin(),v.end(),make_pair(a[i],N))-v.begin();id--;id=v[id].second;
		dp[i]=dp[id]+a[i]*b[id];
		while(v.size() && dp[v.back().second]>=dp[i])v.pop_back();
		if(!v.size()){v.push_back({0,i});continue;}
		while(v.size() && (dp[i]-dp[v.back().second]+b[v.back().second]-b[i]-1)/(b[v.back().second]-b[i])<=v.back().first)v.pop_back();
		v.push_back({(dp[i]-dp[v.back().second]+b[v.back().second]-b[i]-1)/(b[v.back().second]-b[i]),i});
	}
	cout<<dp[n-1];
	return 0;
}