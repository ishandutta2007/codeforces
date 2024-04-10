#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define INF ((ll)1e9)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,k,a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	scanf("%d%d",&n,&k);
	ll maxi=0;
	for(int i=0;i<n;i++)scanf("%d",&a[i]),maxi=max(maxi,a[i]);
	ll l=maxi-1,r=(ll)3e6;
	while(l<r-1)
	{
		ll mid=(l+r)/2,k2=0,p=n;
		set <ll> s;
		map <ll,ll> mp;
		for(int i=0;i<n;i++)mp[a[i]]++,s.insert(a[i]);
		while(p>1)
		{
			k2++;
			set <ll>::iterator it=s.end();
			it--;
			ll ex=*it;
			mp[ex]--;
			if(mp[ex]==0)
				s.erase(ex);
			p--;	
			it=s.upper_bound(mid-ex);
			if(it==s.begin())continue;
			it--;
			ex=*it;
			mp[ex]--;
			if(mp[ex]==0)
				s.erase(ex);
			p--;			
		}
		if(s.size())k2++;
		if(k2<=k)
			r=mid;
		else
			l=mid;	
	}
	printf("%I64d",r);
    return 0;
}