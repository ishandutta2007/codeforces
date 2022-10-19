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

struct fr {
	int mask,p,qnt;
	bool operator<(fr comp)const{
		return qnt < comp.qnt;}
}

v[110];

long long dp[1<<20];

main(){

		int n,m;
		long long b;
		scanf("%d%d%I64d",&n,&m,&b);

		for(int i=0;i<n;i++){

			int j;
			scanf("%d%d%d",&v[i].p,&v[i].qnt,&j);

			while(j--){
				int k;
				scanf("%d",&k), k--;
				v[i].mask |= (1<<k);
			}

		}


		sort(v,v+n);

		for(int i=0;i<(1<<m);i++)
			dp[i] = 1LL<<60;

		dp[0] = 0;
			
		long long ans;

		for(int i=0;i<n;i++){
			for(int j=(1<<m)-1;j>=0;j--)
				dp[j] = min(dp[j], v[i].p + dp[j^(j&v[i].mask)]);

			if(i == 0)
				ans = dp[(1<<m)-1] + b * v[i].qnt;
			else
				ans = min(ans,dp[(1<<m)-1] + b * v[i].qnt);

			}

		int t = 0;

		for(int i=0;i<n;i++)
			t |= v[i].mask;

		if(t != (1<<m) - 1)
			printf("-1\n");
		else
			printf("%I64d\n",ans);

	}