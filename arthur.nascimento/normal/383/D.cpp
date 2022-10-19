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
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 1010

using namespace std;

int dp[maxn][20200];
int v[maxn];
int n;

int get(int p,int s){
	if(p == n)
		return (s == 0) ? 1 : 0;
	if(dp[p][s+10100]+1)
		return dp[p][s+10100];
	int ret = 0;
	if(s == 0) ret = 1;
	ret = (ret + get(p+1,s-v[p]) + get(p+1,s+v[p])) % mod;
	debug("dp %d %d = %d\n",p,s,ret);
	return dp[p][s+10100] = ret;
}

main(){

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",v+i);
	int ans = 0;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		ans = (ans + get(i+1,v[i]))%mod;
		if(v[i]) ans = (ans+get(i+1,-v[i])) % mod;
	}
	printf("%d\n",ans);

}