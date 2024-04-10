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
#define mod 1000000007
#define maxn 100100

using namespace std;

int tira;
short dp[1010][30300];
int v[30300];
int n,d;

short get(int pos,int k){
	if(pos > 30000) return 0;
	if(dp[k-tira][pos]+1) return dp[k-tira][pos];
	short ret = max(get(pos+k,k), get(pos+k+1,k+1));
	if(k > 1)
		ret = max(ret, get(pos+k-1,k-1));
	return dp[k-tira][pos] = ret + v[pos];
}

main(){

		int n,d;
		scanf("%d%d",&n,&d);
		tira = max(0,d-600);

		memset(dp,-1,sizeof(dp));

		while(n--){
			int u;
			scanf("%d",&u);
			v[u]++;

		}

		printf("%d\n",get(d,d));

}