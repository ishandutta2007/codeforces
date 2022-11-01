#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (2100)
#define INF ((ll)1e16)
#define MOD ((ll)1e9+7)

ll n,x,y,x2,y2,ans=INF;
pair <ll,ll> a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>x>>y>>x2>>y2;
	for(ll i=0;i<n;i++)cin>>a[i].first>>a[i].second;
	a[n]={x,y};
	for(ll i=0;i<n+1;i++)
	{
		ll r1=(a[i].first-x)*(a[i].first-x)+(a[i].second-y)*(a[i].second-y),r2=0;
		for(ll j=0;j<n;j++)
			if((a[j].first-x)*(a[j].first-x)+(a[j].second-y)*(a[j].second-y)>r1)
				r2=max(r2,(a[j].first-x2)*(a[j].first-x2)+(a[j].second-y2)*(a[j].second-y2));
		ans=min(ans,r1+r2);
	}
	cout<<ans;
    return 0;
}