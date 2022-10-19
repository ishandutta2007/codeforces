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
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

long long dp[330][330];

long long cc[330][330];

int n,m;

long long get(int p,int k){

	if(k <= 0)
		return 0;

	if(p >= n)
		return 1LL<<60;

	if(dp[p][k]+1)
		return dp[p][k];

	long long ret = get(p+1,k);

	for(int i=p;i<n;i++)
		if(cc[p][i] < 1LL<<60)
		ret = min(ret, cc[p][i] + get(i+1,k-i+p-1));

	return dp[p][k] = ret;
		
}

main(){

		int k;
		scanf("%d%d%d",&n,&m,&k);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cc[i][j] = 1LL<<60;

		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--,b--;
			for(int j=a;j<=b;j++)
				cc[a][j] = min(cc[a][j], (long long)c);
		}

		memset(dp,-1,sizeof(dp));

		printf("%I64d\n",(get(0,k) >= 1LL<<60) ? -1 : get(0,k));

}