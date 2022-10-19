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
int p[110];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		sort(v,v+n);

		int ans = n;

		for(int i=n-1;i>=1;i--){

			memset(p,127,sizeof(p));

			int ok = 1;
			int pos = 0;
			
			for(int j=n-1;j>=0;j--){
				if(p[pos] == 0)
					ok = 0;

			/*	if(p[pos] == v[j])
					p[pos]--;
				else
					p[pos] = v[j];*/

				p[pos] = min(p[pos]-1, v[j]);
					
				pos = (pos+1) % i;
				}

			if(ok)
				ans = i;

			}

		printf("%d\n",ans);}