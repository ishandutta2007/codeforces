#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<long double,long double>
#define eps 1e-4
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

long long v[1010][1010];

long long dp[4][1010][1010];

int n,m;

long long get(int t,int x,int y){

	if(x < 0 || y < 0 || x >= n || y >= m)
		return -999999999999999LL;

	if(dp[t][x][y]+1)
		return dp[t][x][y];

	if(t == 0){
		if(x == 0 && y == 0)
			return v[x][y];
		return dp[t][x][y] = v[x][y] + max(get(0,x-1,y), get(0,x,y-1));
	}

	if(t == 1){
		if(x == 0 && y == m-1)
			return v[x][y];
		return dp[t][x][y] = v[x][y] + max(get(1,x-1,y), get(1,x,y+1));
	}

	if(t == 2){
		if(x == n-1 && y == 0)
			return v[x][y];
		return dp[t][x][y] = v[x][y] + max(get(2,x+1,y), get(2,x,y-1));
	}

	if(t == 3){
		if(x == n-1 && y == m-1)
			return v[x][y];
		return dp[t][x][y] = v[x][y] + max(get(3,x+1,y), get(3,x,y+1));
	}
}

main(){
	
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%I64d",&v[i][j]);

		long long ans = 0;

		memset(dp,-1,sizeof(dp));

		for(int i=1;i<n-1;i++)
			for(int j=1;j<m-1;j++){
				long long sum = get(0,i,j-1) + get(3,i,j+1) + get(1,i-1,j) + get(2,i+1,j);
				long long sum2 = get(0,i-1,j) + get(3,i+1,j) + get(1,i,j+1) + get(2,i,j-1);
				
				ans = max(ans, max(sum,sum2));
			}

		printf("%I64d\n",ans);

}