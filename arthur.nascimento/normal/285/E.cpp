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
#define maxn 1010
#define mod 1000000007

using namespace std;

long long dp[4][maxn][maxn];

long long get(int t,int n,int k){
	
	if(k < 0 || k > n) return 0;
	if(n == 1){
		if(k != 0) return 0;
		return t ? 0 : 1;
	}
	
	if(dp[t][n][k]+1)
		return dp[t][n][k];
		
	int ret;
	
	if(t == 0)
		ret =  dp[t][n][k] = (get(0,n-1,k) + get(1,n-1,k) + get(2,n-1,k) + get(3,n-1,k)) % mod;
	if(t == 1)
		ret =  dp[t][n][k] = get(0,n-1,k-2);
	if(t == 2)
		ret =  dp[t][n][k] = (2LL*get(1,n-1,k) + get(2,n-1,k) + get(2,n-1,k-1) + 2LL*get(3,n-1,k-1)) % mod;
	if(t == 3)
		ret =  dp[t][n][k] = ( get(0,n-1,k) * (n-k-2) + get(0,n-1,k+1) * (k+1) + get(1,n-1,k) * (n-k-1) + get(1,n-1,k+1) * (k-1) + get(2,n-1,k) * (n-k-2) 
					+ get(2,n-1,k+1) * k + get(3,n-1,k) * (n-k-3) + get(3,n-1,k+1) * (k+1) ) % mod;
	
	debug("get %d %d %d -> %d\n",t,n,k,ret);
	return ret;			
}

main(){
	
	memset(dp,-1,sizeof(dp));
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",(int)((get(0,n,k)+get(1,n,k)+get(2,n,k)+get(3,n,k))%mod));

}