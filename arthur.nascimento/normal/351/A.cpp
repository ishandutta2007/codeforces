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

main(){

		int n;
		scanf("%d",&n);
		int z=0;
		double sum = 0;

		for(int i=0;i<2*n;i++){
			double d;
			scanf("%lf",&d);
			if(d == (int)d)
				z++;
			sum += d - (int)d;
			}

		double ans = 10000;
		for(int i=0;i<=n;i++)
			if( 2*n-z >= i  && z >= n-i)
				ans = min(ans,fabs(sum-i));


		printf("%.3lf\n",ans);

}