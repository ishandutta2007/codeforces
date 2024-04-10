#include <iostream>
#include <iomanip>
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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

long double prob[100100];

long double exp(long double a,int b){

	if(b == 0) return 1;
	if(b == 1) return a;
	long double t = exp(a,b/2);
	t=t*t;
	if(b%2) t = t*a;
	return t;

}

long double dp[2][100100];
long double p[100100];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		prob[1] = (double)n/k;

		int u = n-1;
		int foi = 0;

		while(foi < u && prob[1] > eps){
			foi++;
			prob[1] *= (double)(k-1)/k;
		}
		p[1] = prob[1] * exp((double)(k-1)/k,u-foi);

		for(int i=2;i<=n;i++){

			prob[i] = prob[i-1] * ((long double)(n-i+1)/(i*k));

			u--;
			if(foi == u+1){
				foi = u;
				prob[i] /= (double)(k-1)/k;
			}

			while(foi < u && prob[i] > eps){
				foi++;
				prob[i] *= (double)(k-1)/k;
			}

			p[i] = prob[i] * exp((double)(k-1)/k,u-foi);

			
			debug("cur[%d] = %lf\n",i,(double)prob[i]);
		}
			

		for(int i=1;i<=n;i++){

			prob[i] = p[i];
			debug("prob[%d] = %lf\n",i,(double)prob[i]);
			
		}	

		if(n==1)prob[1] = 1.0f/k;

		if(k == 1){
			for(int i=0;i<n;i++)prob[i] = 0;
			prob[n] = 1;
		}

		long double ans = 0;

		for(int l=1000;l>=1;l--)
			for(int j=1;j<=n;j++)
				dp[l&1][j] = 1.0f/(l+1) * (l+dp[(l&1)^1][j-1]) + (double)(l)/(l+1) * ( (double)(l+1)/2 + dp[l&1][j-1]);

		for(int i=1;i<=n;i++)
			ans += dp[1][i] * prob[i];

		printf("%.9lf\n",(double)ans*k);

}