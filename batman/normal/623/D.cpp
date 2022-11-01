#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)110)
#define K ((ll)501*1000)

ll n;
ld p[N],lst[N],now=1,ans;
priority_queue <pair<ld,ll> > s;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];p[i]/=(ld)100;
		now*=p[i];
		s.push({(ld)(1-(1-p[i])*(1-p[i]))/p[i],i});
		lst[i]=p[i];
	}
	ans=now*n;
	for(int i=n+1;i<K;i++)
	{
		ld inc=s.top().first;
		ll x=s.top().second;s.pop();
		ans+=now*(inc-1)*i;
		now*=inc;
		lst[x]=1-(1-p[x])*(1-lst[x]);
		s.push({(1-(1-p[x])*(1-lst[x]))/lst[x],x});
	}
	cout<<fixed<<setprecision(16)<<ans<<"\n";
	return 0;
}