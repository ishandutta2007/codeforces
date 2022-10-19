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

int n,m;
long long best[25][40][40];
long long ans[25][40][40];
int a[20];
int b[20];

int v[20];

void gera(int p){

	if(p == n){

		int B=0,bmin=0;
		long long cost = 0;

		for(int i=0;i<n;i++){
			B += v[i];
			bmin = min(bmin,B);
			cost += (v[i] == 1) ? a[i] : b[i];
			}

		for(int i=0;i<2*n;i++)
			if(i+bmin >= 0 && i+B < 2*n)
				best[0][i][i+B] = min(best[0][i][i+B], cost);

	return;
	}

	v[p] = 1;
	gera(p+1);
	v[p] = -1;
	gera(p+1);

}

main(){

		
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<n;i++)
			scanf("%d",b+i);

		memset(best,1,sizeof(best));
		memset(ans,1,sizeof(ans));
		gera(0);
		debug("ok\n");

		for(int k=1;k<=24;k++)
			for(int i=0;i<2*n;i++)
				for(int j=0;j<2*n;j++)
					for(int l=0;l<2*n;l++)
						best[k][i][j] = min(best[k][i][j], best[k-1][i][l] + best[k-1][l][j]);

	/*	for(int k=0;k<=3;k++){

			debug("k=%d\n",k);
			for(int i=0;i<2*n;i++){
				for(int j=0;j<2*n;j++)
					debug("%I64d ",best[k][i][j]);
				debug("\n");
				}
				
		}*/


		for(int i=0;i<2*n;i++)
			ans[0][i][i] = 0;

		int cont = 1;

		for(int k=0;k<24;k++)
			if(m & (1<<k)){
			
				for(int i=0;i<2*n;i++)
					for(int j=0;j<2*n;j++)
						for(int l=0;l<2*n;l++)
							ans[cont][i][j] = min(ans[cont][i][j], ans[cont-1][i][l] + best[k][l][j]);
			cont++;

			}

		printf("%I64d\n",ans[cont-1][0][0]);

	}