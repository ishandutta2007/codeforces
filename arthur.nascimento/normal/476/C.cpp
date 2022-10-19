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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

long long exp(long long a,long long b){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long k = exp(a,b/2);
	k = (k*k) % mod;
	if(b%2) k = (k*a) % mod;
	return k;
}

unsigned long long inv(long long x){
	return exp(x,mod-2);
}

unsigned long long sum(unsigned long long a,unsigned long long b,long long r){
	unsigned long long n = (b-a)+ 1;
	//long long ret = ((a+b)*n)/2;
	unsigned long long ret = (a+b)%mod;
		ret *= inv(2);
		ret %= mod;
		ret *= (n%mod);
		ret %= mod;

	return ret;
}

main(){

		long long a,b;
		scanf("%I64d%I64d",&a,&b);

		long long ans = 0;
		long long S = sum(1,a,1);

		for(int i=1;i<b;i++){

			ans += a*i;
			ans += ((b*i)%mod)*S;
			ans %= mod;

			/*debug("sum %I64d..%I64d\n",low,up);
			unsigned long long qnt = (up-low+1) % mod;
			ans += qnt * i;
			unsigned long long u = sum(low,up,1);
			u %= mod;
			ans += b*u;
			ans %= mod;*/

		}

		printf("%I64d\n",ans);

}