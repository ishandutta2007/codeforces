#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e15)

ll n,A,cf,cm,m,b[N],ans=-1;
pair <ll,ll> id,a[N];
set <pair<ll,ll> > s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>A>>cf>>cm>>m;
	for(int i=0;i<n;i++)cin>>a[i].first,a[i].second=i;
	sort(a,a+n);
	for(ll i=0,sum=0;i<n;i++)
		s.insert({a[i].first,i}),b[i]=a[i].first*i-sum,sum+=a[i].first;
	a[n].first=a[n+1].first=A;
	for(ll i=n;i>=0;i--)
	{
		m-=A-a[i].first;
		if(m<0)break;
		ll l=0,r=A;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			set <pair<ll,ll> >::iterator it=s.upper_bound({min(mid,a[i-1].first),i-1});
			if(it==s.begin()){l=mid;continue;}
			it--;
			//cout<<mid<<" "<<it->first<<"\n";
			if(m>=b[it->second]+(mid-it->first)*(it->second+1))
				l=mid;
			else
				r=mid;	
		}
		//cout<<i<<" "<<l<<"\n";
		if(ans<cf*(n-i)+cm*l)
			ans=cf*(n-i)+cm*l,id={i,l};
		if(!i && ans<cf*n+cm*A)
			ans=cf*n+cm*A,id={i,l};
	}
	cout<<ans<<"\n";
	for(int i=n-1;i>=id.first;i--)a[i].first=A;
	for(int i=0;i<n;i++)b[a[i].second]=max(a[i].first,id.second);
	for(int i=0;i<n;i++)cout<<b[i]<<" ";
    return 0;
}