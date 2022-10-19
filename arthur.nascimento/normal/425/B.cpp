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

int v[110][110];
int tmp[110][110];

main(){

		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&v[i][j]);

		if(n > m){

			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					tmp[j][i] = v[i][j];

			swap(n,m);
			
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					v[i][j] = tmp[i][j]; 

			}

		if(n > 10){

			int best = 999999;
			for(int j=0;j<m;j++){

				int cur = 0;

				for(int l=0;l<m;l++){

					int qnt = 0;

					for(int i=0;i<n;i++)
						if(v[i][l] != v[i][j])
							qnt++;

					qnt = min(qnt,n-qnt);
					cur += qnt; 

					}

				best = min(best,cur);

			}

			if(best <= k)
				printf("%d\n",best);
			else
				printf("-1\n");
			return 0;

				}

		int ans = 999999;
		for(int i=0;i<(1<<n);i++){

			int cur = 0;
			
			for(int j=0;j<m;j++){

				int qnt = 0;

				for(int l=0;l<n;l++)
					if((v[l][j]!=0) ^ ((i&(1<<l))!=0))
						qnt++;

				qnt = min(qnt,n-qnt);
				cur += qnt;
			}

			ans = min(ans,cur);
					
		}

		if(ans <= k)
			printf("%d\n",ans);
		else
			printf("-1\n");
		return 0;
		
		
}