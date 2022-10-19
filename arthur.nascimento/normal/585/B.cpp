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

#define inf 99999999999.
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
#define maxn 100100

using namespace std;

char M[30][1010];
int dp[30][110];
int n,m;

int tr(int x,int y){
	if(y < 0 || y >= n) return 0;
	debug("tr %d %d\n",x,y);
	if(y >= n) return 0;
	if(M[x][y] >= 'A' && M[x][y] <= 'Z') return 1;
	return 0;
}
	
int get(int x,int y){

	//debug("get %d %d\n",x,y);

	if(y == n) return 1;
	
	if(dp[x][y]+1)
		return dp[x][y];

	if(tr(x,3*y) || tr(x,3*y-1) || tr(x,3*y-2)) return 0;

	int ok = 0;

	if(tr(x,3*y+1)) return 0;

	if(get(x,y+1)) ok = 1;
	if(x)
		if(!tr(x-1,3*y+1)) if(get(x-1,y+1)) ok = 1;
	if(x != 2)
		if(!tr(x+1,3*y+1)) if(get(x+1,y+1)) ok = 1;

	//debug("dp %d %d %d\n",x,y,ok);
	return dp[x][y] = ok;
	
}

main(){

		int t;
		scanf("%d",&t);
		while(t--){
			scanf("%d%d",&n,&m);
			for(int i=0;i<3;i++)
				scanf(" %s",M[i]);
			memset(dp,-1,sizeof(dp));
			int x = 0;
			for(int i=0;i<3;i++) if(M[i][0] == 's') x = i;
			if(get(x,0))
				printf("YES\n");
			else
				printf("NO\n");
		}

}