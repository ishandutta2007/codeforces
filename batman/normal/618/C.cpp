#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e12)

ll n;
pair <ll,pair<ll,ll> > a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second.first,a[i].second.second=i+1;
	sort(a,a+n);
	for(int i=0;i<n-2;i++)
	{
		if(a[i].first==a[i+1].first && a[i].first==a[i+2].first)continue;
		if(a[i].second.first==a[i+1].second.first && a[i].second.first==a[i+2].second.first)continue;
		if(a[i].first==a[i+1].first ||
			a[i].first==a[i+2].first ||
			a[i+1].first==a[i+2].first ||
			a[i].second.first==a[i+1].second.first ||
			a[i].second.first==a[i+2].second.first ||
			a[i+1].second.first==a[i+2].second.first	
		)return cout<<a[i].second.second<<" "<<a[i+1].second.second<<" "<<a[i+2].second.second,0;
		
		ld m1=(ld)(a[i].first-a[i+1].first)/(ld)(a[i].second.first-a[i+1].second.first);
		ld m2=(ld)(a[i].first-a[i+2].first)/(ld)(a[i].second.first-a[i+2].second.first);
		if(m1==m2)continue;
		return cout<<a[i].second.second<<" "<<a[i+1].second.second<<" "<<a[i+2].second.second,0;
	}
    return 0;
}