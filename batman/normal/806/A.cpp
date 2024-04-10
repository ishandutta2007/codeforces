#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)2020)
#define INF ((ll)1e18)

ll t;

int main()
{
	cin>>t;
	while(t--)
	{
		ll x,y,p,q;
		cin>>x>>y>>p>>q;
		if(p==0)
		{
			if(x==0)cout<<"0\n";
			else cout<<"-1\n";
			continue;
		}
		if(p==q)
		{
			if(x==y)cout<<"0\n";
			else cout<<"-1\n";
			continue;
		}
		ll l=max((y+q-1)/q,(x+p-1)/p)-1,r=(ll)3e9;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(mid*p<=x+q*mid-y)r=mid;
			else l=mid;
		}
		cout<<r*q-y<<"\n";
	}
	return 0;
}