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

#define pb push_back
 
using namespace std;

long long dp[64][64];

int ones(long long n){
	int ret = 0;
	while(n)
		n -= n&-n, ret++;
	return ret;
}

long long C(int n,int k){
	debug("C %d %d\n",n,k);
	if(k > n || k < 0)
		return 0;
	if(dp[n][k]+1)
		return dp[n][k];
	if(k == 0)
		return 1;
	if(n == 0)
		return 0;
	long long ret = C(n-1,k-1) + C(n-1,k);
	debug("C(%d,%d) = %I64d\n",n,k,ret);
	return dp[n][k] = ret;
}

main(){

		long long m;
		int k;
		scanf("%I64d%d",&m,&k);

		long long a=1, b=1LL<<62;

		memset(dp,-1,sizeof(dp));

		while(a-b){

			long long mid = (a+b)/2;
			debug("a = %I64d b = %I64d mid = %I64d\n",a,b,mid);

			int u = 0;
			while((1LL<<u) <= mid)
				u++;

			long long qnt = (ones(mid) == k) ? 1 : 0;
			int q1 = 0;

			debug("u = %d\n",u);
			debug("qnt = %I64d\n",qnt);
	
			for(int i=u-1;i>=0;i--){

				 if(mid&(1LL<<i)){
				 	q1++;
				 	continue;
				 }

				 qnt += C(i,k-q1-1);

			}

			q1 = 1;

			debug("qnt = %I64d\n",qnt);

			for(int i=u-1;i>=0;i--){

				if(((2*mid)&(1LL<<i)) == 0)
					continue;
				
				qnt += C(i,k-q1);

				q1++;

			}

			debug("qnt = %I64d\n",qnt);

			if(qnt >= m)
				b = mid;
			else
				a = mid+1;

		}

		printf("%I64d\n",a);

}