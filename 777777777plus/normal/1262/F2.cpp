#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 998244353;
 
int n,k,a[N];
ll ans;
ll fac[N],rev[N];

ll qpow(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		b>>=1;a=a*a%mod;
	}
	return r;
}

void prepare(){
	int i;
	for(i=fac[0]=1;i<N;++i)fac[i]=fac[i-1]*i%mod;
	for(rev[N-1]=qpow(fac[N-1],mod-2),i=N-2;~i;--i)rev[i]=rev[i+1]*(i+1)%mod;
}

ll C(int n,int m){
	if(n<m||m<0)return 0;
	return fac[n]*rev[m]%mod*rev[n-m]%mod;
}

int main(){
	prepare();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	a[n+1]=a[1];
	int c=0;
	for(int i=1;i<=n;++i)if(a[i]==a[i+1])++c;
	int m=n-c;
	for(int i=0;i<=m/2;++i){
		ans+=C(m,i)*C(m-i,i)%mod*qpow(k-2,m-2*i)%mod;
		ans%=mod;
	}
	ans=(qpow(k,m)-ans+mod)%mod*qpow(2,mod-2)%mod;
	cout<<ans*qpow(k,c)%mod<<endl;
}
/*
2 2 x
3 3 x
*/