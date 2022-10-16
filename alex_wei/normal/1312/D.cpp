#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
const int N=2e5+5;
ll ksm(ll a,ll b){
	ll s=1,m=a;
	while(b){
		if(b&1)s=s*m%mod;
		b>>=1,m=m*m%mod;
	}
	return s;
}
ll inv(ll x){return ksm(x,mod-2);}
ll n,m,frc[N],ifr[N],ans;
ll c(ll n,ll m){
	return frc[n]*ifr[n-m]%mod*ifr[m]%mod;
}
int main(){
	cin>>n>>m;
	if(n==2)puts("0"),exit(0);
	frc[0]=ifr[0]=1;
	for(int i=1;i<=m;i++)frc[i]=frc[i-1]*i%mod,ifr[i]=inv(frc[i]);
	ans=c(m,n-1)*(n-2)%mod;
	ll ans2=0;
	for(ll i=2;i<n;i++)ans2=(ans2+c(n-3,min(i-2,n-i-1)))%mod;
	cout<<ans*ans2%mod;
	return 0;
}