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

#define inf (999999999)
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
#define maxn 1001000

using namespace std;

int dp[317][200200];
int n,m,x;

int get(int p,int d,int f){

	if(f < 0 || d < 0) return 0;

	if(p == m){
		if(d == 0 && f == 0) return 1;
		return 0;
	}

	if(dp[d][f*m+p]+1) return dp[d][f*m+p];

	long long ret = 0;

	ret += get(p+1,d+1,f-1);
	ret += get(p+1,d,f-1);
	if(p-x) ret += get(p+1,d-1,f);
	if(p-x) ret += get(p+1,d,f);

	return dp[d][f*m+p] = ret%mod;
	
}

main(){

		scanf("%d%d%d",&n,&m,&x),x--;

		memset(dp,-1,sizeof(dp));

		long long fa = 1;
		for(int i=1;i<=n;i++) fa = (fa*i)%mod;

		printf("%I64d\n",(fa*get(0,0,n))%mod);

}