#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1000005
#define mod 998244353
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll fct[maxn],nyfct[maxn];
ll modpow(ll x,ll y){
  ll res = 1;
  while(y){
    if(y & 1) res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}
void ini(int n){
  fct[1] = 1;
  for(int i=2;i<=n;i++){
    fct[i] = fct[i - 1] * i % mod;
  }
  nyfct[n] = modpow(fct[n],mod - 2);
  for(int i = n - 1;i >= 1;i--){
    nyfct[i] = nyfct[i + 1] * (i + 1) % mod;
  }
}
int main(){
	scanf("%d",&n);
	ini(n);
	ll ans = (n * (fct[n] - 1) + 1) % mod;
	for(int i=1;i<n;i++){
		ll a = (fct[n] * nyfct[i] - fct[n] * nyfct[i + 1]) % mod;
		ans = (ans - a * i) % mod;
	}
	printf("%I64d\n",(ans % mod + mod) % mod);
	return 0;
}