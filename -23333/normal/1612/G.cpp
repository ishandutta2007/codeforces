#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1.2e6;
const int mo=1e9+7;
ll jc[N],a[N],f[N];
inline ll S(ll x,ll y)
{
	ll ans=((__int128)(x+y)*(y-x+1)/2)%mo;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	ll num=0;
	int n;
	cin>>n;
	rep(i,1,n)
	{ 
	  cin>>a[i];
	  f[a[i]]++;
	  num+=a[i];
    }
    int nn=1e6;
    jc[0]=1;
    rep(i,1,nn) jc[i]=jc[i-1]*i%mo;
    ll ans1=0,ans2=1; 
    dep(i,nn,1)
    {
    	if (i!=1) ans2=ans2*jc[f[i]]%mo*jc[f[i]]%mo;
    	else ans2=ans2*jc[f[i]]%mo;
    	ans1+=(S(num-f[i]+1,num)-S(1,f[i]))*(i-1)%mo;
    	ans1%=mo;
    	if (i>=2)
		{ 
		  f[i-2]=f[i-2]+f[i];
    	  num-=2*f[i];
        }
    }
    ans1=(ans1+mo)%mo; ans2=(ans2+mo)%mo;
    cout<<ans1<<" "<<ans2<<endl;
	return 0; 
}