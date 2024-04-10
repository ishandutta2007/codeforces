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
long long a[maxn];
long long dp[maxn][2];

long long dfs(int x,int p){

	if(dp[x][p]+1) return dp[x][p];
	debug("dfs %d %d\n",x,p); 
	if(L[x].size() == 0) {
		debug("x %d a %I64d\n",x,a[x]);
		dp[x][0] = 0;
		dp[x][1] = a[x];
		debug("%d ret %I64d %I64d\n",x+1,dp[x][0],dp[x][1]);
		return dp[x][p];
	}	

	vector<long long> u;
	long long ret = 0;
	long long S = 0;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++){
		dfs(*it,0);
		u.pb(dp[*it][1]-dp[*it][0]);
		
		S += dp[*it][0];
	}

	sort(u.begin(), u.end());
	reverse(u.begin(), u.end());
	
	long long P = 0;
	long long I = u[0];

	debug("us = %d\n",u.size());
		
	for(int i=0;i+1<u.size();i+=2)
		if(u[i] + u[i+1] > 0) P += u[i] + u[i+1];
	for(int i=1;i+1<u.size();i+=2)
		if(u[i] + u[i+1] > 0) I += u[i] + u[i+1];

	debug("ok\n");

	debug("x = %d S %I64d I %I64d P %I64d\n",x+1,S,I,P);

	dp[x][0] = S + P;
	//debug("max %I64d %I64d\n",S+I,a[x]+P);
	dp[x][1] = max(S + I, a[x] + S + P);

	debug("%d ret %I64d %I64d\n",x+1,dp[x][0],dp[x][1]);
	return dp[x][p];

}

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int p;
			scanf("%d%I64d",&p,a+i), p--;
			if(p+2)
				L[p].pb(i);
		}

		memset(dp,-1,sizeof(dp));
		cout << max(dfs(0,0),dfs(0,1)) << endl;

}