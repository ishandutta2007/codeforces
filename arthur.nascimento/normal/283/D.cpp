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
#define maxn 100100

using namespace std;

long long v[5050];
int t[5050];

int dp[5050];

int get(int p){

	if(dp[p]+1)
		return dp[p];

	if(p == 0)
		return 0;

	int ret = p;

	for(int i=p-1;i>=0;i--){

		debug("p=%d i=%d\n",p,i);

		if(v[i]%v[p])
			continue;
		
		if(t[p] > p-i-1 && t[i] != t[p] - p + i)
			continue;

		ret = min(ret,get(i) + p - i - 1);

	}

	debug("dp[%d] = %d\n",p,ret);
	return dp[p] = ret;

}	

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%I64d",v+i);
			while(v[i]%2 == 0)
				v[i] /= 2, t[i]++;
		}

		memset(dp,-1,sizeof(dp));

		int ans = n;

		for(int i=n-1;i>=0;i--)
			ans = min(ans,get(i)+n-i-1);

		printf("%d\n",ans);

	}