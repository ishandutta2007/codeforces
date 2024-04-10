#include <iostream>
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

#define INF (1<<30)
#define pii pair<int,int>
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define mod 1000000009

using namespace std;

long long exp2(long long n){

	if(n == 0)
		return 1;
	if(n == 1)
		return 2;

	long long k = exp2(n/2);

	k = (k*k)%mod;

	if(n%2)
		k = k*2;

	return k%mod;

	}



main(){
    
   int n,m,k;
   scanf("%d%d%d",&n,&m,&k);

   if(k == 1){

	printf("%d\n",(int)(exp2((long long)m+1)-2+mod)%mod);
	return 0;

   }

   long long p = n - n/k;

   long long e = max(0LL,m-p);

   long long resp = (exp2(e+1) - 2 + mod) % mod;

   resp = (resp*k)%mod;

   m -= e*(k);

   resp = (resp + m)%mod;

   printf("%d\n",(int)resp);

    
}