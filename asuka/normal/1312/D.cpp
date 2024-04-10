#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define mod 998244353
using namespace std;
ll n,m,ans,inv[N],fac[N];;
ll qpow(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res%mod;
}
ll C(ll a,ll b){
	if(a < 0||b < 0||a > b) return 0;
	if(a == 0||b == 0) return 1;
	return ((fac[b]%mod*inv[a])%mod*inv[b-a])%mod;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	if(n==2||m < n-1){
		cout<<0<<endl;
		return 0;
	}
	fac[1] = 1ll;
	inv[0] = 1ll;
	for(int i = 2;i <= m;++i){
		fac[i] = (fac[i-1]*i)%mod;
	}
	for(int i = 1;i <= m;++i){
		inv[i] = qpow(fac[i],mod-2)%mod; 
	}
	ans = (1ll*(qpow(2,n-3)%mod*(n-2))%mod*C(n-1,m)%mod)%mod;
	cout << ans;
	return 0;
}