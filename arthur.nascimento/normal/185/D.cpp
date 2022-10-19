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

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

int p;

long long exp(long long a,long long b,int md=p){
	if(b == 0)
		return 1;
	if(b == 1)
		return a%md;
	long long k = exp(a,b/2,md);
	k = (k*k) % md;
	if(b%2)
		k = (k*a) % md;
	return k;
}

long long inv(long long x){
	return exp(x,p-2);
}

long long pg(long long x,long long t){
	debug("pg %I64d %I64d\n",x,t);
	if(x%p == 0)
		return inv(1-x);
	if(x == 1)
		return exp(2,t+1);
	debug("!");
	return (((exp(x,exp(2,t+1,p-1))+p-1)%p) * inv(x-1) ) % p;
}

main(){

		int t;
		scanf("%d",&t);

		while(t--){

			long long k,l,r;
			cin >> k >> l >> r >> p;

			long long x = exp(k,exp(2,l,p-1));
			if(k%p == 0)
				x = 0;

			long long ans = pg(x,r-l);

			if(0)
				ans = ans * inv(pg(k,l-1));

			if(k&1)
				ans = ans * inv(exp(2,r-l));

			cout << ans % p << endl;

		}

}