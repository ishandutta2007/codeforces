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
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

pii dp[maxn][12];

char M[maxn][12];

const int size = 300;

int bucket[maxn];
int begin[maxn];
int end[maxn];

int foi[12];
int visit[12];

int n,m;

void dfs(int x,int y){
	if(foi[y]) return;
	visit[y] = 1;
	if(M[x][y] == '^'){
		if(x == 0)
			dp[x][y] = pii(-1,y);
		else
			dp[x][y] = (x%size == 0) ? pii(x-1,y) : dp[x-1][y];
		foi[y] = 1;
		return;
	}
	if(M[x][y] == '>'){
		if(y == m-1)
			dp[x][y] = pii(x,y+1);
		else if(foi[y+1])
			dp[x][y] = dp[x][y+1];
		else if(!visit[y+1]){
			dfs(x,y+1);
			dp[x][y] = dp[x][y+1];
		}
		else
			dp[x][y] = pii(-2,-2);
	}
	if(M[x][y] == '<'){
		if(y == 0)
			dp[x][y] = pii(x,y-1);
		else if(foi[y-1])
			dp[x][y] = dp[x][y-1];
		else if(!visit[y-1]){
			dfs(x,y-1);
			dp[x][y] = dp[x][y-1];
		}
		else
			dp[x][y] = pii(-2,-2);
	}
	foi[y] = 1;
}
		

void build(int u){

	debug("build bucket %d\n",u);
	for(int i=begin[u];i<=end[u];i++){
		memset(foi,0,sizeof(foi));
		memset(visit,0,sizeof(visit));
		for(int j=0;j<m;j++)
				dfs(i,j);
		debug("%d: ",i);
		for(int j=0;j<m;j++)
			debug(" (%d,%d)",dp[i][j].first,dp[i][j].second);
		debug("\n");
	}

}

main(){

	int q;
	scanf("%d%d%d",&n,&m,&q);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf(" %c",&M[i][j]);

	memset(begin,127,sizeof(begin));

	for(int i=0;i<n;i++){
		bucket[i] = i/size;
		begin[i/size] = min(i,begin[i/size]);
		end[i/size] = max(i,end[i/size]);
	}

	int qt = bucket[n-1] + 1;

	for(int i=0;i<qt;i++)
		build(i);

	while(q--){
		char ch;
		int x,y;
		scanf(" %c%d%d",&ch,&x,&y), x--, y--;
		if(ch == 'C'){
			char u;
			scanf(" %c",&u);
			M[x][y] = u;
			build(bucket[x]);
		}
		else {
			while(x >= 0 && x < n && y >= 0 && y < m){
				pii r = dp[x][y];
				x = r.first;
				y = r.second;
				debug("xy -> %d %d\n",x,y);
			}
			printf("%d %d\n",x+1,y+1);
		}
	}
	
}