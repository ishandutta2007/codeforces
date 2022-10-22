#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long 
const int N=2.1e7;
bool tt[N];
int pr[N],a[N],p;
ll dp[N];
int main()
{
	ios::sync_with_stdio(false);
	int nn=2e7;
	rep(i,2,nn) tt[i]=1;
	rep(i,2,nn)
	{ 
		if(tt[i]) pr[++p]=i;
  		for (int j=1;j<=p;j++)
  		{
  	    	if (i*pr[j]>nn) break;
	    	tt[i*pr[j]]=0;
	    	if (i%pr[j]==0) break;
	    }
	}
	int n;
	cin>>n;
	rep(i,1,n) { int x; cin>>x; a[x]++;}
	rep(i,1,p)
	  dep(j,nn/pr[i],1)
	    a[j]+=a[j*pr[i]];
	
	ll ans=0;
	dep(i,nn,1)
	{
      dp[i]=1ll*a[i]*i;
	  for (int j=1;j<=p&&pr[j]*i<=nn;j++)
	    dp[i]=max(dp[i],dp[i*pr[j]]+1ll*(a[i]-a[i*pr[j]])*i);
	  if (dp[i]>ans) ans=dp[i];
	}
	cout<<ans<<endl;
	return 0;
}