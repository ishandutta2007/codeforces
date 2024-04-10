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

int M[2020][2020];

int foi[2020];
int qnt = 0;

int n;

void dfs(int x){

	foi[x] = 1;
	qnt++;

	for(int i=0;i<n;i++)
		if(!foi[i] && M[x][i])
			dfs(i);

}

void dfs2(int x){

	foi[x] = 1;
	qnt++;

	for(int i=0;i<n;i++)
		if(!foi[i] && M[i][x])
			dfs2(i);

}

int main(){
	
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&M[i][j]);

		int v;

		for(int i=0;i<n;i++)
			if(M[i][i])
				v = i;

		dfs(v);
		memset(foi,0,sizeof(foi));
		dfs2(v);

		if(qnt == 2*n)
			printf("YES\n");
		else
			printf("NO\n");

	}