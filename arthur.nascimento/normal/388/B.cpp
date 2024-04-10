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

#define maxn 32 
 
using namespace std;

int mrk[110];
int v[1100];
int adj[1010][1010];


main(){

		long long k;
		scanf("%I64d",&k);
		k--;

		int qnt = maxn+3;

		adj[0][2] = 1;

		for(int i=2;i<maxn+2;i++)
			adj[i][i+1] = 1;

		adj[maxn+2][1] = 1;

		for(int i=0;i<maxn;i++){

			if(k & (1LL<<i)){

					debug("i=%d\n",i);
					
					int last = 0;

					if(i){

					adj[0][qnt] = 1;
					adj[0][qnt+1] = 1;

		
					qnt += 2;
					last = qnt-1;
					
					for(int j=1;j<i;j++){

						adj[last][qnt] = adj[last-1][qnt] = adj[last][qnt+1] = adj[last-1][qnt+1] = 1;
						
						qnt += 2;
						last = qnt-1;
						}

					adj[qnt-2][qnt] = adj[qnt-1][qnt] = 1;
					last = qnt;
					qnt++;
					

					}
				
					debug("ok\n");
					
					for(int j=(i?i+1:i);j<maxn;j++){

						if(i == 0){
							adj[0][qnt] = 1;
							adj[qnt][3] = 1;
							qnt++;
							break;
							}

						int y = maxn - j;

						adj[last][j+2] = 1;

						break;
					
						/*adj[last][qnt] = 1;
						last = qnt;
						qnt++;*/

						
						}
					//adj[last][1] = 1;

					}

			}

		printf("%d\n",qnt);

		for(int i=0;i<qnt;i++){
			for(int j=0;j<qnt;j++){
				printf("%c",(adj[i][j] || adj[j][i]) ? 'Y' : 'N');
				}
			printf("\n");}

		}