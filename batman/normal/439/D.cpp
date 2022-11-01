#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)

ll n,m,a[N],b[N];

ll check(ll x)
{
	ll ans=0;
	for(int i=0;i<n;i++)ans+=max(0ll,x-a[i]);
	for(int i=0;i<m;i++)ans+=max(0ll,b[i]-x);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	
	ll l=0,r=(ll)1e9+10;
	for(int i=0;i<100;i++)
	{
		ll m1=l+(r-l)/3,m2=r-(r-l)/3;
		if(check(m1)>check(m2))
			l=m1;
		else
			r=m2;	
	}
	cout<<min(check(l),min(check(l+1),check(r)));
	
    return 0;
}