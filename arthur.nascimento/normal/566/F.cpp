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
#define maxn 1001000
#define mod 1000000007

using namespace std;

int dp[maxn];
int mrk[maxn];

int get(int n){
	if(!mrk[n]) return 0;
	if(dp[n]+1) return dp[n];
	int ret = 1;
	for(int i=2*n;i<maxn;i+=n)
		ret = max(ret,1+get(i));
	return dp[n] = ret;
}


main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			mrk[u] = 1;
		}

		memset(dp,-1,sizeof(dp));

		int ans = 0;

		for(int i=1;i<maxn;i++) ans = max(ans,get(i));

		printf("%d\n",ans);

}