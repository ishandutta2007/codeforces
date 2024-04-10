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
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#define getchar_unlocked getchar
#endif

#define pb push_back
#define mod 1000000007

using namespace std;

int dp[110][200200];
int qual[110][200200];
int factors[66];
int v[110];
int n;

int get(int p,int mask){

	if(dp[p][mask]+1)
		return dp[p][mask];

	if(p == n)
		return 0;

	int ret = 99999999;
	for(int i=1;i<=60;i++)
		if((factors[i] & mask) == 0)
			if(ret > abs(v[p]-i) + get(p+1,mask|factors[i])){
				ret = abs(v[p]-i) + get(p+1,mask|factors[i]);
				qual[p][mask] = i;
			}

	return dp[p][mask] = ret;

}

int pr[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};

main(){

		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		memset(dp,-1,sizeof(dp));

		for(int i=1;i<=60;i++)
			for(int j=0;j<17;j++)
				if(i % pr[j] == 0)
					factors[i] |= (1<<j);

		int mask = 0;

		for(int i=0;i<n;i++){
			get(i,mask);
			printf("%d ",qual[i][mask]);
			mask += factors[qual[i][mask]];
		}

		printf("\n");

}