
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <cstring>
#include <map>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;

const lli mod=1e9+7;

lli fac[200001],ifac[200001];
lli power(lli a,lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
lli inv(lli a) {return power(a,mod-2);}

lli cache[2000];
pii arr[2000];
int n,m,k;

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++) scanf("%d%d",&arr[i].fi,&arr[i].se);
	sort(arr,arr+k);

	fac[0]=ifac[0]=1;
	for(int i=1;i<=n+m;i++) 
		fac[i] = fac[i-1]*i%mod;
	for(int i=1;i<=n+m;i++) 
		ifac[i] = inv(fac[i]);

	for(int i=0;i<k;i++) {
		int a=arr[i].fi-1,b=arr[i].se-1;
		cache[i] = fac[a+b] * ifac[a] % mod * ifac[b] % mod;
		for(int j=i-1;j>=0;j--) if(arr[j].fi<=arr[i].fi && arr[j].se<=arr[i].se) {
			a=arr[i].fi-arr[j].fi; b=arr[i].se-arr[j].se;
			cache[i] = (cache[i] - cache[j] * fac[a+b] % mod * ifac[a] % mod * ifac[b] % mod + mod) % mod;
		}
	}

	lli ans = fac[n+m-2] * ifac[n-1] % mod * ifac[m-1] % mod;
	for(int i=0;i<k;i++) {
		int a=n-arr[i].fi, b=m-arr[i].se;
		ans = (ans - cache[i] * fac[a+b] % mod * ifac[a] % mod * ifac[b] % mod + mod) % mod;
	}
	printf("%lld\n",ans);

	return 0;
}