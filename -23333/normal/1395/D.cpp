#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
ll n,m,d;
const ll N=1e5+10;
ll a[N],b[N],c[N],m1,m2;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>d>>m;
	rep(i,1,n)
	{ 
	  cin>>a[i];
	  if (a[i]>m) b[++m1]=a[i];
	  else c[++m2]=a[i];
    }
    sort(b+1,b+m1+1,cmp);
    sort(c+1,c+m2+1,cmp);
    rep(i,1,m2) c[i]+=c[i-1];
    ll ans=0,ans1=0;
    rep(i,0,m1)
    {
    	ans1+=b[i];
    	ll k=n-(d+1)*i+d;
    	if (k>m2) k=m2;
    	if (k>=0) ans=max(ans,c[k]+ans1);
    }
    cout<<ans<<endl;
	return 0;
}