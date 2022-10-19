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
#define maxn 2020
#define mod 1000000007

using namespace std;

int x[maxn];
int y[maxn];

long long dp[maxn];
long long fat[maxn*maxn];

long long exp(long long a,long long b){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long k = exp(a,b/2);
	k = (k*k)%mod;
	if(b%2) k = (k*a) % mod;
	return k;
}

long long inv(long long u){
	return exp(u%mod,mod-2);
}

long long C(int n,int k){
	if(k > n) return 0;
	if(n < 0 || k < 0) assert(0);
	long long ret = (fat[n] * inv(fat[k]*fat[n-k]))%mod;
	return ret;
}

int k;

long long path(int a,int b){
	return C(a+b,b);
}

long long get(int t){

	if(dp[t]+1)	return dp[t];

	long long ret = path(x[t],y[t]);

	for(int i=0;i<k;i++) if(x[i] <= x[t] && y[i] <= y[t] && i != t){
		ret -= (path(x[t]-x[i],y[t]-y[i]) * get(i))%mod; 
		if(ret < 0) ret += mod;
	}

	return dp[t] = ret;

}
	
main(){

		int n,m;
		scanf("%d%d%d",&n,&m,&k);

		for(int i=0;i<k;i++)
			scanf("%d%d",x+i,y+i), x[i]--, y[i]--;
		
		memset(dp,-1,sizeof(dp));

		fat[0] = 1;
		for(int i=1;i<=n+m;i++)
			fat[i] = (fat[i-1]*i) % mod;

		x[k] = n-1;
		y[k] = m-1;
			
		cout << get(k) << endl;

}