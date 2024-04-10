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

queue<char> ans;

int T[2][550][550];

void update(int idx,int val,int xy,int lc){
		idx++;
		while(idx <= 500){
			T[xy][lc][idx] += val;
			idx += idx&-idx;}
}

int sum(int idx,int xy,int lc){
	idx++;
	int ret = 0;
	while(idx){
		ret += T[xy][lc][idx];
		idx -= idx&-idx;}
	return ret;
}

int M[550][550];
int achou[550][550];

void dfs(int x,int y){

	if(achou[x][y])
		return;
	debug("%d %d\n",x,y);

	achou[x][y] = 1;

	if(M[x][y] == 0)
		M[x][y] = 1,
		update(x,1,0,y),
		update(y,1,1,x),
		ans.push('1');

	debug("-> %d %d\n",sum(500,0,y) , sum(x,0,y));

	if(sum(500,0,y) > sum(x,0,y))
		ans.push('R'),
		dfs(x+1,y),
		ans.push('L');

	if(sum(x-1,0,y))
		ans.push('L'),
		dfs(x-1,y),
		ans.push('R');

	if(sum(500,1,x) > sum(y,1,x))
		ans.push('D'),
		dfs(x,y+1),
		ans.push('U');

	if(sum(y-1,1,x))
		ans.push('U'),
		dfs(x,y-1),
		ans.push('D');
}

int n;
bool ok(int x,int y){
	return x >=0 && y >= 0 && x < n && y < n && M[x][y];}

void dfs2(int x,int y){

	achou[x][y] = 1;

	int _x[] = {0,0,1,-1};
	int _y[] = {1,-1,0,0};
	char a[] = {'D','U','R','L'};
	char b[] = {'U','D','L','R'};

	for(int i=0;i<4;i++)
		if(ok(x+_x[i],y+_y[i]) && !achou[x+_x[i]][y+_y[i]])
			ans.push(a[i]),
			dfs2(x+_x[i],y+_y[i]),
			ans.push(b[i]);

	M[x][y] = 0;
	ans.push('2');

}

main(){

		int x0,y0;
		scanf("%d%d%d",&n,&y0,&x0);

		for(int j=0;j<n;j++)
			for(int i=0;i<n;i++)
				scanf("%d",&M[i][j]),
				update(i,M[i][j],0,j),
				update(j,M[i][j],1,i);
				debug("-> %d %d\n",sum(500,0,0) , sum(0,0,0));
  
		dfs(x0-1,y0-1);
		memset(achou,0,sizeof(achou));
		dfs2(x0-1,y0-1);

		int o = 1;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(M[i][j] == 1)
					o = 0;

		if(!o)
			printf("NO\n");
		else {
			printf("YES\n");
			while(!ans.empty())
				printf("%c",ans.front()),
				ans.pop();
			}
		

		}