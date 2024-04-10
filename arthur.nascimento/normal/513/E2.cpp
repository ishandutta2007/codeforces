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

#define inf (9999999999999999LL)
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
#define maxn 10100

using namespace std;

int v[30300];
int dp[2][2][220][30300];
int foi[2][2][220][30300];

int n;

int get(int,int,int);

int get(int t,int r,int k,int p){

	if(foi[t][r][k][p])
		return dp[t][r][k][p];

	if(k == 0) return 0;
	int end = (k == 1) ? 0 : 1;
	if(p == n) return -999999999;

	int ret = -999999999;

	int sig = t ? 1 : -1;
	int s=v[p];


	int u;
	if(r == 1) u = s*(-end+sig);
	else u = s*(end+sig);
	
	ret = get(r,k-1,p+1) + u;
	ret = max(ret,u+get(t,r,k,p+1));

	foi[t][r][k][p] = 1;
	debug("dp[%d][%d][%d][%d] = %d\n",t,r,k,p,ret);
	return dp[t][r][k][p] = ret;

}

int get(int t,int k,int p){
	return max(get(t,0,k,p),get(t,1,k,p));
}

main(){

		int k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		int a = v[0], b = v[0];
		int ans = 0;

		for(int i=1;i<n;i++){

			ans = max(ans, get(0,k-1,i) + a);
			ans = max(ans, get(1,k-1,i) - b);

			a = max(a+v[i],v[i]);
			b = min(b+v[i],v[i]);

		}

		cout << ans << endl;

}