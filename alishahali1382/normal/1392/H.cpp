#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAXN=4000010;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll F[MAXN], I[MAXN];
ll dp[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(ll n, ll r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	cin>>n>>m;
	ll sum=0;
	for (int k=n-1; ~k; k--){
		sum=(sum + dp[k+1]*nCr(n+m-(k+1)-1, m-1))%mod;
		ll tmp=F[k]*F[n-k]%mod*I[n+m]%mod*F[m]%mod;
		ll S=(sum*nCr(n+m, k)+ nCr(n+m+1, k)*nCr(n+m-k+1, n-k))%mod*tmp%mod;
		ll cof=(n+m-k)*I[n-k]%mod*F[n-k-1]%mod;
		dp[k]=S*cof%mod;
	}
	ans=dp[0];
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
	
	return 0;
}