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

char M[550][550];
int achou[550][550];
int n,m,k;


bool ok(int x,int y){

	return x >= 0 && y >= 0 && x < n && y < m && !achou[x][y] && M[x][y] == '.';
}

void dfs(int x,int y){

	debug("dfs %d %d\n",x,y);
	achou[x][y] = 1;

	int _x[] = {0,0,1,-1};
	int _y[] = {1,-1,0,0};

	for(int i=0;i<4;i++)
		if(ok(x+_x[i], y+_y[i]))
			dfs(x+_x[i], y+_y[i]);

	if(k){
		k--;
		M[x][y] = 'X';
		}
	debug("ret %d %d\n",x,y);
}

main(){

			
		scanf("%d%d%d",&n,&m,&k);

		for(int i=0;i<n;i++)
			scanf(" %s",M[i]);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(M[i][j] == '.' && !achou[i][j])
					dfs(i,j);
			

		

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				printf("%c",M[i][j]);
			printf("\n");}

	}