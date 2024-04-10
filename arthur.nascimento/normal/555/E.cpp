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
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define maxn 200200
#define mod 1000000007

using namespace std;

int find(int *pai,int x){
	return pai[x] = (x == pai[x]) ? x : find(pai,pai[x]);
}

void merge(int *pai,int a,int b){
	a = find(pai,a);
	b = find(pai,b);
	if(a == b) return;
	pai[a] = b;
}

int uf[2][maxn];

vector<int> L[maxn];
int dp[20][maxn];
int prof[maxn];

int visit = 0;

int foi[maxn];

void dfs(int x,int p,int r){
	if(foi[x]) return;
	foi[x] = 1;
	visit++;
	if(x != r) prof[x] = 1 + prof[p];
	dp[0][x] = p;
	for(int i=1;i<20;i++)
		dp[i][x] = dp[i-1][dp[i-1][x]];
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(*it != p)
		dfs(*it,x,r);
}

int lca(int a,int b){
	if(prof[a] > prof[b]) swap(a,b);
	int dh = prof[b]-prof[a];
	for(int i=19;i>=0;i--) if(dh & (1<<i))
		b = dp[i][b];
	if(a == b) return a;
	for(int i=19;i>=0;i--)
		if(dp[i][a] != dp[i][b])
			a = dp[i][a], b = dp[i][b];
	return dp[0][a];
}
	
int mrk[maxn];

map<pii,int> foiE;

int sobe[maxn];
int desce[maxn];

int ok = 1;

void dfs2(int x,int p,int r){
	if(foi[x]) return;
	foi[x] = 1;
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(*it != p && !foi[*it]){
		dfs2(*it,x,r);
		sobe[x] += sobe[*it];
		desce[x] += desce[*it];
	}
	if(x == r) return;
	if(sobe[x] && desce[x]) ok  = 0;
}

main(){

		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);

		for(int i=0;i<n;i++)
			for(int j=0;j<2;j++)
				uf[j][i] = i;

		vector<pii> E;

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			E.pb(pii(a,b));
			if(find(uf[0],a) == find(uf[0],b)) continue;
			mrk[i] = 1;
			L[a].pb(b);
			L[b].pb(a);
			merge(uf[0],a,b);
		}

		for(int i=0;i<n;i++) if(!foi[i])
			dfs(i,i,i);

		assert(visit == n);
		debug("dfs ok\n");

		for(int i=0;i<m;i++) if(!mrk[i]){
			int a = E[i].first;
			int b = E[i].second;
			int l = lca(a,b);
			debug("olha %d-%d (%d)\n",a,b,l);
			while(prof[a] > prof[l]){
				merge(uf[1],a,dp[0][a]);
				debug("merge %d %d\n",a,dp[0][a]);
				a = find(uf[1],a);
			}
			while(prof[b] > prof[l]){
				merge(uf[1],b,dp[0][b]);
				debug("merge %d %d\n",b,dp[0][b]);
				b = find(uf[1],b);
			}
		}


		debug("oi\n");
		
		for(int i=0;i<n;i++)
			L[i].clear();

		for(int i=0;i<m;i++){
			int a = E[i].first;
			int b = E[i].second;
			a = find(uf[1],a);
			b = find(uf[1],b);
			debug("-> %d %d\n",a,b);
			if(foiE[pii(a,b)] || a == b) continue;
			foiE[pii(a,b)] = foiE[pii(b,a)] = 1;
			L[a].pb(b);
			L[b].pb(a);
		}

		memset(foi,0,sizeof(foi));
		for(int i=0;i<n;i++) if(!foi[i])
			dfs(i,i,i);
		debug("dfs nova ok\n");

		for(int i=0;i<q;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			if(find(uf[0],a) != find(uf[0],b)) ok = 0;
			a = find(uf[1],a);
			b = find(uf[1],b);
			int l = lca(a,b);
			sobe[a]++;
			desce[b]++;
			sobe[l]--;
			desce[l]--;
		}

		memset(foi,0,sizeof(foi));
		for(int i=0;i<n;i++) if(!foi[i])
			dfs2(i,i,i);

		if(ok)
			printf("Yes\n");
		else
			printf("No\n");

}