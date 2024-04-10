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

#define inf (1LL<<60)
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
#define x second.first
#define y second.second

using namespace std;

int v[100100];	

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		double ans = 0;

		for(int i=0;i<m;i++){
			int a,b,p;
			scanf("%d%d%d",&a,&b,&p), a--, b--;
			if(p)
				ans = max(ans, (double)(v[a]+v[b]) / p);
		}

		printf("%.9llf\n",ans);

}