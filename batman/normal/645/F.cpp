#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define K ((ll)1001*1000)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b){ll res=1;while(b){res*=b%2?a:1;res%=MOD;a*=a;a%=MOD;b/=2;}return res;}
ll n,k,q,ans,kfac,c[K],lp[K],phi[K],num[K];
vector <ll> dv[K];
void add(ll x){for(auto u:dv[x])ans+=(c[num[u]+1]-c[num[u]])*phi[u],num[u]++,ans%=MOD,ans+=MOD,ans%=MOD;}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>q;
	for(ll i=2;i<=k;i++)kfac*=i,kfac%=MOD;
	c[k]=1;for(ll i=k+1;i<K;i++)c[i]=(((c[i-1]*i)%MOD)*tavan(i-k,MOD-2))%MOD;
	lp[1]=phi[1]=1;for(ll i=1;i<K;i++)
	{
		if(!lp[i])for(ll j=i;j<K;j+=i)if(!lp[j])lp[j]=i;	
		phi[i]=phi[i/lp[i]]*(lp[i]-(i%(lp[i]*lp[i])!=0));
		for(ll j=i;j<K;j+=i)dv[j].push_back(i);
	}
	for(int i=0;i<n;i++){ll x;cin>>x;add(x);}
	for(int i=0;i<q;i++){ll x;cin>>x;add(x);cout<<ans<<"\n";}
	return 0;
}