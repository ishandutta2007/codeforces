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

char M[550][550];
char achou[550][550];

pii pai[550][550];

int dist[550][550];

int n,m;

pii find(int x,int y){
	return pai[x][y] = (pai[x][y] == pii(x,y)) ? pii(x,y) : find(pai[x][y].first,pai[x][y].second);}

void merge(int xa,int ya,int xb,int yb){

	pii A = find(xa,ya);
	pii B = find(xb,yb);

	pai[A.first][A.second] = B;
	
	}

struct tr {
	char ch;
	int a,b;
	tr(char ch=0,int a=0,int b=0) : ch(ch) , a(a) , b(b) {}
};

queue<tr> ans;
vector<pii> V;

void dfs(int x,int y,int d){

	if(x < 0 || y < 0 || x >= n || y >= m)return;
	if(achou[x][y] || M[x][y] == '#')return;

	achou[x][y] = 1;
	dist[x][y] = d;
	V.push_back(pii(x,y));

	
	dfs(x+1,y,d+1);
	dfs(x-1,y,d+1);
	dfs(x,y+1,d+1);
	dfs(x,y-1,d+1);
	

}

bool comp(pii a,pii b){
	return dist[a.first][a.second] > dist[b.first][b.second];}

main(){

	scanf("%d%d",&n,&m);
	getchar();

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

		M[i][j] = getchar();

		if(M[i][j] == '.')
			ans.push(tr('B',i,j));

		}
		getchar();
		}

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			pai[i][j] = pii(i,j);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

		if(achou[i][j] || M[i][j] == '#')continue;
		V.clear();
		debug("!!\n");
		dfs(i,j,0);

		if(V.empty())continue;

		sort(V.begin(),V.end(),comp);
		
		for(vector<pii> :: iterator it = V.begin(); it < --V.end(); it++){
			debug("++\n");
			ans.push(tr('D',it -> first, it -> second));
			ans.push(tr('R',it -> first, it -> second));
			}
		

		}}


	printf("%d\n",ans.size());

	while(!ans.empty()){

		tr k = ans.front();
		ans.pop();
		printf("%c %d %d\n",k.ch,k.a+1,k.b+1);

		}

		}