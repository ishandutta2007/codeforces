#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 14;
const ll mod = 1e9+7;

int n;
ll a[N],w[N][N],f[1<<N];
ll ans;

ll qpow(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return r;
}

ll rev(ll x){
	return qpow(x,mod-2);
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j){
		w[i][j]=a[i]*rev(a[i]+a[j])%mod;
	}
	for(int S=1;S<(1<<n);++S){
		f[S]=1;
		for(int T=(S-1)&S;T!=S;T=(T-1)&S){
			ll val=f[T];
			for(int i=0;i<n;++i)
			if(T&1<<i){
				for(int j=0;j<n;++j)
				if((S^T)&1<<j){
					val*=w[i][j];
					val%=mod;
				}
			}
			f[S]=(f[S]-val+mod)%mod;
		}
		ll val=f[S];
		for(int i=0;i<n;++i)
		if(S&1<<i){
			for(int j=0;j<n;++j)
			if(!(S&1<<j)){
				val*=w[i][j];
				val%=mod;
			}
		}
		ans+=val*__builtin_popcount(S)%mod;
	}
	cout<<ans%mod<<endl;
}