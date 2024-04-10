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

#define inf (999999999999LL)
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

int v[1010];

main(){

		int n,l;
		scanf("%d%d",&n,&l);

		for(int i=0;i<n;i++) scanf("%d",v+i);

		sort(v,v+n);

		long double ans = (long double)max(v[0],l-v[n-1]);

		for(int i=1;i<n;i++)
			ans = max(ans,(long double)(v[i]-v[i-1])/2);

		printf("%.9lf\n",(double)ans);

}