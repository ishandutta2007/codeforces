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

using namespace std;

vector<int> L[maxn];
char foi[maxn];
int h[maxn];

int prof = 0;
int lista[maxn];

int tgt;
int ini;

vector<int> ans[3];

int pai[maxn];

pii dfs(int x,int p){

	pai[x] = p;
	h[x] = prof;
	lista[prof++] = x;
	foi[x] = 1;

	vector<pii> u;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++){

		if(*it == p) continue;

	 	if(foi[*it] && h[*it] < h[x]){
	 		u.pb(pii(h[*it],x));
			continue;
		}
		if(foi[*it]) continue;

		pii a = dfs(*it,x);
		if(ans[0].size()) {u.clear(); return pii(0,0);}
		if(a.first < h[x]) u.pb(a);

	}

	sort(u.begin(), u.end());

	if(u.size() >= 2){

		ini = x;
		tgt = lista[u[1].first];

		assert(u[1].first < prof-1);

		int p = ini;
		ans[0].pb(p);
		while(p != tgt && p){
			p = pai[p];
			ans[0].pb(p);
		}
		
		ans[1].pb(tgt);
		int y = tgt;
		while(y != lista[u[0].first] && y){
			y = pai[y];
			ans[1].pb(y);
		}
		p = u[0].second;
		ans[1].pb(p);
		while(p != x && p){
			p = pai[p];
			ans[1].pb(p);
		}
		ans[2].pb(tgt);
		y = tgt;
		while(y != lista[u[1].first] && y){
			y = pai[y];
			ans[2].pb(y);
		}
		p = u[1].second;
		ans[2].pb(p);
		while(p != x && p){
			p = pai[p];
			ans[2].pb(p);
		}
		reverse(ans[1].begin(), ans[1].end());
		reverse(ans[2].begin(), ans[2].end());
		u.clear();
		return pii(0,0);

	}

	prof--;
	if(u.size() == 0) return pii(999999,0);
	
	pii ret = u[0];
	u.clear();
	return ret;

}
		
main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			L[a].pb(b);
			L[b].pb(a);
		}

		for(int i=0;i<n;i++) if(!foi[i] && ans[0].size() == 0){
			prof = 0;
			dfs(i,i);
		}

		if(ans[0].size() == 0) {
			printf("NO\n");
			return 0;
		}
		
		printf("YES\n");

		for(int i=0;i<3;i++){
			printf("%d",ans[i].size());
			for(int j=0;j<ans[i].size();j++)	
				printf(" %d",ans[i][j]+1);
			printf("\n");
		}

}