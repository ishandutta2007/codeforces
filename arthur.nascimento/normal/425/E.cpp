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

long long dp[2][550][550];
long long pot[550];

main(){

		pot[0] = 1;
		
		for(int i=1;i<550;i++)
			pot[i] = (pot[i-1]*2) % mod;

		int n,k;
		scanf("%d%d",&n,&k);
		int t1 = clock();

		for(int last=0;last<=n;last++)
			for(int qnt=0;qnt<=k;qnt++)
				dp[(n+1)%2][last][qnt] = qnt ? 0 : 1;

		for(int pos=n;pos>=1;pos--)
			for(int last=0;last<pos;last++)
				for(int qnt=0;qnt<=k;qnt++){

					int ql = last;
					int qr = pos-last;
					
					dp[pos%2][last][qnt] = (dp[(pos+1)%2][last][qnt] * pot[ql]) % mod;
					
					if(qnt){
						dp[pos%2][last][qnt] += (((dp[(pos+1)%2][pos][qnt-1] * pot[ql]) % mod) * (pot[qr]-1)) % mod;
						if(dp[pos%2][last][qnt] >= mod)
							dp[pos%2][last][qnt] -= mod;
						}

					debug("dp[%d][%d][%d] = %I64d\n",pos,last,qnt,dp[pos%2][last][qnt]);

					}

		printf("%I64d\n",dp[1][0][k]);

}