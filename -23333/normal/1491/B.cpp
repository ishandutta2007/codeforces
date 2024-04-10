#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
const int N=2e5;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{ 
		ll n,u,v;
		cin>>n>>u>>v;
		rep(i,1,n) cin>>a[i];
		ll ans=1e10;
		rep(i,2,n) if (abs(a[i]-a[i-1])>=2) ans=-1;
		if (ans==-1)
		{
			cout<<0<<endl;
		} else
		{
			rep(i,2,n) if (abs(a[i]-a[i-1])==1)
			{
				ans=min(u,v);
			}
			ans=min(ans,u+v);
			ans=min(ans,2*v);
			cout<<ans<<endl;
		}
    }
	return 0;
}