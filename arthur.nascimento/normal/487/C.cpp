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

int gcd(int a,int b){
	return b?gcd(b,a%b):a;}

long long exp(long long a,long long b,long long m){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long k = exp(a,b/2,m);
	k = (k*k) % m;
	if(b%2) k = (k*a) % m;
	return k;
}

int foi[100100];
int ans[100100];

main(){

		int n;
		cin >> n;

		int phi = 0;

		for(int i=1;i<n;i++)
			if(gcd(i,n) == 1) phi++;

		debug("phi = %d\n",phi);

		if(n == 4){
			printf("YES\n");
			printf("1 3 2 4\n");
			return 0;
		}


		int ok = 1;
		long long pi = 1;

		for(int i=0;i<n-1;i++){

			debug("i = %d pi = %I64d\n",i,pi);

			long long ee = exp(pi,phi-1,n);
			debug("%I64d ^ %d = %d\n",pi,phi-1,ee);
			long long x = (long long)(i+1) * ee;
			x %= n;

			debug("x = %I64d\n",x);

			if(foi[x]++) ok = 0;

			ans[i] = x;

			pi = (pi*x) % n;

		}

		ans[n-1] = n;

		if(!ok){
			printf("NO\n");
			return 0;
		}

		printf("YES\n");

		for(int i=0;i<n;i++)
			printf("%d\n",ans[i]);
		printf("\n");

}