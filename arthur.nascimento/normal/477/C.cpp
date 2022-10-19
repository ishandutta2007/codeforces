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

char st1[2020];
char st2[550];
int n,m;

int dp[550][2020];

int qmin[2020][2020];
int acum[2020][2020];

int get(int p2,int p1){

	if(dp[p2][p1]+1) return dp[p2][p1];

	if(p1 == n) return 999999999;
	if(p2 == m-1 && st1[p1] == st2[p2]) return p1;
	int ret;
	if(st1[p1] == st2[p2])
		ret = get(p2+1,p1+1);
	else
		ret = get(p2,p1+1);
	return dp[p2][p1] = ret;

}

int ans[2020];

main(){	

		scanf(" %s %s",st1,st2);

		n = strlen(st1);
		m = strlen(st2);

		memset(dp,-1,sizeof(dp));

		for(int j=1;j<=n;j++)
			qmin[n][j] = 999999999, acum[n][j] = 999999999;

		for(int i=n-1;i>=0;i--)
			for(int j=1;j<=n;j++){

				int u = get(0,i);

				if(u < 999999)
					qmin[i][j] = u-i-m+1 + acum[u+1][j-1];
				else
					qmin[i][j] = 999999999;

				debug("qmin[%d][%d] = %d\n",i,j,qmin[i][j]);

				acum[i][j] = min(qmin[i][j],acum[i+1][j]);

			}

		int ma = 0;

		for(int i=1;i<=n;i++){

			int t = acum[0][i];
			for(int j=t;j<=n;j++)
				ans[j] = i;
			if(t <= n) ma = i;

		}

		int p0 = 0;
		while(ans[p0] != ma) p0++;

		int left = n - p0;
		int cur = ma;

		while(p0 < n){

			p0++;
			left--;

			while(m * cur > left)
				cur--;

			ans[p0] = cur;

		}

		for(int i=0;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");

}