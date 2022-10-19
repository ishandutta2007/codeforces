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

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) //fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

int f[maxn];

vector<pii> E[maxn];

vector<int> heavy;

map<pii,int> ans;

int comp[290][maxn];

vector<int> L[maxn];

vector<int> feliz;

int foi[maxn];

void dfs(int x,int y,int u,int cmp){
	if(foi[x] == y) return;
	comp[u][x] = cmp;
	foi[x] = y;
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		dfs(*it,y,u,cmp);
}

void dfs2(int x,int y){
	if(foi[x] == y) return;
	debug("dfs2 %d\n",x);
	feliz.pb(x);
	foi[x] = y;
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		dfs2(*it,y);
}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c), a--, b--, c--;
			f[c]++;
			E[c].pb(pii(a,b));
		}

		int sq = 350;
		int cur = 1;
		int conta = 0;

		for(int i=0;i<m;i++){
			debug("!%d\n",i);
			if(f[i] == 0) continue;
			if(f[i] > sq){
				debug("%d is heavy\n",i);
				heavy.pb(i);
				for(int j=0;j<n;j++) L[j].clear();
				for(int j=0;j<f[i];j++){
					L[E[i][j].first].pb(E[i][j].second);
					L[E[i][j].second].pb(E[i][j].first);
				}
				int k = 0;
				cur++;
				for(int j=0;j<n;j++) if(foi[j] != cur){
					dfs(j,cur,conta,k);
					k++;
				}
				conta++;
				continue;
			}
			debug("%d is light\n",i);
			for(int j=0;j<f[i];j++){
				L[E[i][j].first].clear();
				L[E[i][j].second].clear();
			}
			for(int j=0;j<f[i];j++){
				L[E[i][j].first].pb(E[i][j].second);
				L[E[i][j].second].pb(E[i][j].first);
				debug("+edge %d %d\n",E[i][j].first,E[i][j].second);
			}
			cur++;
			feliz.clear();
			for(int j=0;j<f[i];j++) {
				if(foi[E[i][j].first] != cur){
					feliz.clear();
					debug("hey!\n");
					dfs2(E[i][j].first,cur);
					for(int a=0;a<feliz.size();a++)
						for(int aa=a+1;aa<feliz.size();aa++){
							ans[pii(min(feliz[a],feliz[aa]),max(feliz[a],feliz[aa]))]++;debug("+ %d %d\n",feliz[a],feliz[aa]);}
				}
			}
		}

		int q;
		scanf("%d",&q);

		while(q--){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;

			if(a > b) swap(a,b);

			int r = ans[pii(a,b)];
			
			for(int i=0;i<conta;i++)
				if(comp[i][a] == comp[i][b]) r++;

			printf("%d\n",r);

		}

}