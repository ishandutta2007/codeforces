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

#define inf (9999999999999999LL)
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
#define maxn 200200
#define sq(x) ((x)*(x))	

using namespace std;

vector<pii> L[maxn];
int big[maxn];

int dfs(int x){

	if(L[x].size() == 0) return 0;
	int a = 0;
	for(vector<pii> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		a = max(a,dfs(it->first) + it->second);
	debug("big %d %d\n",x,a);
	return big[x] = a;
}

int ans = 0;

void dfs2(int x){
	if(L[x].size() == 0) return;
	for(vector<pii> :: iterator it = L[x].begin(); it < L[x].end(); it++){
		ans += big[x] - big[it->first] - it->second;
		dfs2(it->first);
	}
}

main(){

		int n;
		scanf("%d",&n);

		n = (1<<(n+1)) - 1;

		for(int i=2;i<=n;i++){
			int u;
			scanf("%d",&u);
			L[i/2].pb(pii(i,u));
		}

		dfs(1);
		dfs2(1);
		printf("%d\n",ans);
}