#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
ll a[N],b[N],n,lim;
ll js(ll x,ll y)
{
	if (x%y==0) return x/y;
	return x/y+1;
}
ll js2(ll x,ll y)
{
	if (!y) return 1e18;
	ll k=x/y;
	ll c1=x-k*y; ll c2=y-c1;
	return c1*(k+1)*(k+1)+c2*k*k;
}
bool check(ll x,int y)
{
	ll ans=0,ans2=0;
	rep(i,1,n)
	{
		ll h=1,t=b[i];
		while (h<t)
		{
			ll mid=(h+t+1)/2;
			if (js2(b[i],mid-1)-js2(b[i],mid)>=x) h=mid;
			else t=mid-1;
		}
		ans+=js2(b[i],h); ans2+=h;
	}
	if (y==1)
	{
		cout<<ans2-(lim-ans)/x-n<<endl;
	}
	return ans<=lim;
} 
int main()
{
//	freopen("1.in","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) b[i]=a[i]-a[i-1];
    cin>>lim;
    ll h=1,t=1e18;
    while (h<t)
    {
    	ll mid=(h+t+1)/2;
    	if (check(mid,0)) h=mid;
    	else t=mid-1;
    }
    check(h,1);
    return 0;
}