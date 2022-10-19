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

#define max3(a,b,c) max(max(a,b),c)

using namespace std;

long long v[100100];
int c[100100];

long long dp[2][100100];
long long best1[100100];

long long best0[2];
int cor[2];

main(){

		int n,q;
		scanf("%d%d",&n,&q);

		for(int i=0;i<n;i++)
			scanf("%I64d",v+i);

		for(int i=0;i<n;i++)
			scanf("%d",c+i);

		while(q--){

			long long A,B;
			scanf("%I64d%I64d",&A,&B);

			for(int i=0;i<=n;i++)
				best1[i] = 0;

			best0[0] = best0[1] = 0;

			for(int i=n-1;i>=0;i--){

				long long a = best1[c[i]];
				long long b = best0[0];

				if(cor[0] == c[i])
					b = best0[1];

				dp[0][i] = B*v[i] + max3(a,b,0LL);
				dp[1][i] = A*v[i] + max3(a,b,0LL);

				best1[c[i]] = max(best1[c[i]], dp[1][i]);

				if(dp[0][i] > best0[0]){
					if(c[i] != cor[0])
						best0[1] = best0[0],
						cor[1] = cor[0];
					best0[0] = dp[0][i],
					cor[0] = c[i];
				}

				else if(dp[0][i] > best0[1] && c[i] != cor[0])
					best0[1] = dp[0][i],
					cor[1] = c[i];

			}

			long long ans = 0;
			for(int i=0;i<n;i++)
				ans = max(ans, dp[0][i]);

			printf("%I64d\n",ans);

		}

}