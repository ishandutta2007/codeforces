#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
const int N=1e6+5;
ll ksm(ll a,ll b){
	ll m=a,s=1;
	while(b){
		if(b&1)s=s*m%mod;
		m=m*m%mod,b>>=1;
	}
	return s;
}
ll n,q[N],z[N],inv,ans,mx;
vector <int> g[N];
int main(){
	cin>>n; inv=ksm(n,mod-2);
	for(int i=1;i<=n;i++){
		scanf("%lld",&q[i]);
		z[i]=ksm(q[i],mod-2);
		ll t;
		for(int j=1;j<=q[i];j++)scanf("%lld",&t),g[t].push_back(i),mx=max(mx,t);
	}
	for(int i=1;i<=mx;i++){
		ll s=0;
		for(int j=0;j<g[i].size();j++)s=(s+z[g[i][j]]*inv)%mod;
		ans=(ans+s*inv%mod*g[i].size()%mod)%mod;
	}
	cout<<ans<<endl;
    return 0;
}