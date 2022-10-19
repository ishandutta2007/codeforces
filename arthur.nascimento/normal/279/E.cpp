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
#define eps 1e-7
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

char v[1001000];

main(){

		int ans = 0;
		scanf(" %s",v);

		int p=0;
		int n = strlen(v);

		while(p < n){

			int k=p;
			int q0=0, q1=0;
			while(k < n){

				if(v[k] == '0')
					q0++;
				else
					q1++;
					
				k++;

				if(k == n)
					break;
				
				if(k >= 2 && v[k-1] == '0' && v[k-2] == '0'){
					q0 -= 2;
					break;
					}
					
				}

			if(k == n){
				if(v[k-1] == '0')
					q0--;
				if(k >= 2 && v[k-2] == '0' && v[k-1] == '0')
					q0--;
				}

			ans += min(2+q0,q1);

			p = k;

			}

		printf("%d\n",ans);

	}