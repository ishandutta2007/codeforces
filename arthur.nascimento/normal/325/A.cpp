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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

main(){

	int n;
	scanf("%d%",&n);

	long long maxx = -1,maxy = -1,minx = 999999,miny = 999999;

	long long S = 0;

	for(int i=0;i<n;i++){

		long long xi,xf,yi,yf;
		cin >> xi >> yi >> xf >> yf;

		maxx = max(maxx,xf);
		minx = min(minx,xi);
		maxy = max(maxy,yf);
		miny = min(miny,yi);

		S += (xf-xi) * (yf-yi);


		}

	if( (maxx-minx)*(maxy-miny) == S && (maxx-minx) == (maxy-miny))
		printf("YES\n");
	else
		printf("NO\n");

	}