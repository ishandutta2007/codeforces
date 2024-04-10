#include<bits/stdc++.h>
#define int long long
#define N 5005
#define mod 998244353
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}
int fac[N],inv[N];
int A(int n,int m){
	if(n<0 || m<0 || n<m) return 0;
	return (fac[n]*inv[n-m])%mod;
}
int n,a[N],pre[N],dp[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	fac[0] = inv[0] = 1;
 	rep(i,1,n) fac[i] = (fac[i-1]*i)%mod;
 	rep(i,1,n) inv[i] = (qpow(fac[i],mod-2))%mod;
 	sort(a+1,a+n+1);
 	int p = 0;
 	rep(i,1,n){
 		while(p+1 < i && a[p+1]*2 <= a[i]) p++;
 		pre[i] = p;
 	}
 	
 	dp[0] = 1; pre[0] = -1;
 	rep(i,1,n){
 		rep(j,0,pre[i]){
 			dp[i] = (dp[i]+dp[j]*A(n-pre[j]-2,pre[i]-pre[j]-1)%mod)%mod;
 		}
 	}
 	// rep(i,1,n) printf("%lld ",dp[i]);
 	// puts("");
 	if(pre[n] != n-1) puts("0");
 	else printf("%lld",dp[n]);
	return 0;
}