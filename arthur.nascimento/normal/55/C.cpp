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
#define eps 1e-7
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

main(){

		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);

		string ans = "NO";
		
		for(int i=0;i<k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(min(min(x-1,y-1),min(n-x,m-y)) <= 4)
				ans = "YES";
			}

		cout << ans << endl;

}