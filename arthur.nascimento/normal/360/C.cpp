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

#define mod 1000000007

using namespace std;

long long dp[2020][2020];
long long sum[2020][2020];

int v[2020];
char str[2020];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		scanf(" %s",str);

		for(int i=0;i<n;i++)
			v[i] = str[i] - 'a';

		dp[n][0] = 1;
		sum[n][0] = v[n-1];

		for(int j=0;j<=k;j++)
			for(int i=n-1;i>=0;i--){

				dp[i][j] = sum[i+1][j];

				if(j == 0)
					dp[i][j]++;

				int f = 0;

				for(int l=i;l<n;l++){

					if((l-i+1) * (n-l) > j)
						break;

					debug("dp[%d][%d] += dp[%d][%d] * %d\n",i,j,l+1,j-(l-i+1)*(n-l),25-v[l]);
					
					dp[i][j] = (dp[i][j] + dp[l+1][j-(l-i+1)*(n-l)] * (25-v[l])) % mod;

					if(l == n-1)
						f = 1;

				}

				for(int l=n-1;l>=i && !f;l--){

					if((l-i+1) * (n-l) > j)
						break;

					dp[i][j] = (dp[i][j] + dp[l+1][j-(l-i+1)*(n-l)] * (25-v[l])) % mod;

				}

				debug("dp[%d][%d] = %I64d\n",i,j,dp[i][j]);
			
				if(i)
					sum[i][j] = (sum[i+1][j] + dp[i][j] * v[i-1]) % mod;

			}

		printf("%I64d\n",dp[0][k]%mod);

}