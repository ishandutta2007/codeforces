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

int v[330];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);


		for(int i=0;i<n;i++){

			while(v[i]){
				printf("P");
				if(i)
					printf("LR");
				else
					printf("RL");
				v[i]--;
				}


			if(i != n-1)
				printf("R");

}
			}