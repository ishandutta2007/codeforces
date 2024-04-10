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

int dp[22][1<<(20)];

int n,m;

int usa[22];
int v[220];

char t[22];
int q[22];

int log3[1<<21];

int get(int p,int mask){

	if(p == n)
		return 0;

	if(dp[p][mask]+1)
		return dp[p][mask];

	int ret = (q[p] == 1) ? -999999999 : 999999999;

	if(t[p] == 'p'){

		int y = (~mask) & ((1<<n)-1);
		y = log3[y&-y];


		int u = get(p+1, mask ^ (1<<y));

		if(q[p] == 1)
			ret = max(ret, u - v[y]);
		else
			ret = min(ret, u + v[y]);


		return dp[p][mask] = ret;

			}

	for(int j=(~mask)&((1<<n)-1); j; j -= j&-j){
			int i = log3[j&-j];


			int u = get(p+1, mask ^ (1<<i));

			if(q[p] == 1)
				ret = max(ret, u - (t[p] == 'p' ? v[i] : 0));
			else
				ret = min(ret, u + (t[p] == 'p' ? v[i] : 0));


			}

	if(t[p] == 'b')
		if(q[p] == 1)
			ret = max(ret, get(p+1, mask));
		else
			ret = min(ret, get(p+1, mask));

	return dp[p][mask] = ret;

}

main(){

		for(int i=0;i<20;i++)
			log3[1<<i] = i;
		
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i),
			v[i]*=-1;

		sort(v,v+n);

		scanf("%d",&n);

		memset(dp,-1,sizeof(dp));

		for(int i=0;i<n;i++)
			scanf(" %c %d\n",t+i,q+i);

		while(t[n-1] == 'b')
			n--;

		printf("%d\n",get(0,0));

}