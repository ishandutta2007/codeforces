#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)301*1000);
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);

ll n,k,ans,c[N],a[N];
ll sum;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>c[i],sum+=c[i];
	for(int i=0;i<n;i++)ans+=c[i]*c[(i+1)%n];
	for(ll i=0;i<k;i++)
	{
		ll x;
		cin>>x;
		x--;
		if(!a[(x-1+n)%n])sum-=c[(x-1+n)%n];
		if(!a[(x+1)%n])sum-=c[(x+1)%n];
		sum-=c[x];
		//cout<<sum<<"\n";
		ans+=c[x]*sum;
		if(!a[(x-1+n)%n])sum+=c[(x-1+n)%n];
		if(!a[(x+1)%n])sum+=c[(x+1)%n];
		sum+=c[x];
		sum-=c[x];a[x]=1;
	}
	cout<<ans;
	return 0;
}