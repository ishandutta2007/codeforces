#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--) 
#define ll long long
const ll mo=1e9+7;
const ll N=2e5;
struct re{
	ll a,b;
}e[N];
ll head[N],l,sum[N],n,k;
ll b[N],c[N];
ll cnt=0; 
void arr(ll x,ll y)
{
	e[++l].a=head[x];
	e[l].b=y;
	head[x]=l;
}
void dfs(ll x,ll y)
{
	ll now=head[x]; sum[x]=1;
	while (now)
	{
		ll z=e[now].b;
	    if (z!=y)
		{  
		  dfs(z,x);
		  sum[x]+=sum[z];
	    }
		now=e[now].a;
	}
	if (x!=1) b[++cnt]=1ll*sum[x]*(n-sum[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	ll T;
	cin>>T;
	rep(i,1,T)
	{
		cnt=0;
		cin>>n;
		rep(i,1,n-1)
		{
			ll x,y;
			cin>>x>>y;
			arr(x,y); arr(y,x); 
		}
		dfs(1,0);
		sort(b+1,b+n);
		cin>>k;
		rep(i,1,k)
		  cin>>c[i];
		sort(c+1,c+k+1);
		if (k>n-1)
		{
			ll ans=1,ans2=0;
			rep(i,n-1,k) ans=ans*c[i]%mo;
			rep(i,1,n-2) ans2=(ans2+c[i]*b[i])%mo;
			ans2=(ans2+ans*b[n-1])%mo;
			cout<<ans2<<endl;
		} else
		{
		    ll ans=0;
		    dep(i,k,1) ans=(ans+b[n-1-k+i]*c[i])%mo;
		    rep(i,1,n-1-k) ans=(ans+b[i])%mo;
		    cout<<ans<<endl;
		}
		rep(i,1,n) head[i]=0;
	}
	return 0;
}