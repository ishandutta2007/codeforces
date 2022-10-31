#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=301*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,a[N],b[N],sum[N],sum2[N],m;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i],sum[i]=sum[i-1]+a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)sum2[i]=sum2[i-1]+b[i];
	cin>>m;
	for(int i=0;i<m;i++)
	{
		ll t,l,r;
		cin>>t>>l>>r;
		if(t==1)
		{
			cout<<sum[r]-sum[l-1]<<"\n";
		}
		else
			cout<<sum2[r]-sum2[l-1]<<"\n";
	}
	return 0;
}