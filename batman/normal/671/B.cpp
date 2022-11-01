#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e14);
const ll MOD=((ll)1e9+7);
const ll N =501*1000;

ll n,k,a[N],sum;

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	ll l=0,r=sum/n+1;
	while(l<r-1)
	{
		ll mid=(l+r)/2,now=0;
		for(int i=0;a[i]<mid && i<n;i++)now+=mid-a[i];
		if(now<=k)l=mid;
		else r=mid;
	}
	ll mini=l;
	l=ceil((ld)sum/n)-1,r=a[n-1]+1;
	while(l<r-1)
	{
		ll mid=(l+r)/2,now=0;
		for(int i=n-1;a[i]>mid && i>=0;i--)now+=a[i]-mid;
		if(now<=k)r=mid;
		else l=mid;
	}
	ll maxi=r;
	cout<<maxi-mini;
	
	return 0;
}