#include<bits/stdc++.h>
#define N 200100
using namespace std;
vector<int> g[N];
int d[N],sz[N];
void DFS(int u,int p){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v!=p){
			d[v]=d[u]+1;
			DFS(v,u);
			sz[u]+=sz[v]+1;
		}
	}
	d[u]-=sz[u];
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,0);
	long long ans=0;
	sort(d+1,d+n+1,greater<int>());
	for(int i=1;i<=k;i++){
		ans+=d[i];
	}
	printf("%lld\n",ans);
	return 0;
}