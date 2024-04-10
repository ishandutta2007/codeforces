#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>

using namespace std;
typedef pair<int,int> mp;
#define pb push_back
#define fi first
#define se second

const int maxn = 100005;
const int S = 400;

int par[maxn],n,m,tim[maxn],idx,q;
map<mp,int> s;
vector<mp> adj[maxn];
vector<int> nd[maxn];
int u[maxn],v[maxn],ans[maxn];
int findp(int u) {
	return par[u]?par[u]=findp(par[u]):u;
}
void merge(int u,int v) {
	u=findp(u);v=findp(v);
	if (u!=v) par[v]=u;
}

void insert(int u)
{
	if (tim[u]==idx) return ;
	int t=findp(u),sz=nd[t].size();
	for (int i=0;i<sz;i++)
		s[mp(nd[t][i],u)]++;
	tim[u]=idx;nd[t].pb(u);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("graph.in","r",stdin);
		freopen("graph.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int u,v,c,i=1;i<=m;i++)
		scanf("%d %d %d",&u,&v,&c),
		adj[c].pb(mp(u,v));
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
		scanf("%d %d",&u[i],&v[i]);
		
	for (int c=1;c<=m;c++)
	{
		int siz=adj[c].size();
		if (siz>S) {
			memset(par,0,sizeof(int)*(n+1));
			for (int i=0;i<siz;i++)
				merge(adj[c][i].fi,adj[c][i].se);
			for (int i=1;i<=q;i++)
				ans[i]+=(findp(u[i])==findp(v[i]));
		}
		else {
			for (int i=0;i<siz;i++)
				merge(adj[c][i].fi,adj[c][i].se);
			++idx;
			for (int i=0;i<siz;i++)
				insert(adj[c][i].fi),insert(adj[c][i].se);
			for (int i=0;i<siz;i++)
				nd[adj[c][i].fi].clear(),
				nd[adj[c][i].se].clear(),
				par[adj[c][i].fi]=par[adj[c][i].se]=0;
		}
	}
	
	for (int i=1;i<=q;i++)
		printf("%d\n",ans[i]+s[mp(u[i],v[i])]+s[mp(v[i],u[i])]);
	return 0;
}