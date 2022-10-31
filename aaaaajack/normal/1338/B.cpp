#include<bits/stdc++.h>
using namespace std;
#define N 100100
vector<int> g[N];
int deg[N],tol[N];
int dis[N];
void DFS(int u,int p){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v!=p){
			dis[v]=dis[u]+1;
			DFS(v,u);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++,deg[y]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]==1){
			DFS(i,0);
			break;
		}
	}
	int mn=1,mx=n-1;
	for(int i=1;i<=n;i++){
		if(deg[i]==1){
			mx--;
			tol[g[i][0]]++;
			if(dis[i]&1) mn=3;
		}
	}
	for(int i=1;i<=n;i++){
		if(tol[i]) mx++;
	}
	printf("%d %d\n",mn,mx);
	return 0;
}