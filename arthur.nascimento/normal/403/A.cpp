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

int adj[30][30];
int n,p;

int f(int x){
	return (x+n)%n;
}

main(){

		int t;
		scanf("%d",&t);

		while(t--){

			memset(adj,0,sizeof(adj));
			scanf("%d%d",&n,&p);

			for(int i=0;i<n;i++){
				adj[i][f(i+1)] = adj[i][f(i+2)] = adj[i][f(i-1)] = adj[i][f(i-2)] = 1;
				}

			while(p){
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						if(!adj[i][j] && i != j){
							adj[i][j] = adj[j][i] = 1;
							p--;
							if(p == 0)
								goto end;}

				}


			end:

			int ok = 1;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(adj[i][j]){
						ok = 0;
						printf("%d %d\n",i+1,j+1);
						adj[i][j] = adj[j][i] = 0;
						}

			if(!ok)
				goto end;

	}

}