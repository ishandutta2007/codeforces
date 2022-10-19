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
#define eps 1e-12
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

char str[30];

main(){

		int k;
		scanf(" %s",str);
		scanf("%d",&k);

		int n = strlen(str);

		for(int i=0;i<n;i++){
		
			int best = i;

			for(int j=i+1;j<n;j++)
				if(str[j] > str[best] && j-i <= k)
					best = j;

			debug("i=%d best=%d\n",i,best);

			for(int j=best-1;j>=i;j--)
				swap(str[j], str[j+1]), k--;

			
			debug("%d\n",k);
		}
		printf("%s\n",str);

}