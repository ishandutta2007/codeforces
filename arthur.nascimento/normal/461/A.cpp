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
#endif

#define pb push_back
#define mod 1000000007
#define maxn 300300

using namespace std;

int v[maxn];

main(){

		int n;
		scanf("%d",&n);

		long long ans = 0;
		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		sort(v,v+n);

		if(n == 1){
			printf("%d\n",v[0]);
			return 0;
		}

		for(int i=0;i<n;i++)
			ans += (long long)(i+2) * v[i];

		ans -= v[n-1];

		printf("%I64d\n",ans);

}