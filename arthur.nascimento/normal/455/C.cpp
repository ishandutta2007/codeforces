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
#define maxn 300300

#define X second.first
#define Y second.second

using namespace std;

vector<int> L[maxn];
int diam[maxn];
int centro[maxn];
int foi[maxn];

int d1[maxn];
int d2[maxn];
int d3[maxn];

int longe;
int di;
int ce;

int dfs(int x,int d){

	foi[x] = 1;
	d1[x] = d;

	if(d > d1[longe]) longe = x;

	for(int i=0;i<L[x].size();i++) if(!foi[L[x][i]])
		dfs(L[x][i],d+1);

}

int dfs2(int x,int d){

	foi[x] = 2;
	d2[x] = d;

	if(d > d2[longe]) longe = x;

	for(int i=0;i<L[x].size();i++) if(foi[L[x][i]] != 2)
		dfs2(L[x][i],d+1);

}

int dfs3(int x,int d){

	foi[x] = 3;
	d3[x] = d;

	for(int i=0;i<L[x].size();i++) if(foi[L[x][i]] != 3)
		dfs3(L[x][i],d+1);

}

int dfs4(int x){

	foi[x] = 4;

	if(d2[x] + d3[x] == di && abs(d2[x]-d2[x]) <= 1) ce = x;

	for(int i=0;i<L[x].size();i++) if(foi[L[x][i]] != 4)
		dfs4(L[x][i]);

}

int pai[maxn];
int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);}

main(){

		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);

		for(int i=0;i<n;i++) pai[i] = i;

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			L[a].pb(b);
			L[b].pb(a);
			int A = find(a);
			int B = find(b);
			if(A != B)
				pai[A] = B;
		}


		for(int i=0;i<n;i++) if(!foi[i]) {

			int u = find(i);
			longe = i;
			dfs(i,0);
			int t = longe;
			dfs2(longe,0);
			di = d2[longe];
			dfs3(longe,0);
			dfs4(i);
			diam[u] = di;
			centro[u] = ce;

		}

		while(q--){

			int t;
			scanf("%d",&t);

			if(t == 1){
				int x;
				scanf("%d",&x), x--;
				printf("%d\n",diam[find(x)]);
			}
			else {
				int x,y;
				scanf("%d%d",&x,&y), x--, y--;
				x = find(x);
				y = find(y);
				if(x == y) continue;
				if(diam[x] < diam[y]) swap(x,y);

				if((diam[x]+1)/2 + (diam[y]+1)/2 + 1 > diam[x]){
					diam[x] = (diam[x]+1)/2 + (diam[y]+1)/2 + 1;
				}

				pai[y] = x;
			}

		}

}