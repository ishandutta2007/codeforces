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
#define eps 1e-12
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		int ans = 0;
		int t = 0;
	
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			if(a > t){
				ans++;
				t = m;
			}
			t -= a;
		}

		printf("%d\n",ans);

}