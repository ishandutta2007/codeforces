#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
const ll N=3e5+10;
ll a[N],T,n;
ll m;
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	rep(i,1,T)
	{
		cin>>n;
		ll ans=0;
		rep(i,1,n)
		{ 
		  cin>>a[i];
		  if (i>=2&&a[i]<a[i-1]) ans+=a[i-1]-a[i];
	    }
	    cout<<ans<<endl;
	}
	return 0;
}