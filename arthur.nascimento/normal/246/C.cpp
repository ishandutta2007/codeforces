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

int v[55];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		sort(v,v+n);

		for(int i=0;k;i++)
			for(int j=0;j+i<n && k;j++){
				printf("%d ",i+1);
				for(int l=n-i;l<n;l++)
					printf("%d ",v[l]);
				printf("%d\n",v[j]);
			k--;
			}


		}