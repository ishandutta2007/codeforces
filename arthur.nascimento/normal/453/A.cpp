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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#define getchar_unlocked getchar
#endif

#define pb push_back
#define mod 1000000007

using namespace std;

main(){

		int n,m;
		scanf("%d%d",&m,&n);

		double ans = 0;

		for(int i=1;i<=m;i++)

			ans += (double)i * (pow((double)i/m,(double)n)-pow(((double)i-1)/m,(double)n));
			
		printf("%.6lf\n",ans);

}