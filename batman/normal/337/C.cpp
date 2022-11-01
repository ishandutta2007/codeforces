#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD ((ll)1e9+9)
ll n,m,k,tmp;

ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

int main()
{
	
	cin>>n>>m>>k;
	if(n%k!=0)
	{
		tmp+=n%k,m-=n%k,n-=n%k;
		if(n==m)
		{
			ll ans=tavan(2,(n/k)+1,MOD);
			ans-=2;
			ans*=k;
			ans+=tmp;
			cout<<ans%MOD;
			return 0;
		}	
	}
	ll tdad_dste=(ll)ceil((ld)n/k);
	ll ozv_dste=(ll)ceil((ld)m/tdad_dste);
	if(ozv_dste<k)
		return cout<<m+tmp,0;
	ll kam=(k-1)*tdad_dste;
	ll rem=m-kam;
	ll ans=tavan(2,rem+1,MOD*2);
	ans-=2;
	ans*=k;
	ans+=m-(rem*k);
	cout<<(ans+tmp)%MOD;	
	
    return 0;
}