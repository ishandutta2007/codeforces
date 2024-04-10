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

#define pb push_back
 
using namespace std;

int ll[2020];

char M[2020][2020];


main(){

		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf(" %c",&M[i][j]);
				if(M[i][j] == 'U' && i%2 == 0)
					ll[j]++;
			}

		for(int j=0;j<m;j++){

			int ans = 0;

			for(int i=0;i<n;i++){
				if(j+i < m && M[i][j+i] == 'L')
					ans++;
				if(j-i >= 0 && M[i][j-i] == 'R')
					ans++;
			}

			printf("%d ",ans+ll[j]);

		}
		printf("\n");

}