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

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;}

int dp[20][300300];
int dmin[20][300300];

int v[300300];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		for(int i=0;i<n;i++)
			dp[0][i] = dmin[0][i] = v[i];

		for(int i=1;i<19;i++)
			for(int j=0;j<n;j++)
				dp[i][j] = gcd(dp[i-1][j], dp[i-1][min(n-1,j+(1<<(i-1)))]),
				dmin[i][j] = min(dmin[i-1][j], dmin[i-1][min(n-1,j+(1<<(i-1)))]);
		//		debug("i = %d j = %d dp = %d min = %d\n",i,j,dp[i][j],dmin[i][j]);

		int a=1,b=n;
		int lg;

		while(a != b){

			
			int m = (a+b+1)/2;
			

			int ok = 0;

			lg = -1;

			for(int i=1;i<m;i*=2)
				lg++;

			debug("%d %d %d %d\n",a,b,m,lg);	
			
			for(int i=0;i<=n-m;i++)
				if(gcd(dp[lg][i], dp[lg][min(n-1,i+m-(1<<(lg)))]) == min(dmin[lg][i], dmin[lg][min(n-1,i+m-(1<<(lg)))]))
					ok = 1;

			debug("%d\n",ok);
			if(ok)
				a = m;
			else
				b = m-1;

		}

		int qnt = 0;

		lg = -1;
		for(int i=1;i<a;i*=2)
				lg++;

		if(a == 1){
			printf("%d 0\n",n);
			for(int i=0;i<n;i++)
				printf("%d ",i+1);
			return 0;}

		for(int i=0;i<n-a+1;i++)	
			if(gcd(dp[lg][i], dp[lg][i+a-(1<<(lg))]) == min(dmin[lg][i], dmin[lg][i+a-(1<<(lg))]))
					qnt++;

		printf("%d %d\n",qnt,a-1);

		for(int i=0;i<n-a+1;i++)	
			if(gcd(dp[lg][i], dp[lg][i+a-(1<<(lg))]) == min(dmin[lg][i], dmin[lg][i+a-(1<<(lg))]))
				printf("%d ",i+1);

		}