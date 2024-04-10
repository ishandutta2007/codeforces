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

int tt = 1;

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		int qnt = n/2;

		if(n == 1 && k == 0){
			printf("1\n");
			return 0;
		}

		if(qnt > k || n == 1){
			printf("-1");
			return 0;
		}

		k -= (qnt-1);


		printf("%d %d ",k,2*k);

		for(int i=0;i<qnt-1;i++){

			while(tt == k || tt+1 == k || tt == 2*k || tt+1==2*k)
				tt++;

			printf("%d %d ",tt,tt+1);

			tt += 2;

			}

		while(tt == k || tt+1 == k || tt == 2*k || tt+1==2*k)
				tt++;

		if(n%2)
			printf("%d\n",tt);

	}