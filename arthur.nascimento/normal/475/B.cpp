#include <iostream>
#include <iomanip>
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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

char A[30];
char B[30];

vector<pii> L[30][30];
vector<pii> rev[30][30];

int foi[30][30];
int n,m;

void dfs(int x,int y){
	if(x<0||y<0||x==n||y==m)return;
	if(foi[x][y])return;
	debug("achou %d,%d\n",x,y);
	foi[x][y] = 1;
	for(vector<pii> :: iterator it = L[x][y].begin(); it < L[x][y].end(); it++) dfs(it->first,it->second);
}
void dfs2(int x,int y){
	if(x<0||y<0||x==n||y==m)return;
	if(foi[x][y])return;
	foi[x][y] = 1;
	for(vector<pii> :: iterator it = rev[x][y].begin(); it < rev[x][y].end(); it++) dfs2(it->first,it->second);
}

main(){

		scanf("%d%d",&n,&m);

		scanf(" %s",A);
		scanf(" %s",B);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){

				if(A[i] == '>'){
					L[i][j].pb(pii(i,j+1)); rev[i][j+1].pb(pii(i,j));}
				else{
					L[i][j].pb(pii(i,j-1)); if(j)rev[i][j-1].pb(pii(i,j));}
				if(B[j] == 'v'){ if(i==1&&j==0)debug("!!");
					L[i][j].pb(pii(i+1,j)); rev[i+1][j].pb(pii(i,j));}
				else{
					L[i][j].pb(pii(i-1,j)); if(i) rev[i-1][j].pb(pii(i,j));}

			}

		dfs(0,0);
		int cont = 0;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++) cont += foi[i][j];
		memset(foi,0,sizeof(foi));
		debug("foi %d\n",cont);
		dfs2(0,0);
		for(int i=0;i<n;i++)for(int j=0;j<m;j++) cont += foi[i][j];
		debug("foi %d\n",cont);
		if(cont == 2*n*m)
			printf("YES\n");
		else
			printf("NO\n");

}