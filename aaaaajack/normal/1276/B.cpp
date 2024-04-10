#include<bits/stdc++.h>
#define N 200100
using namespace std;
int od[N],val[N],sz[N],cnt,cyc[N];
bool vis[N];
vector<int> g[N];
int DFS(int u,int b){
	int bb=0;
	vis[u]=true;
	val[u]=od[u]=cnt++;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]) val[u]=min(val[u],od[v]);
		else{
			if(DFS(v,b)) bb=sz[v];
			sz[u]+=sz[v];
			val[u]=min(val[u],val[v]);
			if(val[v]>=od[u]) cyc[u]+=sz[v];
		}
	}
	if(u==b) return sz[u];
	else return bb;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,a,b;
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for(int i=1;i<=n;i++){
			vis[i]=false;
			cyc[i]=0;
			g[i].clear();
			sz[i]=1;
		}
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cnt=0;
		int bb=DFS(a,b);
		printf("%I64d\n",1LL*cyc[b]*(n-bb-1));
	}
	return 0;
}