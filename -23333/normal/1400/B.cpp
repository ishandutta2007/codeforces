#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++) 
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int t;
int main()
{
	cin>>t;
	rep(i,1,t)
	{
		ll p,f,cnt1,cnt2,s,w;
		cin>>p>>f;
	    cin>>cnt1>>cnt2;
	    cin>>s>>w;
	    ll ans=0,ans2=0;
	    rep(i,0,cnt1)
		if (i*s<=p)
		{
			ll x=min((p-i*s)/w,cnt2);
			if (s<w)
			{
				ll y=(cnt1-i)*s;
				if (y>f) ans2=max(ans2,x+i+f/s);
				else ans2=max(ans2,cnt1+x+min((f-y)/w,cnt2-x)); 
			} else
			{
				ll y=(cnt2-x)*w;
				if (y>f) ans2=max(ans2,x+i+f/w);
				else ans2=max(ans2,cnt2+i+min((f-y)/s,cnt1-i));
			}
	    }
	    cout<<ans2<<endl;
	}
	return 0; 
}