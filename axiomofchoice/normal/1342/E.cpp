#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
const int mod=(0?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
struct CC{
	static const int N=200010;
	ll fac[N],inv[N];
	CC(){
		fac[0]=1;
		repeat(i,1,N)fac[i]=fac[i-1]*i%mod;
		inv[N-1]=qpow(fac[N-1],mod-2,mod);
		repeat_back(i,0,N-1)inv[i]=inv[i+1]*(i+1)%mod;
	}
	ll operator()(ll a,ll b){ //a>=b
		if(a<b)return 0;
		return fac[a]*inv[a-b]%mod*inv[b]%mod;
	}
}C;
int a[N],c[N];
int n,k,ans;
signed main(){
	cin>>n>>k;
	if(k>=n)cout<<0<<endl,exit(0);
	if(k==0)cout<<C.fac[n]<<endl,exit(0);
	repeat(i,0,n-k+1){
		if(i%2==0)ans+=qpow(n-k-i,n)*C(n-k,i)%mod;
		else ans-=qpow(n-k-i,n)*C(n-k,i)%mod;
	}
	ans%=mod;
	(ans*=C(n,n-k))%=mod;
	(ans*=2)%=mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}