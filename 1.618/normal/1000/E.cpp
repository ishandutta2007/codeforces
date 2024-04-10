#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 300005
using namespace std;
typedef long long ll;
int n,m;
int ind,dfn[maxn],stk[maxn],sk,low[maxn];
int cnt,pt[maxn];//
vector <int> adj[maxn];
void tarjan(int u,int f){
  dfn[u] = low[u] = ++ind;
	stk[++sk] = u;
  for(int i=0;i<adj[u].size();i++){
  	int v = adj[u][i];
  	if(dfn[v] == 0){
  		tarjan(v,u);
  		low[u] = min(low[u],low[v]);
  	}else if(v != f){
  		low[u] = min(low[u],dfn[v]);
  	}
  }
  if(low[u] == dfn[u]){
		cnt++;
		int v;
		do{
			v = stk[sk--];
			pt[v] = cnt;
		}while(v != u);
	}
}
vector <int> adj2[maxn];
int dis[maxn];
void dfs(int u,int f,int d){
	dis[u] = d;
	for(int i=0;i<adj2[u].size();i++){
		int v = adj2[u][i];
		if(v != f) dfs(v,u,d+1);
	}
}
int calc(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			int v = adj[i][j];
			if(pt[i] != pt[v]){
				adj2[pt[i]].push_back(pt[v]);
			}
		}
	}
	dfs(1,-1,0);
	int maxdis = 0,maxpos;
	for(int i=1;i<=cnt;i++){
		if(dis[i] > maxdis){
			maxdis = dis[i];
			maxpos = i;
		}
	}
	dfs(maxpos,-1,0);
	maxdis = 0;
	for(int i=1;i<=cnt;i++){
		if(dis[i] > maxdis){
			maxdis = dis[i];
		}
	}
	return maxdis;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	tarjan(1,-1);
	printf("%d\n",calc());
	return 0;
}