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
#endif

#define pb push_back
#define mod 1000000007

#define X second.first
#define Y second.second

using namespace std;

int v[100100];
long long val[100100];
long long dp[100100];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			val[v[i]] += v[i];
		}


		dp[100000] = val[100000];
		dp[99999] = max(val[99999],val[100000]);

		for(int i=99998;i>=1;i--)
			dp[i] = max(val[i] + dp[i+2], dp[i+1]);

		printf("%I64d\n",dp[1]);

}