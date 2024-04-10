#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)

ll n,m,k,p,a[N],h[N];
bool check(ll x)
{
	priority_queue <pair<ld,ll>,vector<pair<ld,ll> >,less <pair<ld,ll> > > s;
	ll ex=0;
	for(int i=0;i<n;i++)
	{
		ex+=ceil((ld)max(0ll,(h[i]+m*a[i]-x))/p);
		s.push({a[i],i});
		if(a[i]>x)return 0;
	}
	if(ex>m*k)return 0;
	for(ll i=2,now=k;i<=m;i++,now+=k)
	{
		while(s.size() && ceil(((ld)i*s.top().first-x)/p)>0)
		{
			ld v=s.top().first;
			ll num=ceil(((ld)i*v-x)/p);
			if(num<=0)break;
			now-=num;
			if(now<0)return 0;
			s.push({v-(ld)ceil(((ld)i*v-x)/p)*p/i,s.top().second});
			s.pop();
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k>>p;
	for(int i=0;i<n;i++)cin>>h[i]>>a[i];
	ll l=-1,r=(ll)1e14;
	while(l<r-1)
	{
		ll mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<r;
	return 0;
}