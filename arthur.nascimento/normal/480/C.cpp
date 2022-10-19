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

long long dp[2][5050];
long long sum[2][5050];

main(){

		int n,k,a,b;
		scanf("%d%d%d%d",&n,&a,&b,&k), a--, b--;

		for(int i=0;i<n;i++)
			dp[0][i] = 1, sum[0][i] = i+1;

		for(int i=1;i<=k;i++){
			int cur = i&1;
			int alt = cur^1;
			for(int j=0;j<n;j++){
				int dx = abs(b-j)-1;
				int low = max(0,j-dx);
				int up = min(n-1,j+dx);
				if(j == a)debug("! %d %d\n",low,up);
				dp[cur][j] = sum[alt][up];
				if(low) dp[cur][j] -= sum[alt][low-1];
				dp[cur][j] = (dp[cur][j] - dp[alt][j] + mod) % mod;
				dp[cur][j] += mod;
				dp[cur][j] %= mod;
				sum[cur][j] = dp[cur][j];
				if(j) sum[cur][j] = (sum[cur][j] + sum[cur][j-1]) % mod;
			}
		}

		printf("%I64d\n",dp[k&1][a]);

}