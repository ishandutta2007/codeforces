#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll x,n,ans=1,pr[50],cnt,g[500000],cnt2;
ll ksm(ll a,ll b){a%=mod;ll ans=1,mut=a;while(b){if(b&1)ans=(ans*mut)%mod;b>>=1,mut=(mut*mut)%mod;};return ans;}
int main()
{
	cin>>x>>n;
	ll tmp=x;
	for(int i=2;i<=sqrt(tmp);i++)
		if(tmp%i==0){
			pr[++cnt]=i;
			while(tmp%i==0)tmp/=i;
		}
	if(tmp>1)pr[++cnt]=tmp;
	for(int i=1;i<=cnt;i++){
		ll p=n/pr[i];
		ll sum=p;
		while(p)p/=pr[i],sum+=p;
		ans=ans*ksm(pr[i],(sum%1000000006))%mod;
	}
	cout<<ans;
    return 0;
}