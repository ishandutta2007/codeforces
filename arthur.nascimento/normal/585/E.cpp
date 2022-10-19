#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 99999999999999999LL
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 10010000

using namespace std;

int *mrk;
int mul[maxn];
int u[maxn];
int sieve[maxn];
int coprime[maxn];
int inv[maxn];
int gcdm[maxn];
int *gcd;
int cnt;

int ret;
long long r;

int exp(int a){
	if(a < 30)
		return 1 << a;
	r = 1;
	for(int i=32-__builtin_clz(a);i>=0;i--){
		r = (r*r)%mod;
		if(a&(1<<i)){
			r = 2*r;
			if(r > mod)
				r -= mod;
		}
	}
	return r;
}
	

main(){

	int n;
	scanf("%d",&n);

	inv[0] = 1;
	cnt = 1;

	u[1] = 1;
	for(int i=2;i<maxn;i++){
		if(sieve[i] == 0){
			u[i] = -1;
			inv[cnt++] = i;
			for(int j=i;j<maxn;j+=i)
				sieve[j] = i;
		}
		else {
			if((i/sieve[i])%sieve[i] == 0)
				u[i] = 0;
			else
				u[i] = -u[i/sieve[i]];
			if(u[i])
				inv[cnt++] = i;
		}
	}	

	mrk = sieve;
	for(int i=1;i<maxn;i++)
		mrk[i] = 0;

	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		mrk[a]++;
	}

	for(int i=1;i<maxn;i++)
		for(int j=i;j<maxn;j+=i)
			mul[i] += mrk[j];

	for(int a=0;a<cnt;a++){
		int i = inv[a];
		if(mul[i] == 0) continue;
		for(int j=i;j<maxn;j+=i)
			coprime[j] += u[i]*mul[i];
	}

	for(int i=1;i<20;i++)
		debug("coprimos[%d] = %d u %d mul %d\n",i,coprime[i],u[i],mul[i]);

	gcd = mrk;
	for(int i=0;i<maxn;i++)
		gcd[i] = 0;

	for(int i=1;i<maxn;i++)
		gcdm[i] = exp(mul[i])-1;debug("ok");

	for(int i=1;i<maxn;i++)
		for(int j=0;i*inv[j]<maxn && j<cnt;j++){
			gcd[i] += u[inv[j]]*gcdm[i*inv[j]];
		//	debug("gcd[%d] += %d*gcdm[%d]\n",i,u[inv[j]],i*inv[j]);
			if(gcd[i] > mod) gcd[i] -= mod;
			if(gcd[i] < 0) gcd[i] += mod;
		}

	for(int i=1;i<20;i++)
		debug("%d gcdm %d gcd %d\n",i,gcdm[i],gcd[i]);

	long long ans = 0;
	for(int i=2;i<maxn;i++){
		ans += (long long)gcd[i]*coprime[i];
		ans %= mod;
	}

	printf("%lld\n",ans);
	
}