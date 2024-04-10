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
 
using namespace std;

int v[2020];

int dp[2020][2020];
int n;
long long m;

int get(int l,int p){

	if(dp[l+1][p]+1)
		return dp[l+1][p];

	if(p == n)
		return 0;

	int ret = 1+get(l,p+1);

	if(l == -1 || abs(v[p]-v[l]) <= m*(p-l))
		ret = min(ret, get(p,p+1));

	debug("dp[%d][%d] = %d\n",l,p,ret);
	return dp[l+1][p] = ret;

}

main(){

		int k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		long long a=0, b=2000000000;

		while(a != b){

			m = (a+b)/2;

			memset(dp,-1,sizeof(dp));

			debug("m=%d %d\n",m,get(-1,0));
			if(get(-1,0) <= k)
				b = m;
			else
				a = m+1;

			}

		printf("%d\n",a);

	}