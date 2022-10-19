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
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 100100	
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf

typedef long long ll;
using namespace std;

vector<int> L[maxn];
int sz[maxn];

double ans[maxn];

void dfs(int v,int p){
	sz[v] = 1;
	for(int i=0;i<L[v].size();i++){
		dfs(L[v][i],v);
		sz[v] += sz[L[v][i]];
	}
}

void dfs2(int v,int p){

	for(int i=0;i<L[v].size();i++){
		ans[L[v][i]] = 0.5 + ans[v] + (double)(sz[v]-sz[L[v][i]])/2;
		dfs2(L[v][i],v);
	}

}


main(){	

	int n;
	scanf("%d",&n);

	for(int i=1;i<n;i++){
		int p;
		scanf("%d",&p), p--;
		L[p].pb(i);
	}

	ans[0] = 1.0;

	dfs(0,0);

	dfs2(0,0);

	for(int i=0;i<n;i++)
		printf("%.10lf\n",ans[i]);

}