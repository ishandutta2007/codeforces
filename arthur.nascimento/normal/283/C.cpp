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

long long v[330];
vector<int> L[330];

int mrk[330];
long long sum[330];
long long tem[330];
int fail;

int dfs(int x,long long depth){

	if(depth > 330){
		fail = 1;
		return 0;
	}

	mrk[x] = 1;
	tem[x] = max(tem[x],depth);

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++){
		dfs(*it,depth+1);
		if(fail) return 0;
	}

}
	

int dp[330][maxn];

int get(int n,long long t){

	if(n == -1){
		if(t == 0)
			return 1;
		return 0;
	}

	if(t < 0)
		return 0;

	if(dp[n][t]+1)
		return dp[n][t];

	long long ret = get(n-1,t) + get(n,t-sum[n]);

	return dp[n][t] = ret % mod;

}		

main(){

		int n,q;
		long long t;
		scanf("%d%d%I64d",&n,&q,&t);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		for(int i=0;i<q;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			L[b].pb(a);
		}

		for(int i=0;i<n;i++){
			memset(mrk,0,sizeof(mrk));
			dfs(i,0);
			for(int j=0;j<n;j++) if(mrk[j]) sum[i] += v[j];
		}

		if(fail){
			printf("0\n");
			return 0;
		}

		for(int i=0;i<n;i++)
			t -= v[i] * tem[i];

		memset(dp,-1,sizeof(dp));

		printf("%d\n",get(n-1,t));

}