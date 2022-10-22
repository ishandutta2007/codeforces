#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e5;
int a[N],b[N],c[N],n,m;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		ll ans=0,ans2=0;
		rep(i,1,n) cin>>a[i]>>b[i],ans+=a[i]+b[i];
		ans-=1ll*n*m;
		ans2=ans; ans/=2;
		rep(i,1,n)
		{
		  c[i]=min(a[i],m);
		  ans-=a[i]-c[i];
	    }
	    rep(i,1,n)
	    {
	    	if (ans>0)
	    	{
	    		int gg=m-min(m,b[i]);
	    		if (ans-(c[i]-gg)>=0)
	    		{
	    			ans-=(c[i]-gg);
	    			c[i]=gg;
	    		} else
	    		{
	    			c[i]-=ans;
	    			ans=0;
	    		}
	    	}
	    }
	    ans=ans2/2-ans;
	    cout<<abs(2*ans-ans2)<<"\n";
	    rep(i,1,n) cout<<c[i]<<" "<<m-c[i]<<"\n";
    }
	return 0; 
}