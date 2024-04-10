#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P ((ll)133)
const ll MOD=((ll)((1LL)<<(32)));

ll n,p,q,c[P],ans;

ll calc(ll x)
{
	ll a[P],b[P],res=1;
	for(ll i=0;i<x;i++)a[i]=n-i,b[i]=x-i;
	for(ll i=0;i<x;i++)
		for(ll j=0;j<x;j++)
		{
			ll ex=__gcd(a[i],b[j]);
			a[i]/=ex;b[j]/=ex;
		}
	for(ll i=0;i<x;i++)res*=a[i],res%=MOD;
	return res;
}

int main()
{
	cin>>n>>p>>q;
	for(ll i=0;i<=p;i++)c[i]=calc(i);
	for(ll i=1;i<=q;i++)
	{
		ll res=0;
		for(ll j=0,tvn=1;j<=min(p,n-1);j++,tvn*=i,tvn%=MOD)res+=c[j]*tvn,res%=MOD;
		res*=i;res%=MOD;
		ans^=res;ans%=MOD;
	}
	cout<<(ans+MOD)%MOD;
	return 0;
}