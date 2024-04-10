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
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

int v[110];

main(){

		int n;
		int sz = 0;
		scanf("%d",&n);

		int sum=0, ans=0;

		for(int i=0;i<n;i++){

				int k;
				scanf("%d",&k);

				for(int j=0;j<k;j++){
					int u;
					scanf("%d",&u);
					sum += u;
					if(j < k/2)
						ans += u;
					if(k%2 == 1 && j == (k-1)/2)
						v[sz++] = -u;
					}

			}

		sort(v,v+sz);

		for(int i=0;i<sz;i++)
			if(i%2 == 0)
				ans -= v[i];

		printf("%d %d\n",ans,sum-ans);

	}