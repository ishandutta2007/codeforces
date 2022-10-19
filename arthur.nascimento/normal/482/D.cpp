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
#define maxn 100100

using namespace std;

int dp[2][maxn];
int dp2[2][maxn];
int dp3[2][maxn];
int dp4[2][2][maxn];

vector<int> L[maxn];

long long get(int,int);
long long  get2(int,int,int);
long long get3(int,int,int);
long long  get4(int,int,int,int);

long long get(int p,int pos){
	if(dp[p][pos]+1)
		return dp[p][pos];
	if(L[pos].size() == 0)
		return p;
	long long ret = get2(p^1,pos,0) + get3(p^1,pos,L[pos].size()-1);
	ret -= get4(p^1,0,pos,0);
	if(p == 0) ret -= get4(p^1,1,pos,0);
	debug("dp %d %d:\n",p,pos);
	debug("!%lld + %lld - %lld - %lld + %d\n",get2(p^1,pos,0) , get3(p^1,pos,L[pos].size()-1),(p^1)*get4(p^1,0,pos,0) , get4(p^1,1,pos,0), p);
	return dp[p][pos] = (ret%mod+mod)%mod;
}

long long get2(int p,int pos,int t){
	if(t == L[pos].size())
		return p^1;
	if(dp2[p][L[pos][t]]+1)
		return dp2[p][L[pos][t]];
	long long ret = get2(p,pos,t+1) + get(0,L[pos][t]) * get2(p,pos,t+1) + get(1,L[pos][t]) * get2(p^1,pos,t+1);
	return dp2[p][L[pos][t]] = ret%mod;
}

long long get3(int p,int pos,int t){
	if(t == -1)
		return p^1;
	if(dp3[p][L[pos][t]]+1)
		return dp3[p][L[pos][t]];
	long long ret = get3(p,pos,t-1) + get(0,L[pos][t]) * get3(p,pos,t-1) + get(1,L[pos][t]) * get3(p^1,pos,t-1);
	return dp3[p][L[pos][t]] = ret%mod;
}

long long get4(int p,int q,int pos,int t){
	if(t == L[pos].size())
		return p^1;
	if(dp4[p][q][L[pos][t]]+1)
		return dp4[p][q][L[pos][t]];
	long long ret = get4(p,q,pos,t+1) + get(q,L[pos][t]) * get4(p^q,q,pos,t+1);
	return dp4[p][q][L[pos][t]] = ret%mod;
}

main(){

	int n;
	scanf("%d",&n);
	for(int i=1,p;i<n;i++)
		scanf("%d",&p), L[p-1].pb(i);

	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	memset(dp3,-1,sizeof(dp3));
	memset(dp4,-1,sizeof(dp4));

	printf("%d\n",(int)((get(0,0)+get(1,0))%mod));

}