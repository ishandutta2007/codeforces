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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

char M[1010][1010];
int dist[1010][1010];
int r,c;

int ok(int x,int y){
	if(x < 0 || y < 0 || x >= r || y >= c)return 0;
	return M[x][y] != 'T';
}

main(){

	
	scanf("%d%d\n",&r,&c);

	int xf,yf;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
		M[i][j] = getchar();
		if(M[i][j] == 'E')
			xf = i, yf = j;
		}
		getchar();
		}

	memset(dist,-1,sizeof(dist));
	queue<pii> Q;
	Q.push(pii(xf,yf));
	dist[xf][yf] = 0;
	int D;

	while(!Q.empty()){

		pii k = Q.front();
		Q.pop();

		if(M[k.first][k.second] == 'S')
			D = dist[k.first][k.second];

		int _x[] = {0,0,1,-1};
		int _y[] = {1,-1,0,0};

		for(int i=0;i<4;i++){
			if(!ok(k.first + _x[i],k.second + _y[i]))continue;
			if(dist[k.first + _x[i]][k.second + _y[i]] == -1){
				dist[k.first + _x[i]][k.second + _y[i]] =
				1 + dist[k.first][k.second]; 
				Q.push(pii(k.first + _x[i],k.second + _y[i]));
				}
			}
	
}
	debug("D = %d\n",D);
	int ans = 0;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			debug("%d ",dist[i][j]);
			debug("\n");
}

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){

		if(M[i][j] >= '0' && M[i][j] <= '9' && dist[i][j] <= D && dist[i][j] != -1)
			ans += M[i][j] - '0';
		
}

	printf("%d\n",ans);
	}