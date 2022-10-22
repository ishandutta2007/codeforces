#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
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
		int ans=0;
		rep(i,1,n)
 		{
 			rep(j,1,n) dp[j]=0;
 			rep(i1,i,n)
 			{
 			  dep(j1,i1,i)
 			  {
 			  	if (a[j1]<=n) b[a[j1]]=1; int tt;
 			  	rep(k,0,n)
 			  	  if (!b[k])
 			  	  {
 			  	  	tt=k; break;
 			  	  }
 			  	dp[i1]=max(dp[i1],dp[j1-1]+tt+1);
 			  }
 			  ans+=dp[i1];
 			  dep(j1,i1,i)
 			    if (a[j1]<=n) b[a[j1]]=0;
 		    }
	    }
	    cout<<ans<<endl;
	}
	return 0; 
}