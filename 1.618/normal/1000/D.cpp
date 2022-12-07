#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define modd 998244353
#define maxn 1005
// prime.
using namespace std;
typedef long long ll;
int n,a[maxn],dp[maxn];
ll jc[maxn];
ll modpow(ll x,ll y,ll mod){
	x %= mod;
	if(x == 0ll) return 0ll;
	ll res = 1ll;
  while(y){
  	if(y & 1) res = res * x % mod;
  	y >>= 1;
  	x = x * x % mod;
  }
  return res;
}
ll ny(ll x,ll mod){
	return modpow(x,mod-2,mod);
}
ll c(ll x,ll y,ll mod){
	return jc[x] * ny(jc[y],mod) % mod * ny(jc[x-y],mod) % mod;
}
int main(){
	scanf("%d",&n);
	jc[0] = 1;
	for(int i=1;i<=n;i++){
		jc[i] = jc[i-1] * i % modd;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		if(a[i] > 0 && i+a[i] <= n){
			if(i+a[i] == n) dp[i] = 1;
			else{
				dp[i] = c(n-i,a[i],modd);
				for(int j=i+a[i]+1;j<=n;j++){
					dp[i] = (dp[i] + (ll)dp[j] * c(j-i-1,a[i],modd)) % modd;
				}
			}
		}
	}
	ll ans = 0;
	for(int i=1;i<=n;i++) ans = (ans + dp[i]) % modd;
	printf("%I64d\n",ans);
	return 0;
}