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


vector<int> L[220];
int h[220];
int best[2][220];

int t1,t2;

void dfs(int x,int p){

	h[x] = 1 + h[p];
	
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p)
			dfs(*it,x);

}

int dfs2(int x,int p,int a,int b){

	if(h[a] > h[b])
		swap(a,b);


	best[0][x] = best[1][x] = 0;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p){
			dfs2(*it,x,a,b);

			if(1+best[0][*it] > best[0][x])
				best[1][x] = best[0][x], best[0][x] = 1 + best[0][*it];
				
				
			else if(1+best[0][*it] > best[1][x])
				best[1][x] = 1 + best[0][*it];
			
			}

	if(x == b){
		t1 = best[0][x] + best[1][x];
		debug("%d %d %d\n",b,best[0][x],best[1][x]);
		best[0][x] = best[1][x] = -1; 	
		
		}

	if(x == a)
		t2 = best[0][x] + best[1][x];

	return t1*t2;

}

main(){

		int n;
		scanf("%d",&n);

		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			L[a-1].push_back(b-1);
			L[b-1].push_back(a-1);
			}

		h[0] = -1;
		dfs(0,0);

		int ans = 0;

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				ans = max(ans,dfs2(0,0,i,j));

		printf("%d\n",ans);

	}