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

vector<int> L[100100];
int foi[100100];
int pai[100100];
int root[100100];

void dfs(int x,int cc,int p){

	if(foi[x]) return;
	foi[x] = cc;
	debug("foi[%d] = %d\n",x,cc);
	pai[x] = p;
	if(x == p){
		root[cc] = x;
		debug("root[%d] = %d\n",cc,x);
	}

	for(int i=0;i<L[x].size();i++)
		dfs(L[x][i],cc,x);

}

vector<int> ans;

int visit[100100];
int par[100100];

void dfs2(int x){

	debug("dfs2 %d\n",x);
	
	if(L[x].size() == 1 && pai[x] != x) return;

	if(L[x].size() == 0) return;

	for(int i=0;i<L[x].size();i++) if(L[x][i] != pai[x]){

		ans.pb(L[x][i]);
		visit[L[x][i]]^=1;
		dfs2(L[x][i]);
		ans.pb(x);
		visit[x]^=1;
		if(visit[L[x][i]] != par[L[x][i]]){
			ans.pb(L[x][i]);
			visit[L[x][i]]^=1;
			ans.pb(x);
			visit[x]^=1;
		}

	}

	if(pai[x] == x && visit[x] != par[x]){

		debug("sz = %d visit[%d] = %d\n",ans.size(),x,visit[x]);
		ans.pb(L[x][0]);
		ans.pb(x);
		ans.pb(L[x][0]);
		
	}

}



int uf[100100];
int find(int x){
	return uf[x] = (x == uf[x]) ? x : find(uf[x]);}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
		 	uf[i] = i;

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			int A = find(a), B = find(b);
			if(A != B){
				L[a].pb(b);
				L[b].pb(a);
				uf[A] = B;
			}
		}

		int cc = 0;

		for(int i=0;i<n;i++) if(!foi[i])
			dfs(i,++cc,i);

		for(int i=0;i<n;i++)
			scanf("%d",par+i);

		set<int> st;
		for(int i=0;i<n;i++)
			if(par[i]){ st.insert(foi[i]); debug("i=%d insert %d\n",i,foi[i]);}

		if(st.size() >= 2){
			printf("-1\n");
			return 0;
		}

		if(st.size() == 0){
			printf("0\n");
			return 0;
		}

		ans.pb(root[*(st.begin())]);
		visit[root[*(st.begin())]] = 1;
		dfs2(root[*(st.begin())]);

		printf("%d\n",ans.size());

		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]+1);

		printf("\n");

}