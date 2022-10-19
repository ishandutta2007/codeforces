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

long long dp[55][55][55][55];
int n;

int v[55];
int f[55];

long long get(int p,int k,int t,int f){

	if(t < 0 || k < 0)
		return 0;

	if(dp[p][k][t][f]+1)
		return dp[p][k][t][f];

	if(p == n){
		if(k)
			return 0;
		if(t >= v[f])
			return 0;
		return 1;
		}

	if(p == f)
		return dp[p][k][t][f] = get(p+1,k,t,f);

	return dp[p][k][t][f] = get(p+1,k,t,f) + get(p+1,k-1,t-v[p],f);

}

main(){

		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		int t;
		scanf("%d",&t);

		int s=0;
		for(int i=0;i<n;i++)
			s += v[i];

		if(s <= t){
			printf("%d\n",n);
			return 0;}

		memset(dp,-1,sizeof(dp));

		double ans = 0;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
			
				long long qnt = get(0,i,t,j);

				debug("i=%d j=%d qnt=%I64d\n",i,j,qnt);

				memset(f,0,sizeof(f));

				for(int k=2;k<=i;k++)
					f[k]++;
				for(int k=2;k<=n-i-1;k++)
					f[k]++;
				for(int k=2;k<=n;k++)
					f[k]--;

				double K = 1;

				for(int k=2;k<=n;k++){
					while(f[k] > 0)
						K *= k,
						f[k]--;
					while(f[k] < 0)
						K /= k,
						f[k]++;	
					}

				ans += i * qnt * K;
			}

		printf("%lf\n",ans);

	}