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

int dp[25][1001000];

int prof[1001000];

int dist(int a,int b){
			
		if(prof[a] > prof[b])
			swap(a,b);

		int dh = prof[b]-prof[a];

		int ans = 0;

		for(int i=24;i>=0;i--)
			if(dh&(1<<i)){
				b = dp[i][b];
				ans += (1<<i);
				}

		if(a==b)
			return ans;

		for(int i=24;i>=0;i--){

			if(dp[i][a] != dp[i][b]){

				a = dp[i][a];
				b = dp[i][b];
				ans += 2 * (1<<i);
				
				}
		


			}

		debug("dist %d %d = %d\n",a,b,2+ans);
		return 2 + ans;
		
}

main(){

		int q;
		scanf("%d",&q);

		int n = 4;

		prof[0] = 0;

		prof[1]=prof[2]=prof[3] =1;
	

		for(int i=1;i<=3;i++)
			dp[0][i] = 0;

		int A = 1;
		int B = 2;

		for(int i=0;i<q;i++){

			int v;
			scanf("%d",&v);

			v--;

			dp[0][n] = v;
			dp[0][n+1] = v;

			prof[n] = prof[n+1] = 1 + prof[v];
			
			for(int i=1;i<25;i++)
				dp[i][n+1] = dp[i][n] = dp[i-1][dp[i-1][n]];
				
			if(A == v)
				A = n;

			if(B == v)
				B = n;

			n += 2;

			if(dist(n-1,A) > dist(A,B))
				B = n-1;

			if(dist(n-1,B) > dist(A,B))
				A = n-1;

			printf("%d\n",dist(A,B));


			}

		}