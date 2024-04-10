#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
int a[N],b[N],dp[N];
signed main()
{
//	freopen("1.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n; 
		cin>>n;
		rep(i,1,n) cin>>a[i];
	    if (n==3&&a[2]%2==1)
	    {
	    	cout<<-1<<endl;
	    	continue;
	    }
	    bool tt=0;
	    rep(i,2,n-1) if (a[i]!=1) tt=1;
	    if (!tt)
	    {
	    	cout<<-1<<endl;
	    	continue;
	    }
	    ll ans=0;
        rep(i,2,n-1)
        {
          ans+=a[i];
          if (a[i]%2==1) ans++;
        }
        cout<<ans/2<<endl;
	}
	return 0; 
}