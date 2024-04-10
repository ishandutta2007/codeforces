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


int dp[110][20200];

int a[110];
int v[110];

int n;

int get(int p,int sum){

	if(sum < 0)
		return -999999999;

	if(p == n)
		return (sum == 10100) ? 0 : -999999999;

	if(dp[p][sum]+1)
		return dp[p][sum];

	return dp[p][sum] = max(get(p+1,sum), get(p+1,sum+v[p]) + a[p]);

}

main(){

		int k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d",a+i);

		for(int i=0;i<n;i++){
			int b;
			scanf("%d",&b);
			v[i] = a[i] - k*b;}

		memset(dp,-1,sizeof(dp));
		printf("%d\n",get(0,10100) ? get(0,10100) : -1);

	}