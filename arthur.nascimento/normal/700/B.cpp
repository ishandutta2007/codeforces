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
#define maxn 200200	
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf

typedef long long ll;
using namespace std;

vector<int> L[maxn];

int mrk[maxn];

int sz[maxn];

void dfs(int v,int p){
	if(mrk[v]) sz[v] = 1;
	for(int i=0;i<L[v].size();i++) if(L[v][i] != p){
		dfs(L[v][i],v);
		sz[v] += sz[L[v][i]];
	}
}

ll ans = 0;

void dfs2(int v,int p,int d){
	if(mrk[v]) ans += d;
	for(int i=0;i<L[v].size();i++)
		if(L[v][i] != p)
			dfs2(L[v][i],v,d+1);
}

main(){

	int n,k;
	scanf("%d%d",&n,&k);

	for(int i=0;i<2*k;i++){
		int u;
		scanf("%d",&u);
		mrk[u-1] = 1;
	}

	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d%d",&a,&b);
		a--, b--;
		L[a].pb(b);
		L[b].pb(a);
	}

	dfs(0,0);

	int u = 0, p = 0;

	while(1){
		int ok = 1;
		debug("u = %d\n",u);
		for(int i=0;i<L[u].size();i++) if(L[u][i] != p){
			if(sz[L[u][i]] > k){
				ok = 0;
				debug("u := %d\n",L[u][i]);
  				p = u;
				u = L[u][i];
				break;
			}
		}
		if(ok) break;
	}

	dfs2(u,u,0);

	printf("%lld\n",ans);

}