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
#define maxn 2001000

using namespace std;

int f[maxn];

int dp[20][maxn];

int get(int p,int mask){

	if(p == 20) return f[mask];
	if(dp[p][mask]+1) return dp[p][mask];

	if(mask & (1<<p))
		return dp[p][mask] = get(p+1,mask);
	return dp[p][mask] = get(p+1,mask) + get(p+1,mask|(1<<p));

}

int p2(int n){
	if(n == 0) return 1;
	if(n == 1) return 2;
	long long k = p2(n/2);
	k = k*k;
	if(n%2) k = k*2;
	return k%mod;
}

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			f[u]++;
		}

		memset(dp,-1,sizeof(dp));

		long long ans = p2(n);

		debug("%d %d %d\n",get(0,1),get(0,2),get(0,3));

		for(int i=1;i<(1<<20);i++){

			int par = 0;
			for(int j=0;j<20;j++) if(i & (1<<j))
				par ^= 1;

			if(par)
				ans -= p2(get(0,i));
			else
				ans += p2(get(0,i));

			ans = (ans+mod) % mod;
		}

		printf("%I64d\n",ans);

}