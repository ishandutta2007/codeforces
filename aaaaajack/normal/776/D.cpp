#include<bits/stdc++.h>
#define N 100100
using namespace std;
int xr[N];
int ce[N],cv[N];
bool vis[N];
vector<int> g[N];
bool DFS(int u,int c){
	if(vis[u]) return cv[u]==c;
	vis[u]=true;
	cv[u]=c;
	for(int i=0;i<g[u].size();i++){
		int e=g[u][i];
		if(!DFS(u^xr[e],c^ce[e]^1)) return false;
	}
	return true;
}
int main(){
	int n,m,k,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&ce[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&x);
			g[i].push_back(x);
			xr[x]^=i;
		}
	}
	bool flag=true;
	for(int i=1;i<=m;i++){
		if(!vis[i]&&!DFS(i,0)) flag=false;
		//printf("%d\n",cv[i]);
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}