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
#define maxn 300300

using namespace std;

char str[30][30];
int v[30][30];

int dp[1<<20];

int mask[1010];
int cost[1010];

int foi[1<<20];
int id[1<<20];

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++)
		scanf(" %s",str[i]);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&v[i][j]);
	
	int cnt = 0;
	for(int i=0;i<n;i++){
		mask[cnt] = 1 << i;
		int mi = inf;
		for(int j=0;j<m;j++)
			mi = min(mi,v[i][j]);
		cost[cnt] = mi;
		cnt++;
	}

	for(char ch='a';ch<='z';ch++)
		for(int j=0;j<m;j++){
			int sum=0, st=0, ma=0;
			for(int i=0;i<n;i++)
				if(str[i][j] == ch){
					sum += v[i][j];
					st += 1 << i;
					ma = max(ma,v[i][j]);
				}
			if(st && !foi[st]){
				cost[cnt] = sum-ma;
				mask[cnt] = st;
				id[st] = cnt;
				cnt++;
				foi[st] = 1;
				
			}
			else if(st && foi[st])
				cost[id[st]] = min(cost[id[st]],sum-ma);
		}

	for(int i=0;i<(1<<n);i++)
		dp[i] = inf;

	dp[0] = 0;

	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<cnt;j++)
			dp[i|mask[j]] = min(dp[i|mask[j]],dp[i]+cost[j]);

	printf("%d\n",dp[(1<<n)-1]);

}