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
#define maxn 55
#define mod 1000000007

using namespace std;

int dp[2][maxn][maxn];

long long C[maxn][maxn];

long long u(int t){
	return t ? t : 1;
}

long long mul(int a,int b,int c,int d,int e){
	long long ret = a;
	ret *= b;
	ret %= mod;
	ret *= c;
	ret %= mod;
	ret *= d;
	ret %= mod;
	ret *= e;
	ret %= mod;
	return ret;
}

long long get(int f,int n,int k){

	if(k < 0) return 0;
	if(n == 0)
		return (k == 0 && f == 0) ? 1 : 0;
	if(n == 1){
		if(k || f == 0) return 0;
		return 1;
	}

	if(dp[f][n][k]+1)
		return dp[f][n][k];

	debug("get %d %d %d\n",f,n,k);

	int ret = 0;

	for(int i=1;i<n;i++)
		for(int j=0;j<=k;j++){

			if(f == 0 && j == k) continue;
			int a = i, b = n-i-1;
			int l = j, r = k-j;
			if(f == 0) r--;
	
			if(f){
				ret += mul(get(0,a,l) , get(0,b,r) , C[n-2][a-1] , u(a) , u(b));
				ret %= mod;
				continue;
			}

			debug("a %d b %d l %d r %d C[%d][%d] %d\n",a,b,l,r,n-2,a-1,C[n-2][a-1]);

			ret += mul(get(1,a,l) , get(0,b,r) , C[n-2][a-1] , u(a) , u(b));
			ret %= mod;
			ret += mul(get(0,a,l) , get(1,b,r) , C[n-2][a-1] , u(a) , u(b));
			ret %= mod;
			ret += mul(get(1,a,l) , get(1,b,r) , C[n-2][a-1] , u(a) , u(b));
			ret %= mod;

		}

	debug("dp %d %d %d = %d\n",f,n,k,ret);
	return dp[f][n][k] = ret;
}

main(){

		C[0][0] = 1;
		for(int i=1;i<maxn;i++){
			C[i][0] = 1;
			for(int j=1;j<maxn;j++)
				C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
		
		int n,k;
		scanf("%d%d",&n,&k);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",(get(1,n,k)+get(0,n,k))%mod);

}