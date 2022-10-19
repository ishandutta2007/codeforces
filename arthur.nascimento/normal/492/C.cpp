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

main(){

		int n,r,avg;

		scanf("%d%d%d",&n,&r,&avg);

		long long need = (long long) avg * n;

		vector<pii> v;

		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			need -= a;
			v.pb(pii(b,a));
		}

		sort(v.begin(),v.end());

		long long ans = 0;

		for(int i=0;i<n;i++) if(need > 0){

			long long tem = r - v[i].second;
			int pega = min(tem,need);
			need -= pega;
			ans += (long long)v[i].first * pega;

		}

		printf("%I64d\n",ans);

}