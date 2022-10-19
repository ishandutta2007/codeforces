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
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define mod 1000000007 

using namespace std;

int q[3][2] = {
0,2,
1,1,
1,0
};

long long fat[200200];

long long exp(long long a,int b){
	if(b==1)return a;
	long long k = exp(a,b/2);	
	k = (k*k)%mod;
	if(b%2)
		k = (k*a)%mod;
	return k;
}

long long inv(long long n){
	return exp(n%mod,mod-2);}

long long C(int n,int k){
	return (fat[n]*inv(fat[k]*fat[n-k]))%mod;}

main(){

		int n,m,g;
		scanf("%d%d%d",&n,&m,&g);

		fat[0] = 1;

		for(int i=1;i<200200;i++)
			fat[i] = (fat[i-1]*i)%mod;

		long long ans = 0;

		for(int i=0;i<3;i++){

			n -= q[i][0];
			m -= q[i][1];

			debug("n=%d m=%d\n",n,m);

			for(int a=0;a<=n;a++){

				int b = m-a;
				int c = (n-a)/2;
				if((n-a)%2 == 1)
					continue;
				if(c < 0 || b < 0)
					continue;

				long long S = C(a+b+c,a);
				
				if(S < 0)
					debug("! %d %d\n",a+b+c,a);
					
				S = (S * C(b+c,b)) % mod;
				
				if(S < 0)
					debug("!!\n");
					
				ans += S;
				ans %= mod;
				if(ans < 0)
					debug("!!!\n");
				}

			n += q[i][0];
			m += q[i][1];

		}

		if(g)
			ans = (mod - ans + C(n+m,n)) % mod;

		printf("%d\n",(int)ans);

}