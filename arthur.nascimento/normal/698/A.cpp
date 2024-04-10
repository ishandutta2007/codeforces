#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf (1<<30)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define pcc pair<char,char>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) //fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 100100	
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf

typedef long long ll;
using namespace std;

int v[110];

int dp[110][4];
int n;

int get(int pos,int l){
	if(dp[pos][l]+1)
		return dp[pos][l];
	if(pos == n)
		return 0;
	if(v[pos] == 0)
		return dp[pos][l] = 1 + get(pos+1,0);
	if(v[pos] == 1){
		if(l == 1)
			return dp[pos][l] = 1 + get(pos+1,0);
		else return dp[pos][l] = min(get(pos+1,1),1+get(pos+1,0));
	}
	if(v[pos] == 2){
		if(l == 2)
			return dp[pos][l] = 1 + get(pos+1,0);	
		else
			return dp[pos][l] = min(get(pos+1,2),1+get(pos+1,0));
	}
	if(v[pos] == 3){
		int ret = get(pos+1,0)+1;
		if(l != 2) ret = min(ret,get(pos+1,2));
		if(l != 1) ret = min(ret,get(pos+1,1));
		return dp[pos][l] = ret;
	}
}
main(){

	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	memset(dp,-1,sizeof(dp));

	printf("%d\n",get(0,0));

}