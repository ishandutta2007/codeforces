#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll n,q,v[N],c[N],dp[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++)cin>>c[i];
	while(q--)
	{
		ll a,b,ans=0;
		pair <ll,ll> maxi[2]={};
		cin>>a>>b;
		for(int i=0;i<N;i++)dp[i]=-INF;
		for(int i=0;i<n;i++)
		{
			ll ex=maxi[0].first;
			if(maxi[0].second==c[i])ex=maxi[1].first;
			if(dp[c[i]]!=-INF)dp[c[i]]=max(dp[c[i]],dp[c[i]]+v[i]*a);
			dp[c[i]]=max(dp[c[i]],ex+v[i]*b);
			if(dp[c[i]]>maxi[0].first)
			{
				if(maxi[0].second==c[i])maxi[0].first=dp[c[i]];
				else maxi[1]=maxi[0],maxi[0]={dp[c[i]],c[i]};	
			}
			else if(dp[c[i]]>maxi[1].first && c[i]!=maxi[0].second)maxi[1]={dp[c[i]],c[i]};
		}
		for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
		cout<<ans<<"\n";
	}
    return 0;
}