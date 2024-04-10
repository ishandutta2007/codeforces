#include<bits/stdc++.h>
#define N 100100
using namespace std;
vector<int> g[N];
int sz[N],dep[N];
void build(int u,int d){
	sz[u]=1;
	dep[u]=d;
	for(int i=0;i<g[u].size();i++){
		build(g[u][i],d+1);
		sz[u]+=sz[g[u][i]];
	}
}
int main(){
	int n,p;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&p);
		g[p].push_back(i);
	}
	build(1,0);
	for(int i=1;i<=n;i++) printf("%.1f ",0.5*(n-sz[i]+dep[i])+1);
	return 0;
}