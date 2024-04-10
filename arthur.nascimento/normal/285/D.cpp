#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define mod 1000000007
 
using namespace std;

long long ans[] = {1, 0, 3, 0, 15, 0, 133, 0, 2025, 0, 37851, 0, 1030367, 0, 36362925, 0};

long long fat[16];

map<pii,int> dp;
int n;

int foi1[16];
int foi2[16];

int get(int p,int mask1,int mask2){

	if(dp.find(pii(mask1,mask2)) != dp.end())
		return dp[pii(mask1,mask2)];

	if(p == n)
		return 1;

	long long ret = 0;

	for(int i=0;i<n;i++)
		if(!foi1[i] && !foi2[(p+i)%n]){
			foi1[i] = foi2[(p+i)%n] = 1;
			ret += get(p+1,mask1^(1<<i), mask2^(1<<((p+i)%n)));
			foi1[i] = foi2[(p+i)%n] = 0;
		}

	return dp[pii(mask1,mask2)] = ret % mod;

}

main(){

	fat[0] = 1;

	for(int i=1;i<16;i++)
		fat[i] = (fat[i-1] * (i+1)) % mod;

	int k;
	scanf("%d",&k);

	printf("%d\n",(ans[k-1]*fat[k-1])%mod);

	return 0;

	for(n=1;n<=16;n++){

			dp.clear();

			memset(foi1,0,sizeof(foi1));
			memset(foi2,0,sizeof(foi2));

			printf("%d, ",get(0,0,0));

			}

	}