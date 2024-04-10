#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
using namespace std;

#define pb push_back
typedef long double cdb;
const int maxn = 5005;
vector<int> edg[maxn],oedg[maxn];

int dis[maxn],n,m,vis[maxn],ovis[maxn],u[maxn],v[maxn];
void dfs(vector<int> e[],int u,int vis[]) {
	vis[u]=true;
	for (int j=0;j<e[u].size();j++)
		if (!vis[e[u][j]]) dfs(e,e[u][j],vis);
}
int upd(int &x,int y) {
	return x>y?(x=y,1):0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("flights.in","r",stdin);
		freopen("flights.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d %d",&u[i],&v[i]),
		edg[u[i]].pb(v[i]),oedg[v[i]].pb(u[i]);
	dfs(edg,1,vis);dfs(oedg,n,ovis);
	for (int i=1;i<=n;i++) vis[i]&=ovis[i];
	
	bool used=true;
	for (int r=1;r<=n&&used;r++) {
		used=false;
		for (int u=1;u<=n;u++)
		for (int j=0;j<edg[u].size();j++)
		{
			int v=edg[u][j];
			if (!vis[u]||!vis[v]) continue;
			if (upd(dis[u],dis[v]-1)) used=true;
			if (upd(dis[v],dis[u]+2)) used=true;
		}
	}
	if (used) puts("No");
	else {
		puts("Yes");
		for (int i=1;i<=m;i++)
		if (vis[v[i]]&&vis[u[i]])
			printf("%d\n",dis[v[i]]-dis[u[i]]);
		else puts("1");
	}
	return 0;
}