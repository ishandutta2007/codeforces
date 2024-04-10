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
#define maxn 100100

using namespace std;

main(){

		int n;
		scanf("%d",&n);

		while(n--){

			long long a,b;
			scanf("%I64d%I64d",&a,&b);

			long long ans = 0;

			int dif = 0;
			for(int i=63;i>=0;i--){

				

				if(dif)
					ans += 1LL << i;
				else
					ans += (a & (1LL<<i));

				if( (a&(1LL<<i)) != (b&(1LL<<i))) dif = 1;	

			}

			if(__builtin_popcountll(b) > __builtin_popcountll(ans)) ans = b;

			printf("%I64d\n",ans);

		}

}