#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=((n&1)?a:1ll),res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=11*1000;
const ll K=100*1000+1;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,dp[N],part_dp[N];

pair <ll,ll> solve(ll x)
{
	if(x<N)return {dp[part_dp[x]],part_dp[x]};
	ll l=0,r=K;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(mid*mid*mid<=x)l=mid;
		else r=mid;
	}
	ll id=0,ans=0;
	for(int i=0;i<7;i++,l--)
	{
		pair <ll,ll> ex=solve(x-l*l*l);ex.second+=l*l*l;ex.first++;
		if(ans<ex.first || (ans==ex.first && ex.second>id))id=ex.second,ans=ex.first;
		x=l*l*l-1;
	}
	return {ans,id};
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<N;i++)
	{
		ll j=1;
		for(;j*j*j<=i;j++);
		j--;
		dp[i]=1+dp[i-j*j*j];
		if(dp[i]>=dp[part_dp[i-1]])part_dp[i]=i;
		else part_dp[i]=part_dp[i-1];
	}
	pair <ll,ll> ans=solve(n);
	cout<<ans.first<<" "<<ans.second<<"\n";
  	return 0;
}