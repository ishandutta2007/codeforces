#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <ctype.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int inf=1e9+1;

int n,k,m;
struct edge{
	int u,v,w;
}arr[500000];
int u[500000],v[500000],pa[500001];
int ea[20][500001],ec[20][500001],depth[500001];

vector<int> adj[500001];

void make(int cur,int p,int d) {
	depth[cur] = d;
	ea[0][cur] = p;
	int a=1,pp=p;
	while(ea[a-1][pp]) {
		pp = ea[a][cur] = ea[a-1][pp];
		a++;
	}
	for(auto &it:adj[cur]) if(it!=p)
		make(it,cur,d+1);
}

int find(int cur) {
	return cur==pa[cur] ? cur : pa[cur] = find(pa[cur]);
}
void merge(int u,int v) {
	u=find(u),v=find(v);
	if(u!=v) pa[v] = u;
}

void lca(int u,int v,int w) {
	if(depth[u] > depth[v]) swap(u,v);
	int dif=depth[v]-depth[u];
	for(int i=0;1<<i<=dif;i++) if(dif>>i & 1) {
		ec[i][v] = min(ec[i][v], w);
		v=ea[i][v];
	}
	if(u==v) return;

	for(int i=19;i>=0;i--) if(ea[i][u]!=ea[i][v]) {
		ec[i][v] = min(ec[i][v],w); 
		ec[i][u] = min(ec[i][u],w);
		u=ea[i][u];
		v=ea[i][v];
	}
	ec[0][v] = min(ec[0][v],w);
	ec[0][u] = min(ec[0][u],w);
}
int main() {
	scanf("%d%d%d",&n,&k,&m);

	for(int i=1;i<=n;i++)
		pa[i] = i;
	for(int i=0;i<k;i++){
		scanf("%d%d",u+i,v+i);
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
		merge(u[i],v[i]);
	}

	for(int i=0;i<m;i++){
		scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].w);
		if(find(arr[i].u)!=find(arr[i].v)){
			merge(arr[i].u,arr[i].v);
			adj[arr[i].u].push_back(arr[i].v);
			adj[arr[i].v].push_back(arr[i].u);
			arr[i].w=0;
		}
	}

	for(int i=0;i<20;i++) for(int j=1;j<=n;j++)
		ec[i][j] = inf;

	for(int i=1;i<=n;i++) if(!depth[i])
		make(i,0,1);

	for(int i=0;i<m;i++) if(find(arr[i].u) == find(arr[i].v) && arr[i].w) {
		lca(arr[i].u,arr[i].v,arr[i].w);
	}

	for(int i=19;i>=1;i--) {
		for(int j=1;j<=n;j++) {
			ec[i-1][j] = min(ec[i-1][j], ec[i][j]);
			ec[i-1][ea[i-1][j]] = min(ec[i-1][ea[i-1][j]],ec[i][j]);
		}
	}

	for(int i=0;i<m;i++) if(!arr[i].w) {
		int u=arr[i].u,v=arr[i].v;
		if(depth[u] > depth[v]) swap(u,v);
		ec[0][v] = 0;
	}

	lli ans=0;
	for(int i=1;i<=n;i++) if(ea[0][i]){
		if(ec[0][i] == inf) {
			puts("-1");
			return 0;
		}
		ans += ec[0][i];
	}
	
	printf("%lld\n",ans);

	return 0;
}