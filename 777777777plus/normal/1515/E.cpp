#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n;
ll mod;
ll f[N][N];
ll fac[N],rev[N],b2[N];

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
	b2[0]=1;
	for(int i=1;i<N;++i)b2[i]=b2[i-1]*2%mod;
}

int main(){
	cin>>n>>mod;
	prepare();
	f[0][0]=1;
	for(int i=0;i<=n;++i)
	for(int j=0;j<=n;++j)
	if(f[i][j]){
		for(int t=i+2;t<=n+1;++t){
			(f[t][j+t-i-1]+=f[i][j]*b2[t-i-2]%mod*rev[t-i-1]%mod)%=mod;
		}
	}
	ll ans=0;
	for(int i=0;i<=n;++i)(ans+=f[n+1][i]*fac[i]%mod)%=mod;
	cout<<ans<<endl;
}