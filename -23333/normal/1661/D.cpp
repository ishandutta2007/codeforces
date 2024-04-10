//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5+10;
const int mo=1e9+7;
ll n,m,a[N],b[N],f[N];
ll sum1[N],sum2[N],tmp1[N],tmp2[N];
ll js(ll x,ll y)
{
	if (x%y==0) return x/y;
	return x/y+1;
}
int main()
{
	ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	rep(i,1,n) cin>>a[i];
	ll ans=0;
	dep(i,n-k+1,2)
	{
		int j=i+k-1;
		sum1[j]+=sum1[j+1];
		sum2[j]+=sum2[j+1]-sum1[j+1];
		ll p=0;
		if (sum2[j]<a[j]) p=js(a[j]-sum2[j],k);
		sum1[j]+=p; sum2[j]+=k*p; sum1[i-1]-=p;
		ans+=p;
	}
	ll mx=0;
	dep(j,k,1)
	{
		sum1[j]+=sum1[j+1];
		sum2[j]+=sum2[j+1]-sum1[j+1];
		mx=max(mx,js(a[j]-sum2[j],j));
	}
	cout<<ans+mx<<endl;
//	ll ans=0;
//	rep(i,1,n-k)
//	{
//		sum1[i]+=sum1[i-1];
//		sum2[i]+=sum2[i-1];
//		sum2[i]+=sum1[i-1];
//		if (sum2[i]<a[i])
//		{
//			ll p=a[i]-sum2[i];
//			ans+=p;
//			sum1[i]+=p;
//			sum2[i]+=p;
//			sum1[i+k]-=p;
//			sum2[i+k]-=p*(k+1);
//	    }
//	}
//	ll mx=0;
//    ll h=0,t=1e12;
//    int pos=n-k+1;
//    sum1[pos]+=sum1[pos-1];
//    sum2[pos]+=sum2[pos-1];
//    sum2[pos]+=sum1[pos-1];
//	sum1[pos-1]=sum2[pos-1]=0; 
//    while (h<t)
//    {
//    	ll mid=(h+t)/2;
//    	memcpy(tmp1,sum1,sizeof(sum1));
//    	memcpy(tmp2,sum2,sizeof(sum2));
//    	sum1[pos]+=mid; sum2[pos]+=mid;
//    	bool tt=1;
//    	rep(i,pos,n)
//    	{
//			sum1[i]+=sum1[i-1];
//			sum2[i]+=sum2[i-1];
//			sum2[i]+=sum1[i-1];
//			if (a[i]>sum2[i]) tt=0;
//    	}
//    	memcpy(sum1,tmp1,sizeof(tmp1));
//    	memcpy(sum2,tmp2,sizeof(tmp2));
//    	if (tt) t=mid; else h=mid+1;
//    }
//    cout<<ans+h<<endl;
	return 0;
}