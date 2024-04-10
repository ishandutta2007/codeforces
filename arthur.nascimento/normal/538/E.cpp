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

#define inf (9999999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define mod 1000000007
#define maxn 200200

using namespace std;

vector<int> L[maxn];

int dp[2][2][maxn];

int qnt[maxn];
int pai[maxn];

void dfs(int x){

	if(L[x].size() == 0){
		qnt[x] = 1;
		return;
	}

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++){
		pai[*it] = x;
		dfs(*it);
		qnt[x] += qnt[*it];
	}

}

int get(int c,int t,int x){

	//if(c == 1) return 0;
	if(dp[c][t][x]+1) return dp[c][t][x];

	if(L[x].size() == 0) return 1;

	int u = 0;
	int y = 999999999;
	int yy = y;
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++){
		if(c == 1)u += get(c,1-t,*it)-1;
		else u += qnt[*it]-get(c,1-t,*it);
		if(c == 1) y = min(y,qnt[*it]-get(c,1-t,*it));
		else y = min(y,get(c,1-t,*it)-1);
		if(c == 0 && t == 0) yy = min(yy,get(c,1-t,*it));
	}

	int r;

	if(c == t){
		r = qnt[x]-y;
		if(c == 0) r = yy;
		debug("dp[%d][%d][%d] = %d\n",c,t,x,r);
		return dp[c][t][x] = r;
	}


	 r = u+1;
	if(t == 1)r = qnt[x] - u;
	debug("dp[%d][%d][%d] = %d\n",c,t,x,r);
	return dp[c][t][x] = r;	

	

}

main(){

		int n;
		scanf("%d",&n);

		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			L[a].pb(b);
		}

		dfs(0);

		memset(dp,-1,sizeof(dp));

		printf("%d %d\n",get(1,1,0),get(0,1,0));

}