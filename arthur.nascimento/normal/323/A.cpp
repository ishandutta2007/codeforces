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

main(){

		int n;
		scanf("%d",&n);

		if(n%2 == 1){
			printf("-1\n");
			return 0;}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++)
					printf("%c",((max((2*j > n-1) ? (j-n/2+1) : (n/2-j),(2*k > n-1) ? (k-n/2+1) : (n/2-k))%2) ^ (i%2)) ? 'b' : 'w');
					printf("\n");
				}
				printf("\n");}}