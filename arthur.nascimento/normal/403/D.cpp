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
#define maxn 1010
using namespace std;

int dp[45][1010][1010];
long long sum[2][1010][1010];

long long fat[2020];

main(){

		fat[0] = 1;
		for(int i=1;i<2020;i++)
			fat[i] = (fat[i-1]*i)%mod;

		for(int i=0;i<maxn;i++)
			for(int j=0;j<maxn;j++)
				dp[0][i][j] = 1,
				sum[0][i][j] = i+1;

		for(int k=1;k<45;k++){

			for(int i=0;i<maxn;i++)
				for(int j=0;j<maxn;j++)
					sum[k%2][i][j] = 0;
		
			for(int m=1;m<maxn;m++)
				for(int sz=1;sz<maxn;sz++){

					dp[k][sz][m] = dp[k][sz][m-1];

					if(sz >= m)
						dp[k][sz][m] = (sum[(k-1)%2][sz-m][m-1] + dp[k][sz][m-1]) % mod;

					sum[k%2][sz][m] = sum[k%2][sz-1][m] + dp[k][sz][m];

					if(sum[k%2][sz][m] > mod)
						sum[k%2][sz][m] -= mod;

					}

				}

		int t;
		scanf("%d",&t);		
			

		while(t--){

			int n,k;
			scanf("%d%d",&n,&k);
			
			if(k >= 45)
				printf("0\n");
			else
				printf("%d\n",(fat[k]*dp[k][n][n])%mod);

		}


}