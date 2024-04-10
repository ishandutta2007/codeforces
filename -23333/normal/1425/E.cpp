#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
#define mid ((h+t)>>1)
#define ll long long
const int N=2e6;
ll a[N],d[N],n,k;
ll sum[N],f[N],sum2[N];
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>k;
  rep(i,1,n) cin>>a[i];
  rep(i,1,n) cin>>d[i];
  if (k==0)
  {
  	dep(i,n,1) sum[i]=sum[i+1]+a[i];
  	ll ans=0;
	rep(i,1,n) ans=max(ans,sum[i]-d[i]);
	cout<<ans<<endl; 
  } else
  if (k==1)
  {
  	dep(i,n,1) sum[i]=sum[i+1]+a[i];
  	rep(i,1,n) sum2[i]=sum2[i-1]+a[i];
  	ll ans=0;
  	dep(i,n,1)
  	{
  		f[i]=max(f[i+1],sum[i]-d[i]);
  	}
  	ans=f[2];
  	ll tt=1e15,tt1=1e15;
  	rep(i,1,n-1)
  	{
  		tt1=min(tt1,1ll*d[i]);
  		ans=max(ans,sum2[i]-tt1+f[i+1]); 
  		tt=min(tt,sum2[i-1]+d[i]);
  		if(i<=n-2) ans=max(ans,sum2[n]-tt-a[i+1]+max(a[i+1]-d[i+1],0ll)) ;
  	}
  	ans=max(ans,a[n]-1ll*d[n]);
  	cout<<ans<<endl;
  } else
  {
  	ll ans=1e9;
  	ll now=0;
  	rep(i,1,n-1) ans=min(ans,d[i]);
  	rep(i,1,n) now=now+a[i];
  	cout<<max(0ll,max(now-ans,a[n]-1ll*d[n]))<<endl;
  }
  return 0; 
}