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

#define inf (9999999999999999LL)
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
#define maxn 10100

using namespace std;

int d[100100];
int h[100100];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<k;i++)
			scanf("%d%d",d+i,h+i);

		int ok = 1;
		int ans = h[0];

		ans = h[0] + d[0] - 1;
		ans = max(ans, h[k-1] + n - d[k-1]);

		for(int i=1;i<k;i++){

			int u = abs(h[i]-h[i-1]);
			if(u > d[i]-d[i-1]) ok = 0;
			ans = max(ans,max(h[i],h[i-1]) + (d[i]-d[i-1]-u)/2);

		}

		if(ok)
			printf("%d\n",ans);
		else
			printf("IMPOSSIBLE\n");
	
		}