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

#define pb push_back

using namespace std;

double v[110];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%lf",v+i);

		sort(v,v+n);
		reverse(v,v+n);

		double ans = 0;

		for(int i=0;i<n;i++){

			double cur = 0;

			for(int j=0;j<=i;j++){
				double a = v[j];
				for(int k=0;k<=i;k++)
					if(k-j)
						a *= (1.0-v[k]);
				cur += a;
			}

			ans = max(ans, cur);

		}

		printf("%.9lf\n",ans);

}