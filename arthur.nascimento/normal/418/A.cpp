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

int foi[1010][1010];

pii ans[1010*1010];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		if(k > (n-1)/2){
			printf("-1\n");
			return 0;}

		int cont = 0;

		for(int i=0;i<n;i++){

			int p = k;
			for(int j=0;j<n && p;j++){

				if(i == j)
					continue;

				if(!foi[i][j]){
					ans[cont++] = pii(i,j);
					foi[i][j] = foi[j][i] = 1;
					p--;
					}
				

				}

			}

		if(cont != n*k){
			printf("-1\n");
			return 0;
		}


		printf("%d\n",cont);
		for(int i=0;i<n*k;i++)
			printf("%d %d\n",ans[i].first+1, ans[i].second+1);

	}