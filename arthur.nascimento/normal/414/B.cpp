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

long long dp[2020][2020];
int n,k;

long long get(int pr,int pos){

	if(pos == k)
		return 1;

	if(dp[pr][pos]+1)
		return dp[pr][pos];

	long long ret = 0;
	for(int i=1;pr*i<=n;i++)
		ret += get(pr*i,pos+1);

	return dp[pr][pos] = ret % mod;

}

main(){

		memset(dp,-1,sizeof(dp));

		scanf("%d%d",&n,&k);

		printf("%I64d\n",get(1,0) % mod);

	}