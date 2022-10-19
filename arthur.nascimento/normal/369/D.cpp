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

int n,k;
int p[3030];
int dpmax[3030];
int dpmin[3030];
int ans = 0;

int achou[3030][3030];
int best[3030][3030];
int ach[3030];
int vazio=0;

void dfs(int a,int b){

	debug("dfs %d %d\n",a,b);

	if(best[a][b] > k)
		return;


	if(a >= n){
		if(vazio==0)
			vazio=1,
			ans++;
		return;
		}	

	if(b >= n){
		if(ach[a] == 0)
			ach[a] = 1,
			ans++;
		return;}

	
	if(!achou[a][b])
		achou[a][b] = 1,
		ans++;

	if(p[a] && dpmax[b] && best[b+1][b+2] > 1 + best[a][b]){
		best[b+1][b+2] = 1 + best[a][b];
		dfs(b+1,b+2);
		}

	if((p[a] != 100) && dpmax[b] && best[b][b+1] > 1 + best[a][b]){
		best[b][b+1] = 1 + best[a][b];
		dfs(b,b+1);
		}

	if(p[a] && (dpmax[b] != 100) && best[a][b+1] > 1 + best[a][b]){
		best[a][b+1] = 1 + best[a][b];
		dfs(a,b+1);
		}

}

main(){

		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d",p+i);

		dpmin[n-1] = dpmax[n-1] = p[n-1];

		for(int i=n-2;i>=0;i--)
			dpmin[i] = min(dpmin[i+1], p[i]),
			dpmax[i] = max(dpmax[i+1], p[i]);

		memset(best,127,sizeof(best));

		best[0][1] = 0;
		dfs(0,1);

		printf("%d\n",ans);

	}