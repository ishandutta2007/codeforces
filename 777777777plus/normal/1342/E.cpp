#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 998244353;

int n;
ll k,f[1001][1001];
ll fac[N],rev[N];

ll qpow(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return r;
}

void prepare(){
	fac[0]=1;
	for(int i=1;i<N;++i)fac[i]=fac[i-1]*i%mod;
	rev[N-1]=qpow(fac[N-1],mod-2);
	for(int i=N-2;~i;--i)rev[i]=rev[i+1]*(i+1)%mod;
}

ll C(int n,int m){
	return fac[n]*rev[m]%mod*rev[n-m]%mod;
}

ll S(int n,int m){
	ll ret=0;
	for(int k=0;k<=m;++k){
		ret+=((k&1)?mod-1:1)*C(m,k)%mod*qpow(m-k,n)%mod;
		ret+=mod;
		ret%=mod;
	}
	return ret*rev[m]%mod;
}

int main(){
	prepare();
	cin>>n>>k;
	if(k>=n){
		cout<<0<<endl;
		return 0;
	}
	k=n-k;
//	f[0][0]=1;
//	for(int i=1;i<=k;++i)
//	for(int j=0;j<=n;++j)
//	for(int t=1;t<=j;++t){
//		f[i][j]+=f[i-1][j-t]*C(n-(j-t),t);
//	}
//	for(int i=1;i<=k;++i)cout<<f[i][n]<<" ";
//	cout<<endl;
	ll ans=S(n,k)*fac[k]%mod*C(n,k)%mod*2%mod;
	if(k==n)ans=ans*qpow(2,mod-2)%mod;
	cout<<ans<<endl;
}