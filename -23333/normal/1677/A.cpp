#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
ll T,n,m;
const int N=5100;
int a[N],f[N][N],f2[N][N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		rep(i,1,n) cin>>a[i];
		rep(i,0,n+1) 
		  rep(j,0,n+1) f[i][j]=f2[i][j]=0;
		rep(i,1,n)
		{
			rep(j,1,i-1)
			{
				f[i][j]=f[i][j-1];
				if (a[i]>a[j]) f[i][j]++;
			}
	    }
	    rep(i,1,n)
	    {
	    	dep(j,n,i+1)
	        {
	        	f2[i][j]=f2[i][j+1];
	        	if (a[i]>a[j]) f2[i][j]++;
			}
	    }
	    ll ans=0;
	    rep(i,1,n)
	      rep(j,i+1,n)
	      {
	        ans+=1ll*f[j][i-1]*f2[i][j+1];
		  }
		cout<<ans<<endl;
	}
	return 0;
}