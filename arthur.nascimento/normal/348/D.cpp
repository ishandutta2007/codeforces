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

#define inf (999999999999LL)
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
#define maxn 3030
#define mod 1000000007

using namespace std;

int dp[2][maxn][maxn];
int M[maxn][maxn];

int n,m;

int ret;
int get(int t,int x,int y){
	if(x >= n || y >= m) return 0;
	if(M[x][y] == '#') return 0;
	if(t == 0 && x == n-2 && y == m-1) return 1;
	if(t == 1 && x == n-1 && y == m-2) return 1;
	if(dp[t][x][y]+1) return dp[t][x][y];
	dp[t][x][y] = (get(t,x+1,y) + get(t,x,y+1));
	if(dp[t][x][y] > mod) dp[t][x][y] -= mod;
	return dp[t][x][y];
}

main(){

		scanf("%d%d\n",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				M[i][j] = getchar();
			getchar();
		}

		memset(dp,-1,sizeof(dp));
		long long ans = (long long)get(0,0,1) * get(1,1,0) - (long long)get(1,0,1) * get(0,1,0);
		ans %= mod;
		if(ans < 0) ans += mod;
		cout << ans << endl;

}