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

int dp[2][3030];

int a[3030];
int b[3030];
int c[3030];

int n;

int get(int t,int p){
	if(dp[t][p]+1)
		return dp[t][p];

	if(p == n)
		return t ? 0 : -9999999;

	if(t)
		return dp[t][p] = max(get(1,p+1)+b[p], get(0,p+1) + c[p]);
	else
		return dp[t][p] = max(get(1,p+1)+a[p], get(0,p+1) + b[p]);

}

main(){

		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<n;i++)
			scanf("%d",b+i);
		for(int i=0;i<n;i++)
			scanf("%d",c+i);

		memset(dp,-1,sizeof(dp));

		printf("%d\n",get(0,0));

}