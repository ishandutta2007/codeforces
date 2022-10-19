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
#define mod 1000000007
#define maxn 100100

using namespace std;

int n;
int dp[33][33][2];

int get(int pos,int rep,int ok){

	if(pos == -1) return 1;
	
	if(dp[pos][rep][ok]+1)
		return dp[pos][rep][ok];

	int u = n & (1<<pos);

	long long ret = 0;

	int a = ok;
	if(u) a = 1;
	ret = (1LL<<(rep-1)) * get(pos-1,rep,a);

	if(ok || u){

		ret += (1LL<<(rep-1)) * get(pos-1,rep,ok);
		ret += get(pos-1,rep+1,ok);

	}

	debug("dp[%d][%d][%d] = %d\n",pos,rep,ok,ret);
	return dp[pos][rep][ok] = ret%mod;

}

main(){

		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		
		int u = -1;
		int aux = 1;
		while(aux <= n) aux *= 2, u++;

		int ans = get(u-1,1,0) + 1;

		for(int i=u-1;i>=0;i--)
			ans = (ans + get(i-1,1,1)) % mod;

		printf("%d\n",ans);

}