#include <bits/stdc++.h>
using namespace std;

int n,k,dist[200001],sz[200001];
vector<int> adj[200001];

int dfs(int cur,int p,int d) {
	sz[cur]=1;
	dist[cur] = d;
	for(auto &v:adj[cur]) if(v!=p) sz[cur]+=dfs(v,cur,d+1);
	dist[cur]-=sz[cur]-1;
	return sz[cur];
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0,0);

	sort(dist+1,dist+1+n,std::greater<int>());
	
	long long ans=0;
	for(int i=1;i<=k;i++) ans+=dist[i];
	printf("%lld\n",ans);
	
	return 0;
}