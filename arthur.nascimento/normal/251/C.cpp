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

int k;

int st(int y,int low){

	int p = 0;

	while(y-low){
			int best = y-1;
			for(int i=2;i<=k;i++)
				if(y-y%i >= low)
					best = min(best,y-y%i);
			y = best;
			p++;
		}

	return p;

}

main(){

		long long a,b;
		scanf("%I64d%I64d%d",&a,&b,&k);

		long long qnt = a/360360 - b/360360 - 1;

		long long ans = st(360360,0) * qnt + st(360360,b%360360) + st(a%360360,0);

		if(qnt == -1)
			ans = st(a%360360,b%360360);

		printf("%I64d\n",ans);
		
}